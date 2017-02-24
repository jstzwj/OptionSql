#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include<string>
#include<cstdint>
#include"file.h"



namespace optionsql
{
    class FileSystemBase
    {
    public:
        FileSystemBase():maxPathname(255){}
        virtual ~FileSystemBase(){}
        int maxPathname;          /* Maximum file pathname length */
        void *pAppData;          /* Pointer to application-specific data */
        virtual int open(File& file,int flags)=0;
        virtual int close(File& file)=0;
        virtual int del(int syncDir)=0;
        virtual int access(int flags, int *pResOut)=0;
        virtual int fullPathname(int nOut, char *zOut)=0;
        //void *DlOpen(const std::string &zFilename);
        //void DlError(int nByte, char *zErrMsg);
        //void DlSym(void*, const char *zSymbol)(void);
        //void DlClose(void*);
        //int Randomness(int nByte, char *zOut);
        //int Sleep(int microseconds);
        //int CurrentTime(double*);
        //int GetLastError(int, char *);
        //int CurrentTimeInt64(int64_t*);
        //int SetSystemCall(const char *zName, sqlite3_syscall_ptr);
        //sqlite3_syscall_ptr xGetSystemCall(const char *zName);
        //const char *NextSystemCall(const char *zName);
    };
    //==========
    //系统依赖代码
    //==========
#ifdef OPTIONSQL_OS_WINDOWS
    class WindowsFileSystem:public FileSystemBase
    {
    public:
        WindowsFileSystem():FileSystemBase(){}
        virtual ~WindowsFileSystem(){}
        virtual int open(File& file, int flags);
        virtual int close(File& file);
        virtual int del(int syncDir);
        virtual int access(int flags, int *pResOut);
        virtual int fullPathname(int nOut, char *zOut);
    };
    using FileSystem=WindowsFileSystem;
#endif

}


#endif // FILESYSTEM_H
