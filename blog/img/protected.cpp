#include <iostream>

using namespace std;

class Base
{
protected:
	int m_protected;
};

class Derived : public Base
{
public:
	int GetProtected();
	int GetAnotherProtected();
};

class AnotherDerived : public Base
{
};

int Derived::GetProtected()
{
	return m_protected; // tudo bem. sou um Derived; tenho meus direitos!
}

int Derived::GetAnotherProtected()
{
	AnotherDerived anotherDeriv;
	return anotherDeriv.m_protected; // inacessível. não estamos em AnotherDerived!
}

int main()
{
	Derived deriv;

	deriv.GetProtected();
	deriv.GetAnotherProtected(); // isso não vai dar certo...
}