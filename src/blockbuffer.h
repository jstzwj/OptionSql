#ifndef BLOCKBUFFER_H
#define BLOCKBUFFER_H
#include<cstdint>
#include"optionvalue.h"
namespace optionsql
{
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
