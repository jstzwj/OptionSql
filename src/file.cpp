#include "file.h"

namespace optionsql
{
    FileBase::FileBase(const std::string &path)
        :IoMethod(),filePath(path)
    {

    }

#ifdef OPTIONSQL_OS_WINDOWS
    WindowsFile::WindowsFile(const std::string &path)
        :FileBase(path)
    {

    }

    int WindowsFile::open(int flags)
    {
        MessageBoxA(NULL, "打开文件失败", "Error", MB_OK);
        DWORD dwDesiredAccess=0;
        DWORD dwCreationDisposition=OPEN_EXISTING;
        DWORD dwFlagsAndAttributes=FILE_ATTRIBUTE_NORMAL;
        if((flags&OPTIONSQL_OPEN_CREATE)!=0)
        {
            dwCreationDisposition=CREATE_NEW;
        }
        if((flags&OPTIONSQL_OPEN_READONLY)!=0)
        {
            dwDesiredAccess|=GENERIC_READ;
        }
        if((flags&OPTIONSQL_OPEN_READWRITE)!=0)
        {
            dwDesiredAccess|=GENERIC_WRITE;
        }
        if((flags&OPTIONSQL_OPEN_DELETEONCLOSE)!=0)
        {
            dwFlagsAndAttributes|=FILE_FLAG_DELETE_ON_CLOSE;
        }
        pfile = CreateFileA(filePath.c_str(), dwDesiredAccess, 0, NULL, dwCreationDisposition,
                dwFlagsAndAttributes, NULL);
        if(pfile!=INVALID_HANDLE_VALUE)
        {
            CloseHandle(pfile);
            return OPTIONSQL_FILE_ERROR_OPEN;
        }
        else
        {
            return OPTIONSQL_GOOD;
        }
    }

    int WindowsFile::close()
    {
        CloseHandle(pfile);
        return OPTIONSQL_GOOD;
    }

    int WindowsFile::read(char * buffer, int readLen, int64_t offset)
    {
        DWORD bytesRead;
        if(!SetFilePointerEx(pfile,*(LARGE_INTEGER *)(&offset),NULL,FILE_BEGIN))
        {
            return OPTIONSQL_FILE_ERROR_SEEK;
        }
        if(!ReadFile(pfile, buffer, readLen, &bytesRead, NULL))
        {
            return OPTIONSQL_IO_ERROR_READ;
        }
        return OPTIONSQL_GOOD;
    }

    int WindowsFile::write(const char *buffer, int writeLen, int64_t offset)
    {
        DWORD bytesWritten;
        if(!SetFilePointerEx(pfile,*(LARGE_INTEGER *)(&offset),NULL,FILE_BEGIN))
        {
            return OPTIONSQL_FILE_ERROR_SEEK;
        }
        if(!WriteFile(pfile,buffer,writeLen,&bytesWritten,NULL))
        {
            return OPTIONSQL_IO_ERROR_WRITE;
        }
        return OPTIONSQL_GOOD;
    }

    int WindowsFile::truncate(int64_t size)
    {
        if(!SetFilePointerEx(pfile,*(LARGE_INTEGER *)(&size),NULL,FILE_BEGIN))
        {
            return OPTIONSQL_FILE_ERROR_SEEK;
        }
        if(SetEndOfFile(pfile))
        {
            return OPTIONSQL_GOOD;
        }
        else
        {
            return OPTIONSQL_FILE_ERROR_TRUNCATE;
        }
    }

    int WindowsFile::sync(int flags)
    {
        if(FlushFileBuffers(pfile))
        {
            return OPTIONSQL_GOOD;
        }
        else
        {
            return OPTIONSQL_FILE_ERROR_SYNC;
        }
    }

    int WindowsFile::fileSize(int64_t *pSize)
    {
        if(GetFileSizeEx(pfile,(LARGE_INTEGER *)pSize))
        {
            return OPTIONSQL_GOOD;
        }
        else
        {
            return OPTIONSQL_FILE_ERROR_GETSIZE;
        }
    }

    int WindowsFile::lock(int)
    {
        LARGE_INTEGER file_size;
        fileSize(&file_size.QuadPart);
        if(LockFile(pfile,0,0,file_size.LowPart,file_size.HighPart))
        {
            return OPTIONSQL_GOOD;
        }
        else
        {
            return OPTIONSQL_FILE_ERROR_LOCK;
        }
    }

    int WindowsFile::unlock(int)
    {
        LARGE_INTEGER file_size;
        fileSize(&file_size.QuadPart);
        if(UnlockFile(pfile,0,0,file_size.LowPart,file_size.HighPart))
        {
            return OPTIONSQL_GOOD;
        }
        else
        {
            return OPTIONSQL_FILE_ERROR_UNLOCK;
        }
    }

    int WindowsFile::checkReservedLock(int *pResOut)
    {

    }

    int WindowsFile::fileControl(int op, void *pArg)
    {

    }

    int WindowsFile::sectorSize()
    {

    }

    int WindowsFile::deviceCharacteristics()
    {

    }
#endif

}
