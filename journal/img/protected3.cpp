// dentro da lei

int Derived::GetAnotherProtected()
{
	Derived deriv; // meu irmão: typeid(deriv) == typeid(*this).
	return deriv.m_protected; // mesmo tipo do escopo: meus direitos são preservados
}