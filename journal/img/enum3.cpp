enum ModoDeServir
{
   assado,
   cozido,
   frito,
   cru
};


void Cook(Prato p, ModoDeServir ms);

main()
{
   Cook(frango, cozido);
}


enum FileOpenMode
{
   fomRead   = 0x0001,
   fomWrite  = 0x0002,
   fomOver   = 0x0004,
   fomDel    = 0x0008,
};

void OpenFile(DWORD fileOpenMode);

main()
{
   OpenFile(fomRead | fomWrite);
}