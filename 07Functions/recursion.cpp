#include <iostream>
#include <vector>
 
int fibonacci(int count)
{
	// We'll use a static std::vector to cache calculated results
	static std::vector<int> results{ 0, 1 };
 
	// If we've already seen this count, then use the cache'd result
	if (count < static_cast<int>(std::size(results)))
		return results[count];
	else
	{
		// Otherwise calculate the new result and add it
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}
int factorial(int n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n-1);
	}
	
}

int sumNumbers(int n)
{
	if(n<10)
	{
		return n; 
	}
	else
	{
		return n%10+sumNumbers(n/10);
	}
	
}


void printBinary(int x)
{
	if(x<2)
	{
		std::cout<<x;
	}
	else
	{
		printBinary(x/2);
		std::cout<<x%2;
	}
	
}


int main()
{
	printBinary(256);
	return 0;
}