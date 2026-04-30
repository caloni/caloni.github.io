/** Use this macro instead LongJmp
*/
#define ANTIDEBUG(code)
{
	jmp_buf env;

	if( setjmp(env) == 0 )
	{
		LongJmp(&env);
	}
	else
	{
		code;
	}
}

/** And God said: 'int main!'
*/
int main()
{
	DWORD ret = ERROR_SUCCESS;

	while( cin )
	{
		string line;

		cout << "Type something\n";
		getline(cin, line);

		ANTIDEBUG(( cout << line << endl ));
	}

	return (int) ret;
}