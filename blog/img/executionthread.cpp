// the well-defined functions are functional blocks of code and have
// the same signature, allowing the creation of a pointer array to them
void WellDefinedFunction1( args );
void WellDefinedFunction2( args );
void WellDefinedFunction3( args );
//...
void WellDefinedFunctionN( args );

// this thread stays forever waiting execution commands from some
// well-defined function. the parameter that it receives is the function number
void ExecutionThread()
{
	// 2. ad aeternum
	while( true )
	{
		// 5. it runs some well-defined function by number
		ExecuteWellDefinedFunction( functionNumber );
	}
}

// the well-defined functions script is an integer array indicating 
// the number for the next function that is going to be called
int FunctionsToBeCalled[] = { 3, 4, 1, 2, 34, 66, 982, n };

int Start()
{
	// 1. we create the thread that is going to run commands
	CreateThread( ExecutionThread );

	// 3. for each script item (each function number)
	for( int i = 0; i < sizeof(FunctionsToBeCalled); ++i )
	{
		// 4. tells the thread to run the function number N
		TellExecutionThreadToExecuteWellDefinedFunction( FunctionToBeCalled[i] );
	}

	// 6. end of execution.
	return 0;
}