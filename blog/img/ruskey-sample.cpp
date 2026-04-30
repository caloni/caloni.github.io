switch( pMsg->message )
{
	case WM_CHAR:
	{
		LPTSTR ptzChar =
		_tcschr(g_tzRussAlphabet, (TCHAR) pMsg->wParam);

		if( ptzChar )
		{
			size_t offset = ptzChar - g_tzRussAlphabet;
			pMsg->wParam = (WPARAM) g_tzPortAlphabet[offset];
		}
	}
}