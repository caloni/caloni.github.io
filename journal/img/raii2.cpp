void BlowUpFunction()
{
	// the things are not that good. so...
	throw Scatadush();
}

int UseFileEx()
{
	File config("config.txt"); // local object: aquired resource

	// using config.txt
	BlowUpFunction(); // an exception is thrown: config.txt is automagically released
	// using config.txt

	return 0; // the aquired resource  (config.txt) is released automagically
}