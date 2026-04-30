void DebugLoop()
{
	bool exitLoop = false;

	while( ! exitLoop )
	{
		DEBUG_EVENT debugEvt;

		// Wait for some debug event.
		WaitForDebugEvent(&debugEvt, INFINITE);

		// Let us see what it is about.
		switch( debugEvt.dwDebugEventCode )
		{
			// This one...

			// That one...

			// Process is going out. We get out the loop and go away.
			case EXIT_PROCESS_DEBUG_EVENT:
			exitLoop = true;
			break;
		}

		// We need to unfreeze the thread who sent the debug event.
		// Otherwise, it stays frozen forever!
		ContinueDebugEvent(debugEvt.dwProcessId, debugEvt.dwThreadId, DBG_EXCEPTION_NOT_HANDLED);
	}
}