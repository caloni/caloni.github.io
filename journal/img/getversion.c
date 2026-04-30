#include <windows.h>
#include <stdio.h>

int main()
{
	DWORD winVer = GetVersion();
	BOOL isPlatformNT = winVer >= 0x80000000 ? FALSE : TRUE;

	if( isPlatformNT )
		printf("Plataforma NT\n");
	else
		printf("Bem-vindo ao parque dos dinossauros!\n");

	return isPlatformNT ? 1 : 0;
}

