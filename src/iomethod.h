#ifndef IOMETHOD_H
#define IOMETHOD_H
#include<cstdint>
namespace optionsql
{
    class IoMethod
    {
    public:
        IoMethod();
        int xClose();
        int xRead(void*, int iAmt, int64_t iOfst);
        int xWrite(const void*, int iAmt, int64_t iOfst);
        int xTruncate(int64_t size);
        int xSync(int flags);
        int xFileSize(int64_t *pSize);
        int xLock(int);
        int xUnlock(int);
        int xCheckReservedLock(int *pResOut);
        int xFileControl(int op, void *pArg);
        int xSectorSize();
        int xDeviceCharacteristics();
        /* Methods above are valid for version 1 */
        int xShmMap(int iPg, int pgsz, int, void volatile**);
        int xShmLock(int offset, int n, int flags);
        void xShmBarrier();
        int xShmUnmap(int deleteFlag);
        /* Methods above are valid for version 2 */
        int xFetch(int64_t iOfst, int iAmt, void **pp);
        int xUnfetch(int64_t iOfst, void *p);
        /* Methods above are valid for version 3 */
        /* Additional methods may be added in future releases */
    };
}


#endif // IOMETHOD_H
