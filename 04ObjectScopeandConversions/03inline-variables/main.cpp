#include "constants.h"
 
#include <iostream>
 
int main()
{
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;
 
    std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
 
    return 0;
}