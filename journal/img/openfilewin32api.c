#include <windows.h>

int main()
{
	HANDLE hFile = CreateFile("c:\\tests\\myfile.txt", GENERIC_READ, 
		FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if( hFile )
	{
		DWORD read = 0;
		CHAR buffer[100];

		if( ReadFile(hFile, buffer, sizeof(buffer), &read, NULL) )
		{
			WriteBuffer(buffer);
		}

		CloseHandle(hFile);
	}
}

