#include <iostream>
#include"blockbuffer.h"
#include"optioninstance.h"
#include"settings.h"
using namespace std;


int main(int argc, char *argv[])
{
    cout << "Hello OptionSql Database!" << endl;
    //构建数据库实例
    cout << "Database instance is created!" << endl;
    optionsql::OptionInstance* dbInstance=new optionsql::OptionInstance("option.ini","ASCII");
    //读取数据库配置文件进入内存
    optionsql::Settings settings;
    settings.readSettings("ASCII");


    //析构数据库实例
    cout << "Database instance is deleted!" << endl;
    delete dbInstance;

    cout<<"Goodbye Database"<< endl;
    return 0;
}
