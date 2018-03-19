#ifndef BLOCKBUFFER_H
#define BLOCKBUFFER_H
#include<cstdint>
#include"optionvalue.h"
namespace optionsql
{
    #pragma pack(1)
    //--6字节
    struct Scn
    {
        uint32_t scn_base;
        uint16_t scn_wrap;//前两个字节0000 SCN Wrap,后4个字节SCN BASE ,bbed-offset:0x8
    };

    //事务槽--24字节
    struct Itl
    {
        uint64_t xid;   //Transaction ID (UndoSeg.Slot.Wrap)
        uint64_t uba ;  //Undo address
        uint16_t lock_flag;//	Lck 锁定的row数 这里还用到了下一个 byte 的数据
        //2 对应的二进制表示为 0010 正好和dump文件中的 --U- 吻合
        //flag 1 nibble
        //C = Committed; U = Commit Upper Bound; T = Active at CSC; B = Rollback
        Scn scn_fsc;//	If the transaction has been cleaned out, this is the commit SCN or an upper bound thereof.
        //Otherwise the leading two bytes contain the free space credit for the transaction
        //- that is, the number of bytes freed in the block by the transaction
        //Scn = SCN of commited TX; Fsc = Free space credit (bytes)
    };

    struct Block
    {
        //第一个20字节
        uint8_t type_kcbh;   //block类型
        uint8_t frmt_kcbh;   //block格式
        uint8_t spare1_kcbh;   //已不再使用
        uint8_t spare2_kcbh;   //已不再使用
        uint32_t rdba_kcbh;  //相关数据库块地址,转换成2进制后它的前10bit 表示file id 后22bit 表示的block id
        Scn scn_kcbh;    //数据块scn
        uint8_t seq_kcbh;//同一个SCN影响这个block中的行数大于 254 行就会为这个事务分配一个新的SCN
        //如下面的操作就可能引起同一个SCN但影响的同一个block 中的行超过254行 :"delete from table_name"
        //影响的行数(最大254) 是用从 0x01 到 0xfe 表示的
        //当这个byte 的数据为 0xff 的时候标志这个 block 坏调了---> ora-01578
        uint8_t flg_kcbh;//1 = virgin block
        //2 = last change to the block was for a cleanout operation
        //4 = checksum value is set
        //8 = temporary data
        //6 的时候是 2,4 的组合 bbed-offset:0x15)
        uint16_t chkval_kcbh;//快检查值，db_block_checksum=TRUE,数据块读入buffer和写回数据文件之前都要做检查计算，如果计算值与数据块中记录的计算值不匹配就会标记该块是坏块.
        uint16_t spare3_kcbh;   //未知


        //第二个24字节
        uint8_t typ;    //类型
        uint8_t expand_1;   //拓展位
        uint8_t expand_2;
        uint8_t expand_3;
        uint32_t seg_obj;
        Scn csc;    //The SCN at which the last full cleanout was performed on the block
        uint16_t expand_4;
        uint8_t itc;    //ITL 条目的个数 max 255超过会报ORA-02207
        uint8_t expand_5;
        uint8_t flg;    //	indicates that the block is on a freelist. Otherwise the flag is 9i ASSM
        uint8_t fsl;    //Index to the first slot on the ITL freelist. ITL TX freelist slot
        uint32_t fnx;   //自由列表中下一块的地址

        //两条itl
        Itl itl1;
        Itl itl2;

        //14字节
        uint8_t flag;
        uint8_t ntab ;//这block中有几个table的数据 cluster这个就可能大于1
        uint16_t block_nrow;//block 有多少行数据
        uint16_t frre;//First free row index entry. -1=you have to add one.
        uint16_t fsbo;//出去row dict 后面的可以放数据的空间的起始位置
        //也可以看成是从这个区域的开始"flag"到最后一个 "row offs"占用的空间
        uint16_t fseo;//Free Space End offset ( 9.2.0 )参与db_block_checking的计算剩余空间
        //select 的时候oracle不是简单的根据offset定位row.这个值也是参与了定位row的
        uint16_t avsp;//Available space in the block (pctfree and pctused) ORA-01578
        uint16_t tosp;//Total available space when all TXs commit ( 9.2.0 )参与db_block_checking


        //用户数据
        uint16_t offs;//偏移量 用 cluster 的时候可以看出值
        uint16_t table_nrow;//这个table有多少行数据
        uint16_t row_offs;//这行数据相对的起始位置 after delete & commit is 0xffff

        uint8_t fb;/*K = Cluster Key (Flags may change meaning if this is set to show HASH cluster)
        C = Cluster table member
        H = Head piece of row
        D = Deleted row
        F = First data piece
        L = Last data piece
        P = First column continues from previous piece
        N = Last column continues in next piece*/
        uint8_t lb;//和上面的 ITL 的lck相对应 表示这行是否被 lock 了
        uint8_t cc;//有几列数据 这里只能表示255列 超过了就会有链接行
        uint8_t length;//这列的数据的长度是多少




        //block tail
        uint8_t seq_clone;
        uint8_t type_clone;
        uint16_t scn_clone;
        /*改这 block 最后的4 bytes 数据中的任意肯定ora-1578
        第 1 byte : 对应开始的 seq
        第 2 byte : 对应开始的 type
        第3,4byte : 对应开始的scn的末2为 control file 这里是control seq*/

    };

    class BlockBuffer
    {
    public:
        BlockBuffer();
    private:
        byte * blockData;
        int64_t lockTime;
        int32_t fileNum;



    };
}

#endif // BLOCKBUFFER_H
