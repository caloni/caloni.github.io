while( g_bruteForceContinue )
{
	if( lstrcmp(currentPassword, breakPassword) != 0 )
	{
		IncrementPassword(breakPassword, 
			SIZEOF_ARRAY(breakPassword) - 1);
	}

	SetDlgItemText(g_singleDialogHandle, IDC_EDIT2, breakPassword);
}