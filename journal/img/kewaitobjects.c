//...
	processorCount = 0;
	processorsMask = KeQueryActiveProcessors();
	processorsMaskAux = processorsMask;

	while( processorsMaskAux )
	{
		if( processorsMaskAux & 1 )
			processorCount++;

		processorsMaskAux >>= 1;
	}

//...

	KeWaitForMultipleObjects(processorCount, waitObjects, WaitAll, 
		UserRequest, KernelMode, TRUE, NULL, NULL);

	ExFreePool(dpcVect);
	ExFreePool(eventVect);
	ExFreePool(waitObjects);
//...