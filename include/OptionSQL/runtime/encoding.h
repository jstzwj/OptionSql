#ifndef ENCODING_H
#define ENCODING_H
#include<iconv.h>
#include<memory.h>
namespace optionsql
{
    class Encoding
    {
    private:
        iconv_t cd;
    public:
        Encoding(const char *from_charset,const char *to_charset)
        {
            cd = iconv_open(to_charset,from_charset);
        }

        ~Encoding()
        {
            iconv_close(cd);
        }


        // 转换输出
        int convert(char *inbuf,int inlen,char *outbuf,int outlen)
        {
            char **pin = &inbuf;
            char **pout = &outbuf;
            memset(outbuf,0,outlen);
            return iconv(cd,pin,(size_t *)&inlen,pout,(size_t *)&outlen);
        }
    };
}

#endif // ENCODING_H
