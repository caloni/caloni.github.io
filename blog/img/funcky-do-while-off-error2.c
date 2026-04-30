if( exploded() )
	{
		char buffer[500];
		sprintf(buffer,
			"MYTRACE: %s(%d) %s\n",
			__FILE__,
			__LINE__,
			"Oh, my God");
		OutputDebugString(buffer);
	};
else
	{
		char buffer[500];
		sprintf(buffer,
			"MYTRACE: %s(%d) %s\n",
			__FILE__,
			__LINE__,
			"That's right");
		OutputDebugString(buffer);
	};
