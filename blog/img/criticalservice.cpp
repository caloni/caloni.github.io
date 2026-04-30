#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void DoProcess()
{
	int nextNumber = rand() % 1000;
	//bool even = nextNumber % 2;
	bool even = !(nextNumber % 2);
	printf("%d => %s\n", nextNumber, even ? "even" : "odd");
}


int main()
{
	srand( time(0) );

	while( true )
	{
		DoProcess();
		Sleep(3000);
	}
}

