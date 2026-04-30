#ifdef NDEBUG

#define MYTRACE( message ) /* nothing */

#else

#define MYTRACE( message )        \
	{                              \
		char buffer[500];           \
		sprintf(buffer,             \
			"MYTRACE: %s(%d) %s\n",  \
			__FILE__,                \
			__LINE__,                \
			message);                \
		OutputDebugString(buffer);  \
	}

#endif /* NDEBUG */