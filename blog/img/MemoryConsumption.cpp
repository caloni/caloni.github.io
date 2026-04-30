#include <windows.h> // critical section, create thread...
#include <list> // nossa lista interna
#include <time.h> // randomização

struct Queue // uma fila (duh)
{
    size_t bufferSize; // cada item é um buffer de tamanho fixo
    DWORD wait; // antes de processar, aguardemos esse tempo fixo
    CRITICAL_SECTION cs; // stl é thread-safe, pero no mucho
    std::list<char*> items; // os itens!
};

DWORD WINAPI InsertItems(LPVOID pvQueue) // insere, insere, insere....
{
    Queue& queue = *(Queue*) pvQueue;
    for( int i = 0; i < 10 * 1000; ++i ) // 10k itens!
    {
        char* buffer = new char[queue.bufferSize];
        memset(buffer, (int) (i % ('Z' - 'A')) + 'A', queue.bufferSize); // teoricamente de A a Z
        buffer[queue.bufferSize - 1] = 0; // string C pra facilitar nossa depuração
        EnterCriticalSection(&queue.cs); // deixa eu entrar!
        queue.items.push_back(buffer);
        LeaveCriticalSection(&queue.cs); // deixa eu sair!
        Sleep(10); // dá uma dormidinha (sempre menor dormidinhas do processamento)
    }
    return ERROR_SUCCESS; // "tá tudo certo!" (by Starcraft 2)
}

DWORD WINAPI ProcessItems(LPVOID pvQueue) // processa, processa, processa...
{
    Queue& queue = *(Queue*) pvQueue;
    DWORD wait = 2;
    Sleep(10000); // como um advogado oportunista, aguardamos por alguém pra processar
    while( ! queue.items.empty() ) // agora vai até esvaziar o recinto
    {
        EnterCriticalSection(&queue.cs); // deixa eu entrar!
        char* buffer = queue.items.front();
        queue.items.pop_front();
        LeaveCriticalSection(&queue.cs); // deixa eu sair!
        delete [] buffer;
        Sleep(queue.wait); // aguarda por... por quanto mesmo?
    }
    return ERROR_SUCCESS; // "tá tudo certo!" (by Starcraft 2)
}

int main(int argc, char* argv[]) // No princípio havia a pilha, quando Deus disse: 'int main!'
{
    static const size_t QUEUES_SIZE = 20; // número de filas sendo processadas
    static const size_t QUEUE_ITEM_SIZE = 0x1000; // 1KB é o chunk alocado por item
    static const DWORD WAIT_TIMES[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1000 }; // alguém vai esperar demais

    Queue queues[QUEUES_SIZE]; // as filas
    HANDLE queueThreads[QUEUES_SIZE * 2]; // as threads que processam as filas

    srand((unsigned int)time(0)); // randomizemos tudo

    for( size_t i = 0; i < QUEUES_SIZE; ++i )
    {
        queues[i].bufferSize = QUEUE_ITEM_SIZE + i; // para diferenciarmos as filas
        queues[i].wait = WAIT_TIMES[ rand() % (sizeof(WAIT_TIMES) / sizeof(DWORD)) ]; // vamos esperar por... por quanto mesmo?
        InitializeCriticalSection(&queues[i].cs); // deu crash em algumas situações em release (stl deveria ser thread-safe...)
        queueThreads[i] = CreateThread(NULL, 0, InsertItems, &queues[i], 0, NULL); // criamos thread de inserção
        queueThreads[QUEUES_SIZE + i] = CreateThread(NULL, 0, ProcessItems, &queues[i], 0, NULL); // criamos thread de processamento
    }

    WaitForMultipleObjects(QUEUES_SIZE * 2, queueThreads, TRUE, INFINITE); // espera a 'gaguera'
    return 0; // "tá tudo certo!" (by Starcraft 2)
}
