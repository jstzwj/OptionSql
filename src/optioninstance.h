#ifndef OPTIONINSTANCE_H
#define OPTIONINSTANCE_H

#include<string>
#include"encoding.h"
#include"queryresult.h"
namespace optionsql
{
    class OptionInstance
    {
    public:
        OptionInstance();
        OptionInstance(const std::string & fileName,const std::string & encoding);
        QueryResult exec(const std::string & sql,const std::string & encoding);
    };
}

#endif // OPTIONINSTANCE_H
