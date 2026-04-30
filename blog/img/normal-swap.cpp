/** Troca o valor entre duas variáveis inteiras. Ou seja, ao final da função
a variável first irá conter o valor da variável second e vice-versa.
*/
void normalSwap(int &first, int& second)
{
	int third = first;
	first = second;
	second = third; // contém o valor de first
}

int main()
{
	int first = 13;
	int second = 42;

	cout << "first: " << first << ", second: " << second << endl;
	normalSwap(first, second);
	cout << "first: " << first << ", second: " << second << endl;
}