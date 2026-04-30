#include <windows.h>
#include <iostream>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;


list<DWORD> g_ticks;
list<LONG> g_increments;


DWORD WINAPI Ticks(PVOID)
{
    for( int i = 1; i <= 100; ++i )
    {
        DWORD tick = GetTickCount();
        g_ticks.push_back(tick);
        Sleep(rand() % 20);
    }
    return 0;
}


DWORD WINAPI Increment(PVOID)
{
    static LONG st_prevIncrement = 0;

    for( int i = 1; i <= 100; ++i )
    {
        LONG increment = InterlockedIncrement(&st_prevIncrement);
        g_increments.push_back(increment);
        Sleep(rand() % 20);
    }
    return 0;
}


int main()
{
    const size_t threadsCount = 20;
    HANDLE threads[threadsCount];

    srand((unsigned int) time(0));

    for( size_t i = 0; i < threadsCount / 2; ++i )
        threads[i] = CreateThread(NULL, 0, Ticks, NULL, 0, NULL);
    for( size_t i = threadsCount / 2; i < threadsCount; ++i )
        threads[i] = CreateThread(NULL, 0, Increment, NULL, 0, NULL);

    WaitForMultipleObjects(threadsCount, threads, TRUE, INFINITE);

    for( auto it = g_ticks.begin(); it != g_ticks.end(); ++it )
    {
        DWORD tick = *it;
        size_t incrementOccurrence = count(g_increments.begin(), g_increments.end(), tick);

        if( incrementOccurrence )
        {
            cout << "Ocorrencia de incremento duplicado!\n";
            break;
        }
    }

    for( auto it = g_ticks.begin(); it != g_ticks.end(); ++it )
    {
        DWORD tick = *it;
        size_t tickOccurrence = count(g_ticks.begin(), g_ticks.end(), tick);

        if( tickOccurrence )
        {
            cout << "Ocorrencia de tick duplicado!\n";
            break;
        }
    }
}

