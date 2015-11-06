#include "Winreg.h"

HKEY g_hKey = NULL;

void   OpenFile(WCHAR *pFilePath,BOOL nFlag = 0);
long   ReadFile(WCHAR *pRegKey,BYTE *pReadBuf,DWORD nReadLen,DWORD dwType);
long   WriteFile(WCHAR *pRegKey,BYTE *pWriteBuf,DWORD nWriteLen,DWORD dwType);
void   CloseFile(BOOL nCloseFlag);