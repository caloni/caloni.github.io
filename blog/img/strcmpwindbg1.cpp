#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main()
{
	CHAR sysPath[MAX_PATH];
	CHAR findPath[MAX_PATH];

	GetSystemDirectory(sysPath, MAX_PATH);
	sprintf(findPath, "%s\\*.*", sysPath);

	WIN32_FIND_DATA findData;
	HANDLE findH = FindFirstFile(findPath, &findData);

	if( findH != INVALID_HANDLE_VALUE )
	{
		do
		{
			CHAR filePath[MAX_PATH];

			sprintf(filePath, "%s\\%s", sysPath, findData.cFileName);
			HANDLE fileH = CreateFile(filePath, GENERIC_READ, 
				FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

			if( fileH )
			{
				CHAR firstBytes[4];
				DWORD wasRead = 0;

				if( ReadFile(fileH, firstBytes, 4, &wasRead, NULL) && wasRead == 4 )
				{
					printf("%s: %02X %02X %02X %02X\n", findData.cFileName,
						(int) firstBytes[0], (int) firstBytes[1], 
						(int) firstBytes[2], (int) firstBytes[3]);
				}

				CloseHandle(fileH);
			}
		}
		while( FindNextFile(findH, &findData) );

		FindClose(findH);
	}
}
