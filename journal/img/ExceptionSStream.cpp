#include <sstream>
#include <exception>
#include <iostream>

using namespace std;

void LogError(const char* msg)
{
    cerr << "** " << msg << endl;
}


void func()
{
    //doSomething();
    throw exception("sbrubles exception");
}


int main()
{
    try
    {
        func();
    }
    catch(exception& e)
    {
        stringstream ss;
        ss << "Error calling func: " << e.what() << endl;
        const char* errorMessage = ss.str().c_str();
        LogError(errorMessage);
    }
}
