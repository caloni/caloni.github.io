#include <windows.h>

class File
{
	public:
	File(const char* fileName)
	{
		m_file = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, 
		NULL, OPEN_EXISTING, 0, NULL); // if we open the file...
	}

	~File()
	{
		CloseHandle(m_file); // ... we need to close it!
		m_file = NULL;
	}

	HANDLE m_file; // aquired resource
};

int UseFile()
{
	File config("config.txt"); // local object: aquired resource
	// using config.txt
	return 0; // the aquired resource  (config.txt) is automagically released
}