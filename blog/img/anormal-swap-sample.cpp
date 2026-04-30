#include <iostream>

using namespace std;

/** Troca o valor entre duas variáveis inteiras. Ou seja, ao final da função
a variável first irá conter o valor da variável second e vice-versa.
*/
void anormalSwap(int &first, int& second)
{
	first = first ^ second; // first contém first e second juntos
	second = first ^ second; // firstXORsecond XOR second = first
	first = first ^ second; // second = first. logo, firstXORsecond XOR first = second
}

int main()
{
	int first = 13;
	int second = 42;

	cout << "first: " << first << ", second: " << second << endl;
	anormalSwap(first, second);
	cout << "first: " << first << ", second: " << second << endl;
}