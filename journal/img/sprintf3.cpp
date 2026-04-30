// SPrintf.cpp : 8)
//
 
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
 
int _tmain(int argc, _TCHAR* argv[])
{
	__int64 myLoooongInt = 0x1234;
	PCSTR myString = "0x1234";

	printf("0x%x%s", myLoooongInt, myString);

	return 0;
}