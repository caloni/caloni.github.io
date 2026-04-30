//...
// Start process and get handle with powers.
hProc = CreateAndGetProcessGodHandle(tzProgPath, tzProgArgs);

if( hProc != NULL )
{
	// Load DLL in the create process context.
	HMODULE hDll = RemoteLoadLibrary(hProc, tzDllPath);

	if( hDll != NULL )
		RemoteFreeLibrary(hProc, hDll);

	CloseHandle(hProc);
}
//...