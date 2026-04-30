int soma(int x, int y);
double soma(double x, double y);

int main()
{
    int zi = soma(2, 3); // dois tipos int: chamar soma(int, int)
    double zd = soma(2.5, 3.4); // dois tipos double: só pode ser soma(double, double)
    return 0;
}

