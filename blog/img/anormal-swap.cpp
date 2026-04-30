template<typename T1, typename T2, typename T3>
void universalXor(const T1& first, const T2& second, T3& result)
{
	typedef unsigned char byte;

	const byte* pFirst = reinterpret_cast<const byte*>( &first );
	const byte* pSecond = reinterpret_cast<const byte*>( &second );

	byte* pResult = reinterpret_cast<byte*>( &result );

	for( size_t i = 0; i < sizeof(first) && i < sizeof(second); ++i )
		pResult[i] = pFirst[i] ^ pSecond[i];
}

int main()
{
	// trocando ints
	int x = 13, y = 42;

	cout << "x: " << x << ", y: " << y << '\n';
	universalXor(x, y, x);
	universalXor(x, y, y);
	universalXor(x, y, x);
	cout << "x: " << x << ", y: " << y << "\n\n";

	// trocando strings em c
	char str1[50] = "teste de xor", str2[50] = "aceita strings!";

	cout << "str1: " << str1 << ", str2: " << str2 << '\n';
	universalXor(str1, str2, str1);
	universalXor(str1, str2, str2);
	universalXor(str1, str2, str1);
	cout << "str1: " << str1 << ", str2: " << str2 << '\n';

	return 0;
}