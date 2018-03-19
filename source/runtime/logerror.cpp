#include "logerror.h"

namespace optionsql
{

    std::fstream LogError::stream;
    LogError::LogError()
    {

    }

    void LogError::openLogErrorFile(const std::string & filename)
    {
        stream.open(filename,std::ios::out|std::ios::app);
    }

    void LogError::log(int logType, const std::string &data)
    {
        time_t timep;
        struct tm *p;
        time(&timep);
        p = gmtime(&timep);
        stream<<(1900+(p->tm_year))<<"-"<<(1+(p->tm_mon))<<"-"<<(p->tm_mday)
             <<(p->tm_hour)<<":"<<(p->tm_min)<<":"<<(p->tm_sec)<<"\t";
        if(logType==1)
        {
            stream<<"[error]";
        }
        else if(logType==2)
        {
            stream<<"[warning]";
        }
        else if(logType==3)
        {
            stream<<"[note]";
        }
        stream<<"\t"<<data<<std::endl;
    }

    void LogError::closeLogErrorFile()
    {
        stream.close();
    }
}

