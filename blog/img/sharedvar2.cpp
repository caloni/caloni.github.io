#pragma once
#include <windows.h>
#include <tchar.h>

/** Aloca uma variável em memória mapeada, permitindo a qualquer processo
com direitos enxergá-la e alterá-la.
*/

template<typename T>
HANDLE AllocSharedVariable(T** pVar, PCTSTR varName)
{
	DWORD varSize = sizeof(T);
	HANDLE ret = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
		0, varSize, varName);

	if( ret )
	{
		*pVar = (T*) MapViewOfFile(ret, FILE_MAP_ALL_ACCESS, 0, 0, 0);

		if( ! *pVar )
		{
			DWORD err = GetLastError();
			CloseHandle(ret);
			SetLastError(err);
		}
	}
	else
		*pVar = NULL;

	return ret;
}

/** Abre uma variável que foi criada em memória mapeada, permitindo ao
processo atual enxergar e alterar uma variável criada por outro processo.
*/
template<typename T>
HANDLE OpenSharedVariable(T** pVar, PCTSTR varName)
{
	DWORD varSize = sizeof(T);
	HANDLE ret = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, varName);

	if( ret )
	{
		*pVar = (T*) MapViewOfFile(ret, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, varSize);

		if( ! *pVar )
		{
		DWORD err = GetLastError();
		CloseHandle(ret);
		ret = NULL;
		SetLastError(err);
		}
	}
	else
		*pVar = NULL;

	return ret;
}

/** Libera visualização de uma variável em memória mapeada. Quando o último processo
liberar a última visualização, a variável é eliminada da memória.
*/
template<typename T>
VOID FreeSharedVariable(HANDLE varH, T* pVar)
{
	if( pVar )
		UnmapViewOfFile(pVar);
	if( varH )
		CloseHandle(varH);
}