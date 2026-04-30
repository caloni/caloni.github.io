// Papai, o que que é isso?
// Ora, filho, apenas uma definição de estrutura!
//
struct MinhaStruct {
   int x;
   int y;
};

// muitas linhas abaixo...

void func(MinhaStruct* ms)
{
   // asterisco significa ponteiro para MinhaStruct!
}

int main()
{
   MinhaStruct ms;
   func(&ms);
}
