#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include"errcode.h"
#include<string>
namespace optionsql
{
    class QueryResult
    {
    public:
        QueryResult();
        ErrCode code;
        std::string msg;
    };
}
#endif // QUERYRESULT_H
