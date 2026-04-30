jmp_buf env; // Contains the next instruction (stack state).

void Func()
{
	// 3. Return using the "nonconventional" way
	longjmp(env, 1);
}

void CallFunc()
{
	// 1. If we're setting, returns 0.
	// 2. If we're returning, returns a value different from 0.
	if( setjmp(env) == 0 )
		Func();

	int x = 10; // 4. Next instruction.
}