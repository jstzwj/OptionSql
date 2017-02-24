#include "settings.h"

namespace optionsql
{
    Settings::Settings()
    {

    }

    int Settings::readSettings(const std::string &address, const std::string &encoding)
    {
        FileSystem fs;

        File optionIni(address.c_str());
        fs.open(optionIni,OPTIONSQL_OPEN_READONLY);


        fs.close(optionIni);
    }

    int Settings::readSettings(const std::string &encoding)
    {
        readSettings("option.ini",encoding);
    }
}


