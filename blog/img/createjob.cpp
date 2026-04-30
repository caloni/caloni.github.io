#define _WIN32_WINNT 0x0500 // Jobs só existem do 2000 em diante
#include <windows.h>


/** @brief Função que cria um processo a partir de cmdLine
 * e coloca-o dentro de um job. A função aguarda o término
 * do processo e de qualquer subprocesso criado por este.
 */
DWORD CreateJobAndWait(LPSTR cmdLine)
{
   // primeiro, criamos um job sem nome
   HANDLE job = CreateJobObject(NULL, NULL);

   if( job )
   {
      STARTUPINFO si = { sizeof(si) };
      PROCESS_INFORMATION pi;

      // depois, criamos um processo suspenso (travado)
      if( CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 
         CREATE_SUSPENDED | CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi) )
      {
         // atribuímos esse processo ao nosso jobo
         AssignProcessToJobObject(job, pi.hProcess);

         // rodamos o processo
         ResumeThread(pi.hThread);

         // essa é uma completion i/o port genérica
         // (ou seja, não relacionada com nenhum arquivo
         // ou outra completion port)
         HANDLE port = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 
                 NULL, 0, 0);

         if( port )
         {
            JOBOBJECT_ASSOCIATE_COMPLETION_PORT jobPort;

            jobPort.CompletionKey = 0; // ver variável key abaixo
            jobPort.CompletionPort = port; // nossa completion port vai aqui!

            // definimos a c.p. em nosso job
            if( SetInformationJobObject(job, 
                        JobObjectAssociateCompletionPortInformation, 
                        &jobPort, sizeof(jobPort)) )
            {
               ULONG_PTR key = 0; // ver membro CompletionKey acima
               LPOVERLAPPED overlap = 0;
               DWORD tranferred = 0;

               // nosso loop de mensagens com completion port
               while( GetQueuedCompletionStatus(port, &tranferred, 
                  &key, &overlap, INFINITE) )
               {
                  // transferred especifica a mensagem
                  DWORD msg = *(LPDWORD) &tranferred;

                  // significa que não existem mais processos rodando
                  if( msg == JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO )
                     break; // saímos fora
               }
            }

            CloseHandle(port); // fecha tudo
         }

         CloseHandle(pi.hThread); // fecha tudo
         CloseHandle(pi.hProcess); // fecha tudo
      }

      CloseHandle(job); // fecha tudo
   }

   return 0;
}


int main(int argc, char* argv[])
{
   if( argc == 2 )
      CreateJobAndWait(argv[1]);
}

