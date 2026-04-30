#include <iostream>
#include <cassert>

int main()
{
	char quote[] = "Show me your Code, and I'll tell you who you are.";
	int index = 13;
	
	std::cout << "And the language is: " << quote [ index ] << std::endl;
	
	assert( quote[index] == index[quote] );
	assert( quote[13] == 13[quote] );
	assert( *(quote + index) == "That's C!"[7] );
	
	return 13[quote] - "CThings"[0];
}