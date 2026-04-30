#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void* AlocaMasNaoDevolve(__int64 largeBytes)
{
    void* ret = nullptr;
    size_t bytes = (size_t) largeBytes; // assumo o risco de truncar

    if( bytes == largeBytes )
    {
        try
        {
            ret = new char[bytes];
        }
        catch(bad_alloc&)
        {
            cout << "Nao foi possivel alocar " << bytes << " bytes" << endl;
        }
    }

    return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 totalBytes = 0;
    __int64 bytes = 0;

    do
    {
        cout << "Alocar quantos bytes? (zero para sair): ";
        cin >> bytes;

        void* address = AlocaMasNaoDevolve(bytes);

        if( address )
        {
            totalBytes += bytes;

            cout << "Alocados " << bytes << " bytes em " << address
                << " (total ate o momento: " << totalBytes << " bytes)\n";
        }
    }
    while( bytes );

    return int(totalBytes);
}
