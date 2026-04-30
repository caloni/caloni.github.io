#ifdef NDEBUG

#define MYTRACE( message ) /* nothing */

#else

#define MYTRACE( message )        \
	do                             \
	{                              \
		char buffer[500];           \
		sprintf(buffer,             \
			"MYTRACE: %s(%d) %s\n",  \
			__FILE__,                \
			__LINE__,                \
			message);                \
		printf(buffer);             \
	}                              \
	while( 0 )

#endif /* NDEBUG */