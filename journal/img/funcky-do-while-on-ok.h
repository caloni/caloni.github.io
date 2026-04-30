if( exploded() )
	do
	{
		char buffer[500];
		sprintf(buffer,
			"MYTRACE: %s(%d) %s\n",
			__FILE__,
			__LINE__,
			"Oh, my God");
		OutputDebugString(buffer);
	}
	while( 0 );
else
	do
	{
		char buffer[500];
		sprintf(buffer,
			"MYTRACE: %s(%d) %s\n",
			__FILE__,
			__LINE__,
			"That's right");
		OutputDebugString(buffer);
	}
	while( 0 );
