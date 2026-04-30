MIDL_INTERFACE("00000002-0000-0000-C000-000000000046")
IMalloc : public IUnknown
{
	public:
	virtual void *STDMETHODCALLTYPE Alloc( 
	/* [in] */ SIZE_T cb) = 0;


	virtual void *STDMETHODCALLTYPE Realloc( 
	/* [in] */ void *pv,
	/* [in] */ SIZE_T cb) = 0;

	virtual void STDMETHODCALLTYPE Free( 
	/* [in] */ void *pv) = 0;


	virtual SIZE_T STDMETHODCALLTYPE GetSize( 
	/* [in] */ void *pv) = 0;

	virtual int STDMETHODCALLTYPE DidAlloc( 
	void *pv) = 0;

	virtual void STDMETHODCALLTYPE HeapMinimize(void) = 0;
};
