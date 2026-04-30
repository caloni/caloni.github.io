/** @file dois_apelidos.cpp */
#include <iostream>

using namespace std;

struct Struct
{
   int x;
   int y;
};

typedef Struct Struct1;
typedef Struct Struct2;

int main()
{
   Struct1 s1;
   Struct2 s2;

   cout << typeid(s1).name() << endl;
   cout << typeid(s2).name() << endl;
}
