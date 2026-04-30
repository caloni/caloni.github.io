BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch( ul_reason_for_call )
	{
		case DLL_PROCESS_ATTACH:
		{
			DWORD dwThrId;

			// Fill global variable with handle copy of this thread.

			BOOL bRes =
			DuplicateHandle(GetCurrentProcess(),
				GetCurrentThread(),
				GetCurrentProcess(),
				g_hThrDllMain,
				0,
				FALSE,
				0);

			if( bRes == FALSE )
				break;

			// Call function that do the useful stuff with its DLL handle.
			CloseHandle(CreateThread(NULL,
				0,
				RmThread,
				(LPVOID) LoadLibrary(g_tzModuleName),
				0,
				dwThrId));
				}
			break;
			//...