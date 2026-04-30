#include <stdio.h>


void InitFunction()
{
	printf("InitFunction");
}


void DoAnotherJob()
{
	char buf[100] = "";
	fgets(buf, sizeof(buf), stdin);
	printf("New line: %s", buf);
}


void TerminateFunction()
{
	printf("TerminateFunction");
}


int main()
{
	InitFunction();

	while( ! feof(stdin) )
	{
		DoAnotherJob();
	}

	TerminateFunction();
}

