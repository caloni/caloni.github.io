int factorial(int n, int a)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n == 1)
		return a;
	else
		return factorial(n - 1, n * a);
}

int main()
{
	return factorial(1000, 0);
}
