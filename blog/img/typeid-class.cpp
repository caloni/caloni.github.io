#include <iostream>

using namespace std;

class MyClass
{
	public:
		void MyMethod()
		{
			cout << typeid(*this).name() << "::MyMethod" << endl;
		}
};

int main()
{
	MyClass myc;

	myc.MyMethod();
}

