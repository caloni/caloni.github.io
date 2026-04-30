CreateWindowEx(0, WC_LINK, 
	L"<a href=\"http://www.caloni.com.br\">This site rocks!</a>", 
	WS_VISIBLE | WS_CHILD | WS_TABSTOP, ...);

//...

	case WM_NOTIFY:
		switch( ((LPNMHDR)lParam)->code )
		{
		case NM_CLICK:
		case NM_RETURN:
		{
			PNMLINK pNMLink = (PNMLINK)lParam;
			LITEM item = pNMLink->item;
			if( (((LPNMHDR)lParam)->hwndFrom == st_linkHwnd[hWndDlg]) )
			{
				// codigo util
			}
