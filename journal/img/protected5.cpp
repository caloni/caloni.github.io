// espertinho, hein?

int Derived::GetAnotherProtected()
{
	AnotherDerived anotherDeriv; // não acesso os protegidos desse aqui...
	Base& base = anotherDeriv; // mas quem sabe se eu acessar os genes da minha mãe?
	return base.m_protected; // nada feito =(. Também, se nem eu mesmo consegui me acessar...
}