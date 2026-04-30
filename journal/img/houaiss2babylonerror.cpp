void MessageError(DWORD err, PCSTR msg, ...)
{
	CHAR errBuffer[100];
	CHAR msgBuffer[ERR_STR_BUF_SIZE];
	va_list vaList;

	va_start(vaList, msg);
	vsprintf(msgBuffer, msg, vaList);
	va_end(vaList);

	sprintf(errBuffer, " Erro de sistema número %d.", (int) err);
	strcat(msgBuffer, errBuffer);

	MessageBox(NULL, msgBuffer, STR_PROJECT_NAME, MB_OK | MB_ICONERROR);
}

