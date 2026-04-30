STDMETHODIMP CService::Open(BYTE *fileName, COUNT keyNo, COUNT *pctReturn)
{
	char szMsg[200];

	// Verifica se o banco de dados foi inicializado
	if (!_Main.m_bDBInitialized)
	{
		_Main.Log("Error opening file before database to be initialized.");
		*pctReturn = FINT_ERR;
		return S_OK;
	}

	// Verifica se o arquivo já foi aberto
	if (m_pData)
	{
		sprintf(szMsg, "Error on open file \"%s\". File already opened.");
		_Main.Log(szMsg);
		*pctReturn = ERR_BLABLABLA;
		return S_OK;
	}
	//...
}
