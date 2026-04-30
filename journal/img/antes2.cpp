// Papai, o que que é isso?
// Ora, filho, apenas uma definição de sinônimo da struct
// _MINHASTRUCT, cujo nome não é usado, para dois nomes
// em maiúsculas, apesar se não serem defines, com uma
// nomenclatura de ponteiro que eu nunca vi na vida (obs: 
// papai programa em um sistema não-Windows).
//
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
