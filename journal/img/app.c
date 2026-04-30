#include <windows.h>
#include <stdio.h>

int main()
{
	HMODULE dll1 = LoadLibrary(".\\DLL\\DLL.dll");
	HMODULE dll2 = LoadLibrary(".\\DLL.dll");

	printf("First DLL: %p\nSecond DLL: %p",
			dll1, dll2);

	return 0;
}

