#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include<string>
#include"file.h"
namespace optionsql
{
    class FileSystem
    {
    public:
        FileSystem();
        int maxPathname;          /* Maximum file pathname length */
        std::string vfsName;
        void *pAppData;          /* Pointer to application-specific data */
        int open(const std::string &zName, File *,int flags, int *pOutFlags);
        int del(const std::string &zName, int syncDir);
        int access(const std::string &zName, int flags, int *pResOut);
        int fullPathname(const std::string &zName, int nOut, char *zOut);
        void *DlOpen(const std::string &zFilename);
        void DlError(int nByte, char *zErrMsg);
        //void DlSym(void*, const char *zSymbol)(void);
        void DlClose(void*);
        int Randomness(int nByte, char *zOut);
        int Sleep(int microseconds);
        int CurrentTime(double*);
        int GetLastError(int, char *);
        int CurrentTimeInt64(int64_t*);
        //int SetSystemCall(const char *zName, sqlite3_syscall_ptr);
        //sqlite3_syscall_ptr xGetSystemCall(const char *zName);
        const char *NextSystemCall(const char *zName);
    };
}


#endif // FILESYSTEM_H
