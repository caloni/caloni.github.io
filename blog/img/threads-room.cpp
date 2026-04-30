#include <windows.h>
#include <stdio.h>
 
#define MAX_GLOBAL_COUNTER 10
 
int g_globalCounter = 0;
CRITICAL_SECTION g_globalCounterCS;
 
 
DWORD WINAPI IncrementGlobalCounter(PVOID)
{
	DWORD tid = GetCurrentThreadId();
 
	while( g_globalCounter < MAX_GLOBAL_COUNTER )
	{
		// esse é o começo de nossa seção crítica
		// só uma thread entra por vez por aqui
		EnterCriticalSection(&g_globalCounterCS);

		int temp = g_globalCounter;
		temp = temp + 1;
		Sleep(0); // vou para o final da fila antes de contar
		g_globalCounter = temp;

		// esse é o fim de nossa seção crítica
		// a partir dessa chamada outra thread pode entrar pelo começo
		LeaveCriticalSection(&g_globalCounterCS);

		printf("Counter: %d\t\tThread: %d\n", temp, tid);
	}
	return 0;
}
 
 
int main()
{
	HANDLE threads[3];
	DWORD tids[3];

	// precisamos inicializar nosso recurso de seção crítica	
	InitializeCriticalSection(&g_globalCounterCS);

	for( int i = 0; i < 3; ++i )
	{
		threads[i] = CreateThread(NULL, 0, IncrementGlobalCounter, 0, 0, &tids[i]);
		printf("Thread %i: %d\n", i, tids[i]);
	}
 
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);

	// precisamos liberar o recurso de seção crítica
	DeleteCriticalSection(&g_globalCounterCS);
}

