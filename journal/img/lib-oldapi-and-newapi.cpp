#include "LibMod.h"
#include <windows.h>
#include <Tlhelp32.h>
#include <stdio.h>

// Essa função é usada pelo nosso App
int UsingOldApis()
{
	DWORD ver = GetVersion(); // API paleozoica, OK.
	return int( (DWORD)(LOBYTE(LOWORD(ver))) );
}

// Essa função NÃO é usada pelo nosso App
void UsingNewApis()
{
	// Opa: função moderninha!!
	if( HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL) )
	{
		PROCESSENTRY32 procEntry;

		// Tudo bem, nosso App não vai usar essa função.
		if( Process32First(snapshot, &procEntry) )
		{
			printf("Process list:\n");

			do
			{
				printf("%s\n", procEntry.szExeFile);
			}
			while( Process32Next(snapshot, &procEntry) );
		}

		CloseHandle(snapshot);
	}
}
