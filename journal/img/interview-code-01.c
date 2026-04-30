#include <stdio.h>
#include <stdlib.h>

void func()
{
	*(int *)0 = 0;
	return 0;
}

int main(int argc, char **argv)
{
	func();
	return 0;
}