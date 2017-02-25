#include <iostream>
#include"blockbuffer.h"
#include"optioninstance.h"
#include"settings.h"
#include"logerror.h"
using namespace std;


int main(int argc, char *argv[])
{
    //开启错误日志
    optionsql::LogError::openLogErrorFile("optionsql_error.log");
    //构建数据库实例
    optionsql::LogError::log(3,"Database started");
    optionsql::OptionInstance* dbInstance=new optionsql::OptionInstance("option.ini","ASCII");
    //读取数据库配置文件进入内存
    optionsql::Settings settings;
    settings.readSettings("ASCII");


    //析构数据库实例
    optionsql::LogError::log(3,"Database instance is deleted!");
    delete dbInstance;

    optionsql::LogError::log(3,"Database ended");
    return 0;
}
