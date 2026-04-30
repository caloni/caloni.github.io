#include <iostream>

using namespace std;

int main()
{
	cout << typeid( int ).name() << endl;

	int x;
	cout << typeid( x ).name() << endl;

	cout << typeid( 2 + 2 ).name() << endl;
}

