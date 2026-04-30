/** The only purpose of this function is to generate an exception.
*/
DWORD LongJmp(jmp_buf* env)
{
	__try
	{
		__asm int 3
	}
		__except( EXCEPTION_EXECUTE_HANDLER )
	{
		longjmp(*env, 1);
	}

	return ERROR_SUCCESS;
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

		jmp_buf env;

		if( setjmp(env) == 0 )
		{
			LongJmp(&env);
		}
		else
		{
			cout << line << endl;
		}
	}

	return (int) ret;
}