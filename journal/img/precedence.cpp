#include <stdio.h>

int main()
{
	int f1,f2,s=0;
	   for(f1=1;(f1==11&&s!=5)?s=5,f1=0,putchar(10):(f1<=10)?f1=f1:f1=12,f1<=11;f1++)
			for(f2=1+s;f2<=5+s;f2++)printf("%dx%d=%d%c",f2,f1,f1*f2,(f2==5+s)?10:9);
	return 0;
}