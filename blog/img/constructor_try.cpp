#include <iostream>


/* This class explodes */
class Explode
{
	public:
		Explode(int x) 
		{
			m_x = x;
			throw x;
		}

		void print()
		{
			std::cout << "The number: " << m_x << std::endl;
		}

	private:
		int m_x;
};


/* This class is going to be exploded */
class Victim
{
	public:
		Victim() try : m_explode(5)
		{
			std::cout << "You're supposed to NOT seeing this...\n";
		}
		catch(...) 
		{ 
			std::cerr << "Something BAD hapenned\n";
			std::cerr << "We're going to blow up\n";
			// just like 'throw' over here
		}

		void print()
		{
			m_explode.print();
		}

	private:
		Explode m_explode;
};


int main()
{
	try
	{
		Victim vic;
	}
	catch(...)
	{
		std::cerr << "Something BAD BAD happenned...\n";
	}
}

