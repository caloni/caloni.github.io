// A listagem abaixo pode virar um enum...
#define FOM_READ   0x0001
#define FOM_WRITE  0x0002
#define FOM_OVER   0x0004
#define FOM_DEL    0x0008

// ... como este aqui!
enum FileOpenMode
{
   FOM_READ   = 0x0001,
   FOM_WRITE  = 0x0002,
   FOM_OVER   = 0x0004,
   FOM_DEL    = 0x0008,
};


// esse pedaço de código abaixo...
int main()
{
   OpenFile(path, FOM_WRITE);
}

// ... vira isso após ser pré-processado...
int main()
{
   OpenFile(path, 0x0002);
}

// ... mas isso se fossem usados enums...
int main()
{
   OpenFile(path, FOM_WRITE); // FOM_WRITE faz parte da linguagem
}
