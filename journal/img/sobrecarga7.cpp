#include <windows.h>
#include <objbase.h>

#include <iostream>
#include <string>

using namespace std;


struct CreateNewGUID
{
   operator wstring ()
   {
      GUID guid = operator GUID();
      OLECHAR buf[40] = { };
      ::StringFromGUID2(guid, buf, sizeof(buf));
      return wstring(buf);
   }

   operator GUID ()
   {
      GUID guid = { };
      ::CoCreateGuid(&guid);
      return guid;
   }
};



int _tmain(int argc, _TCHAR* argv[])
{
   wstring guidS;
   GUID guid;

   // instancia um CreateNewGUID e chama CreateNewGUID::operator wstring()
   guidS = CreateNewGUID();

   // instancia um CreateNewGUID e chama CreateNewGUID::operator GUID()
   guid = CreateNewGUID();

   wcout << L"Pra nao dizer que esse exemplo nao imprime nada:\n"
         << guidS << L'\n';

   return 0;
}