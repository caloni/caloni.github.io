#include <windows.h>
#include <stdio.h>

#define MAX_GLOBAL_COUNTER 10

int g_globalCounter = 0;


DWORD WINAPI IncrementGlobalCounter(PVOID)
{
	DWORD tid = GetCurrentThreadId();

	while( g_globalCounter < MAX_GLOBAL_COUNTER )
	{
		int temp = g_globalCounter;
		temp = temp + 1;
		g_globalCounter = temp;
		printf("Counter: %d\t\tThread: %d\n", temp, tid);
	}
	return 0;
}


int main()
{
	HANDLE threads[3];
	DWORD tids[3];

	for( int i = 0; i < 3; ++i )
	{
		threads[i] = CreateThread(NULL, 0, IncrementGlobalCounter, 0, 0, &tids[i]);
		printf("Thread %i: %d\n", i, tids[i]);
	}

	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
}
