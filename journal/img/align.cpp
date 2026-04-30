#include <stdio.h>

template<typename Teste, int Align>
union TesteAlignTemplate
{

	Teste t;

	unsigned char align[ (sizeof(Teste) % Align) ?
		(sizeof(Teste) / Align + 1) * Align
		: (sizeof(Teste))
		];

};


struct Teste
{
	char buf[13];
	int x;
};


int main()
{
	typedef TesteAlignTemplate<Teste, 8> TesteAlign;
	TesteAlign tst;

	printf("Alinhamento. Union: %d; Teste: %d; Align: %d.\n",
			sizeof(TesteAlign), 
			sizeof(Teste), 
			sizeof(tst.align) );

	printf("t: %p, align: %p\n", &tst.t, tst.align);

	return 0;
}

