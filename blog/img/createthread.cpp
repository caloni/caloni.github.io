void StartBruteForceThread()
{
	g_bruteForceContinue = TRUE;
	g_bruteForceThread = CreateThread(NULL, 0, BruteForceThread, NULL, 
		0, &g_bruteForceThreadId);
}