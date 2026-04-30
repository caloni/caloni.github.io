/** @file structs.cpp */
struct MyStruct { int x, y; };

void func1()
{
   /*struct*/ MyStruct ms;
   //...
}

void func2(/*struct*/ MyStruct msa)
{
   //...
}

int main()
{
   /*struct*/ MyStruct ms;
   func2(ms);
}
