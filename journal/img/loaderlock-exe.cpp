//
// Victim.exe
//
#include <windows.h>
#include <tchar.h>

int main()
{
	HMODULE lockDll = LoadLibrary(_T("LoaderLock.dll"));

	if( lockDll )
	{
		Sleep(5000);
		FreeLibrary(lockDll), lockDll  = NULL;
	}
}