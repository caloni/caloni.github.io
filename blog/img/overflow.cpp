#include <limits.h>
#include <iostream>

int main()
{
	int x = INT_MAX; // máximo inteiro que pode ser armazenado no tipo int

	std::cout << x << std::endl; // se é o máximo, é um valor positivo
	x = x + 1;  // mas basta um empurrãozinho para que
	std::cout << x << std::endl; // a casa caia
}