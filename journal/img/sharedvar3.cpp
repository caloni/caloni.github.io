#define _CRT_SECURE_NO_DEPRECATE
#include "ShareVar.h"
#include <windows.h>
#include <tchar.h>

#include <stdio.h>

#define SHARED_VAR "FraseSecreta"

/** Exemplo de como usar as funções de alocação de memória compartilhada
AllocSharedVariable, OpenSharedVariable e FreeSharedVariable.
*/
int _tmain(int argc, PTSTR argv[])
{
	// passou algum parâmetro: lê a variável compartilhada e exibe

	if( argc > 1 )
	{
		system("pause");

		TCHAR (*sharedVar)[100] = 0; // ponteiro para array de 100 TCHARs
		HANDLE varH = AllocSharedVariable(&sharedVar, _T(SHARED_VAR));

		if( varH && sharedVar )
		{
			_tprintf(_T("Frase secreta: '%s'n"), *sharedVar);
			_tprintf(_T("Pressione <enter> para retornar..."));
			getchar();
		}
	}
	else // não passou parâmetro: escreve na variável 
	// compartilhada e chama nova instância
	{
		TCHAR (*sharedVar)[100] = 0; // ponteiro para array de 100 TCHARs
		HANDLE varH = AllocSharedVariable(&sharedVar, _T(SHARED_VAR));

		if( varH && sharedVar )
		{
			PTSTR cmd = new TCHAR[ _tcslen(argv[0]) + 10 ];
			_tcscpy(cmd, _T("\""));
			_tcscat(cmd, argv[0]);
			_tcscat(cmd, _T("\" 2"));

			_tcscpy(*sharedVar, _T("Tuintuintuclaim"));
			_tsystem(cmd);

			delete [] cmd;
		}
	}

	return 0;
}