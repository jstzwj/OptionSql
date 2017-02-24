#include "filesystem.h"

namespace optionsql
{
#ifdef OPTIONSQL_OS_WINDOWS
    int WindowsFileSystem::open(File & file, int flags)
    {
        file.open(flags);
        return 0;
    }

    int WindowsFileSystem::close(File & file)
    {
        file.close();
        return 0;
    }

    int WindowsFileSystem::del(int syncDir)
    {

    }

    int WindowsFileSystem::access(int flags, int *pResOut)
    {

    }

    int WindowsFileSystem::fullPathname(int nOut, char *zOut)
    {

    }
#endif

}
