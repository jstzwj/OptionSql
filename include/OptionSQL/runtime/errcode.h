#ifndef ERRCODE_H
#define ERRCODE_H

namespace optionsql
{

    enum ErrorCode
    {
        OPTIONSQL_GOOD,
        OPTIONSQL_FILE_ERROR_OPEN,
        OPTIONSQL_FILE_ERROR_GETSIZE,
        OPTIONSQL_FILE_ERROR_SEEK,
        OPTIONSQL_IO_ERROR_READ,
        OPTIONSQL_IO_ERROR_WRITE,
        OPTIONSQL_FILE_ERROR_TRUNCATE,
        OPTIONSQL_FILE_ERROR_SYNC,
        OPTIONSQL_FILE_ERROR_LOCK,
        OPTIONSQL_FILE_ERROR_UNLOCK
    };

    class ErrCode
    {
    public:
        ErrCode();
    };
}


#endif // ERRCODE_H
