#include <iostream>
#include <stdexcept>
 
int main()
{
	try
	{
		throw std::runtime_error("Bad things happened");
	}
	// This handler will catch std::exception and all the derived exceptions too
	catch (const std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}
 
	return 0;
}