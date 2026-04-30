#include <windows.h>
#include <iostream>
#include <time.h>

using namespace std;

// declaramos que existe uma classe com esse nome
class FuzzyCall;

// ponteiro para métodos da classe acima
typedef void (FuzzyCall::*FP_Fuzzy)();

/** Classe que faz chamada de um método aleatório. */
class FuzzyCall
{
public:

	FuzzyCall()
	{
		srand(GetTickCount()); // chacoalha o saco de bingo
	}

   FP_Fuzzy GiveMeAMethod() { return m_methods[rand() % 3]; }

private:
	void MethodOne()   { cout << "One!\n"; }
	void MethodTwo()   { cout << "Two!\n"; }
	void MethodThree() { cout << "Three!\n"; }

	static FP_Fuzzy m_methods[3];
};

/** Array com os métodos que podem ser chamados aleatoriamente. */
FP_Fuzzy FuzzyCall::m_methods[3] = { &MethodOne, &MethodTwo, &MethodThree };

/** Recebe um ponteiro para um método de FuzzyCall e chama com um objeto local. */
void passThrough(FP_Fuzzy pMethod)
{
	FuzzyCall fuzzyObject; // esse é o objeto local
	( fuzzyObject.*pMethod )(); // essa é a chamada
}

/** No princípio Deus disse: 'int main!'
*/
int main()
{
	FuzzyCall fuzzyObject1;
	FP_Fuzzy pMethod;

	// pegamos um método da classe qualquer
	pMethod = fuzzyObject1.GiveMeAMethod();

	// e passamos para uma outra função
	passThrough(pMethod);
}