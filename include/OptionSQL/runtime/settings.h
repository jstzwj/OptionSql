#ifndef SETTINGS_H
#define SETTINGS_H
#include<string>
#include<memory>
#include<iostream>
#include"filesystem.h"
namespace optionsql
{
    class Settings
    {
    public:
        Settings();
        int readSettings(const std::string &address,const std::string &encoding);
        int readSettings(const std::string &encoding);
    private:
        int port;
        std::string basedir;
        std::string datadir;
        std::string bind_address;
        std::string log_error;
        int sqlMode;
    };
}


#endif // SETTINGS_H
