#include <iostream>
 
class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
	}
};
 
class B : public A
{
public:
	B(int x) try : A(x) // note addition of try keyword here
	{
		if (x <= 0) // moved this from A to B
			throw 1; // and this too
	}
	catch (...)
	{
                std::cerr << "Exception caught\n";
 
                // If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
	}
};
 
int main()
{
	try
	{
		B b(0);
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}