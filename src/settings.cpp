#include "settings.h"

namespace optionsql
{
    Settings::Settings()
    {

    }

    int Settings::readSettings(const std::string &address, const std::string &encoding)
    {
        //新建文件系统
        FileSystem fs;
        //新建文件对象
        File optionIni(address.c_str());
        //读取缓冲区
        char buffer[256]={0};
        if(fs.open(optionIni,OPTIONSQL_OPEN_READONLY)==OPTIONSQL_GOOD)
        {
            std::cout<<"setting file opened"<<std::endl;
        }
        else
        {
            std::cout<<"failed to open setting file"<<std::endl;
        }
        if(optionIni.read(buffer,250,0)==0)
        {
            std::cout<<buffer<<std::endl;
        }


        fs.close(optionIni);
    }

    int Settings::readSettings(const std::string &encoding)
    {
        readSettings("option.ini",encoding);
    }
}


