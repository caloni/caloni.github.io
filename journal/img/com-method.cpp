STDMETHODIMP CService::Open(<params>, PLONG *pctReturn)
{
	if( DeuErrado() )
	{
		*pctReturn = ERR_DEU_ERRADO;
		return S_OK;
	}
	//...
}
