#include "stdafx.h"
#include "Regedit.h"

void OpenFile(WCHAR *pFilePath,BOOL nOpenFlag)
{
	long ret=::RegOpenKeyEx(HKEY_CURRENT_USER,pFilePath, 0, KEY_ALL_ACCESS, &g_hKey);
	if(ERROR_SUCCESS != ret)
	{
		DWORD dwPos = 0;
		long ret1=RegCreateKeyEx(HKEY_CURRENT_USER,pFilePath,0,0,REG_OPTION_NON_VOLATILE,0,NULL, &g_hKey,&dwPos);
		if(ERROR_SUCCESS != ret1)
		{
			g_hKey = NULL;
			RETAILMSG(true,(L"RegCreateKeyEx failed. \r\n"));
		}
		else
		{
			RETAILMSG(true,(L"OK .g_hKey = %x\r\n",g_hKey));
		}
	}
}

long ReadFile(WCHAR *pRegKey,BYTE *pReadBuf,DWORD nReadLen,DWORD dwType)
{
	long ret = 0;
	if(NULL == g_hKey)
	{
		ret = -1;
		RETAILMSG(true,(L" failed NULL == g_hKey.\r\n"));
		return ret;
	}
	ret=RegQueryValueEx(g_hKey,pRegKey,NULL,&dwType,pReadBuf,&nReadLen);
	if(ERROR_SUCCESS != ret)
	{
		ret = -1;
		RETAILMSG(true,(L"RegQueryValueEx failed.\r\n"));
	}
	return ret;
}

long WriteFile(WCHAR *pRegKey,BYTE *pWriteBuf,DWORD nWriteLen,DWORD dwType)
{
	long ret = 0;
	if(NULL == g_hKey)
	{
		ret = -1;
		RETAILMSG(true,(L"g_hKey == NULL.\r\n"));
		return ret;
	}
	ret=::RegSetValueEx(g_hKey,pRegKey,0,dwType,(LPBYTE) pWriteBuf,nWriteLen);
	if(ERROR_SUCCESS != ret)
	{
		ret = -1;
		RETAILMSG(true,(L"RegSetValueEx failed.\r\n"));
	}
	return ret;
}

void CloseFile(BOOL nCloseFlag)
{
	if(g_hKey)
	{
		long ret=::RegCloseKey(g_hKey);
		g_hKey = NULL;
		RETAILMSG(true,(L"RegCloseKey OK.\r\n"));
	}
	else
	{
		RETAILMSG(true,(L"RegCloseKey failed\r\n"));
	}
}