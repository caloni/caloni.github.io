class File2
{
public:
	// the user MUST open the file before the object construction
	DWORD Open(const char* fileName)
	{
		m_file = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, 
			NULL, OPEN_EXISTING, 0, NULL);
	}

	// ... and MUST close it before its destruction
	void Close()
	{
		CloseHandle(m_file);
		m_file = NULL;
	}

	HANDLE m_file; // aquired resource
};

int UseFile2()
{
	File2 config; // local object

	config.Open("config.txt"); // aquired resource

	// using config...
	BlowUpFunction(); // exception thrown: the resource was NOT released
	// using config...

	config.Close(); // resource released

	return 0;
}