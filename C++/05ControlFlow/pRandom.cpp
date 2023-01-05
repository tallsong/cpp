#include<iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include <random> // for std::mt19937
unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed{ 5323 };
 
    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // hard for someone to casually predict what the next number is
    // going to be from the previous one.
    seed = 8253729 * seed + 2396403;
 
    // Take the seed and return a value between 0 and 32767
    return seed % 32768;
}
 
int main1()
{
    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << PRNG() << '\t';
 
        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }
 
    return 0;
}

int main2()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
 
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';
 
        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
	}
 
    return 0;
}


int main()//Mersenne Twister
{
	// Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die{ 1, 6 };
	// If your compiler doesn't support C++17, use this instead
	// std::uniform_int_distribution<> die{ 1, 6 };
 
	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 48; ++count)
	{
		std::cout << die(mersenne) << '\t'; // generate a roll of the die here
 
		// If we've printed 6 numbers, start a new row
		if (count % 6 == 0)
			std::cout << '\n';
	}
 
	return 0;
}