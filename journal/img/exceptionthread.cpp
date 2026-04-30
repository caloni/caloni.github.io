// filter exceptions that were thrown by the thread below
DWORD ExceptionFilterButExecuteWellDefinedFunction()
{
	// 5. run some well-defined function by number
	ExecuteWellDefinedFunction( number );

	return EXCEPTION_EXECUTE_HANDLER; // goes to except code
}

// this thread stays forever waiting execution commands from a 
// well-defined function. its "parameter" is the function number
void ExecutionThread()
{
	// 2. ad aeternum
	while( true )
	{
		__try
		{
			__asm int 3 // breakpoint exception

			// it stops the debugger if we have an attached debugger in
			// the process, or throws an exception if there is no one
		}
		__except( ExceptionFilterButExecuteWellDefinedFunction() )
		{
			// it does nothing. here is NOT where is the code (obvious, huh?)
		}

		Sleep( someTime ); // give some time
	}
}