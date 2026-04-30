struct CreateNewGUID
{
   operator wstring () { ... } // a conversão é a "chamada da função".

   operator GUID () { ... } // E como existem duas conversões... sobrecarga!
};