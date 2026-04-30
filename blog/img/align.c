#include <stdio.h>

union TesteAlign
{

	struct Teste
	{
		char buf[13];
		int x;
	}
	t;

	unsigned char align[ (sizeof(struct Teste) % 8) ?
		(sizeof(struct Teste) / 8 + 1) * 8
		: (sizeof(struct Teste))
		];

};


int main()
{
	union TesteAlign tst;

	printf("Alinhamento. Union: %d; Teste: %d; Align: %d.\n",
			sizeof(union TesteAlign), 
			sizeof(struct Teste), 
			sizeof(tst.align) );

	printf("t: %p, align: %p\n", &tst.t, tst.align);

	return 0;
}

