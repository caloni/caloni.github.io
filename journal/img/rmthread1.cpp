/** Run process and get rights for running remote threads. */
HANDLE CreateAndGetProcessGodHandle(LPCTSTR lpApplicationName, LPTSTR lpCommandLine);

/** Load DLL in another process. */
HMODULE RemoteLoadLibrary(HANDLE hProcess, LPCTSTR lpFileName);

/** Free DLL in another process. */
BOOL RemoteFreeLibrary(HANDLE hProcess, HMODULE hModule);