/**
* Sample function, called remotely for RmThread.exe.
*/
DWORD WINAPI RmThread(LPVOID lpParameter)
{
	HMODULE hDll = (HMODULE) lpParameter;
	LPCTSTR ptzMsg = _T("Congratulations! You called RmThread.dll successfully!");

	// Wait DllMain termination.
	WaitForSingleObject(g_hThrDllMain, INFINITE);

	//TODO: Put your remote code here.
	MessageBox(NULL,
		ptzMsg,
		g_tzModuleName,
		MB_OK : MB_ICONINFORMATION);

	// Do what the function name says.
	FreeLibraryAndExitThread(hDll, 0);
}