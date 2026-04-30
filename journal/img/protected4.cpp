// fora-da-lei

int Derived::GetAnotherProtected()
{
	Base& base = *this; // os genes da minha mãe.
	return base.m_protected; // eu não me acesso! tipo o subconsciente...
}