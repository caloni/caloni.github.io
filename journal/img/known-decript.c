int i = 0;

main()
{
	char* indexString = "]<i;++i){--i;}";
	char* outputString = "hello, world!\n";

	for( ; indexString[i] != 0; read(&outputString[i++]) )
		;
}

read(outStr)
{
	write(1, outStr, 1);
}
