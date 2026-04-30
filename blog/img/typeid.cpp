#include <iostream>
#include <typeinfo>

using namespace std;


class Base
{
public:
	Base()
	{
		cout << "Base()\n";
		m_x = 0;
	}

	~Base()
	{
		cout << "~Base()\n";
	}

	int m_x;
};


// como Base não é polimórfica (como vamos ver), Deriv paga o pato
class Deriv : public Base
{
public:
	Deriv()
	{
		cout << "Deriv()\n";

		m_x = 1;
		m_y = 0;
	}

	virtual ~Deriv() // ela é polimórfica
	{
		cout << "~Deriv()\n";
	}

	int m_y;
};


void func(Base* b) // eu não sei que é uma derivada
{
	cout << typeid(*b).name() << '\n'; // e nem o typeid número 1
}


int main()
{
	Base* b = new Deriv(); // o ponteiro é pra base, mas a instância é de derivada
	func(b);
}