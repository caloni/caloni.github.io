/** Classe helper para as nossas funções de alocação de variáveis
compartilhadas com o mundo. */
template<typename T>
class SharedVar
{
public:
	// se conseguir, parabéns; senão, retorna BUM!
	SharedVar(PCTSTR varName)
	{
		m_memPointer = 0;
		m_memHandle = AllocSharedVariable(&m_memPointer, varName);

		if( ! m_memHandle || ! m_memPointer )
			throw GetLastError();
	}

	// libera recursos alocados para a variável
	~SharedVar()
	{
		FreeSharedVariable(m_memHandle, m_memPointer);
	}

	T& operator * ()
	{
		return *m_memPointer;
	}

private:
	// não vamos nos preocupar com isso agora
	SharedVar(const SharedVar& obj);
	SharedVar& operator = (const SharedVar& obj);

	T* m_memPointer;
	HANDLE m_memHandle;
};