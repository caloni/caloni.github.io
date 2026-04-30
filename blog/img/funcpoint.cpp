#include <iostream>

void func(int x, int y)
{
   std::cout << x << '-' << y << '\n';
}

int main()
{
   void* pf = func;
   ( ( void (*)(int, int) ) pf )(3, 14);
}
