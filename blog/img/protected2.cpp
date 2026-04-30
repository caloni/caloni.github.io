// another chance

int Derived::GetAnotherProtected()
{
	Base base; // somos derivados dessa base, não somos?
	return base.m_protected; // mas não é por isso que vamos acessar um membro protegido de boa.
}