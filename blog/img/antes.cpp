typedef struct _MINHASTRUCT {
   int x;
   int y;
}
MINHASTRUCT, *LPMINHASTRUCT;

// muitas linhas abaixo...

void func(LPMINHASTRUCT ms)
{
   // o que diabos é um LP, mesmo?
}

int main()
{
   MINHASTRUCT ms;
   func(&ms);
}
