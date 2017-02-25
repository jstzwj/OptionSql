#ifndef LOGERROR_H
#define LOGERROR_H

#include<string>
#include<ctime>
#include<fstream>

namespace optionsql
{
    class LogError
    {
    public:
        LogError();
        static void openLogErrorFile(const std::string &filename);
        static void log(int logType,const std::string & data);//0:error,1:warning,2note
        static void closeLogErrorFile();
    private:
        static std::fstream stream;
    };
}


#endif // LOGERROR_H
