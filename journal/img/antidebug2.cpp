// Go back to place pre-defined by the restoration point.
void LongJmp(restorePoint)
{
	// Here we will generate an exception to make things difficult.
	// @todo Make a breakpoint exception and catch it.

	// 3. We return to the if without using the stack, but from the restoration point.
	GoBackToTheStartFunction(restorePoint);
}

// Here everything begins.
int Start()
{
	// Obs.: follow the agreement flow according to the numbers.

	// 1. First pass: we define a restoration point to the return of LongJmp.
	// 4. Second pass: we go back from the LongJmp function, but this time we get into the else.
	if( RestorePointDefined() == Defined )
	{
		// 2. We call the function that will return to the if.
		LongJmp( if );
	}
	else
	{
		// 5. Call the real function, our true target.
		CallTheUsefulFunction();
	}

	// 6. End of execution.
	return 0;
}