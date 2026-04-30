#include <windows.h>
#include <shlwapi.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
	CHAR wndTxt[MAX_PATH];

	while( true )
	{
		HWND fgWin = GetForegroundWindow();
		wndTxt[0] = 0;

		if( GetWindowText(fgWin, wndTxt, sizeof(wndTxt)) )
		{
			if( StrStrI(wndTxt, "Fict Bank") )
			{
				MessageBox(fgWin, "Hello! Would you like to be under attack?",
					"Free Trojan", MB_OK | MB_ICONINFORMATION);
				break;
			}
		}
	}

	ExitProcess(ERROR_SUCCESS);
}