INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, 
							WPARAM wParam, LPARAM lParam)
{
	INT_PTR ret = TRUE;

	switch( uMsg )
	{
	case WM_INITDIALOG:
		g_singleDialogHandle = hwndDlg;
		StartBruteForceThread();
		break;
	case WM_COMMAND:
		if( LOWORD(wParam) == IDC_EDIT1 && HIWORD(wParam) == EN_CHANGE )
		{
			TCHAR pwd[MAX_PATH];

			if( GetDlgItemText(hwndDlg, IDC_EDIT1, 
				pwd, SIZEOF_ARRAY(pwd)) )
			{
				lstrcpy(g_currentPassword, pwd);
				g_currentPasswordSize = lstrlen(pwd);

				RestartBruteForceThread();
			}
		}
		break;
	case WM_CLOSE:
		EndDialog(hwndDlg, TRUE);
		break;
	default:
		ret = FALSE;
	}

	return ret;
}