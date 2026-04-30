namespace Math
{
	const float Pi = 3.14;
}

//...

int func1(int x)
{
	float calc = x * Math::Pi;
	return calc;
}

//...

int func2(int y)
{
	const size_t PathSize = MAX_PATH * 2;
	//...
	//...
	char path[PathSize];
	//...
}
