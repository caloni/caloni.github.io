/** @brief A stupid sample for show WinDbg COM hooking!
* @author Wanderley Caloni (wanderley@caloni.com.br)
*/
#include <windows.h>
#include <objbase.h>
#include <objidl.h>
 
int main()
{
	CoInitialize(NULL); // initialize the COM library

	IMalloc* malloc = 0; //IMalloc interface pointer

	// if we get the interface...
	if( SUCCEEDED(CoGetMalloc(1, &malloc)) )
	{
		// allocate 4KB (use your HP hyper-plus to make the necessary reckons)
		if( void* pAlloc = malloc->Alloc(0x1000) )
		{
			malloc->Free(pAlloc); // everthing allocated, must be released =)
		}

		malloc->Release(); // decrement the reference counter for the COM object we created
	}

	CoUninitialize(); // we don't need the COM library anymore
}