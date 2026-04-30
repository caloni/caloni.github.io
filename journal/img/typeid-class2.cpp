#include <iostream>

using namespace std;

class MyClass
{
	public:
		virtual void MyMethod()
		{
			cout << typeid(*this).name() << "::MyMethod" << endl;
		}
};

class MyDerivatedClass1 : public MyClass { };

class MyDerivatedClass2 : public MyClass { };

int main()
{
	MyClass* myc1 = new MyDerivatedClass1;
	MyClass* myc2 = new MyDerivatedClass2;

	myc1->MyMethod();
	myc2->MyMethod();
}

