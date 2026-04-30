/** @file OnCrash

@brief Exemplo de como capturar exceções no seu programa.

@author Wanderley Caloni <wanderley@caloni.com.br>
@date 2010-08
*/
#include <windows.h>
#include <dbghelp.h>
#include <time.h>

#pragma comment(lib, "dbghelp.lib")


LONG WINAPI CrashHandler(_EXCEPTION_POINTERS* ExceptionInfo)
{
	LONG ret = EXCEPTION_CONTINUE_SEARCH;
	MINIDUMP_EXCEPTION_INFORMATION minidumpInfo;

	minidumpInfo.ClientPointers = FALSE;
	minidumpInfo.ThreadId = GetCurrentThreadId();
	minidumpInfo.ExceptionPointers = ExceptionInfo;

	HANDLE hFile = CreateFile("OnCrash.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

	if( hFile != INVALID_HANDLE_VALUE )
	{
		MINIDUMP_TYPE dumpType = MiniDumpNormal;

		if( MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), 
			hFile, MiniDumpNormal, &minidumpInfo, NULL, NULL) )
		{
			ret = EXCEPTION_EXECUTE_HANDLER;
		}

		CloseHandle(hFile);
	}

	return ret;
}


DWORD WINAPI CrashThread(PVOID)
{
	int* x = 0;
	*x = 13;
	return 0;
}


int main()
{
	SetUnhandledExceptionFilter(CrashHandler);
	HANDLE crashThread = CreateThread(NULL, 0, CrashThread, NULL, 0, NULL);
	WaitForSingleObject(crashThread, INFINITE);
}
