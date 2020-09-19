#define __STDC_WANT_LIB_EXT1__ 1
#include <cstring> // for strcpy_s
#include <iostream>
#include <iterator> // for std::size

void getCStyleString()
{
    char name[255]; // declare array large enough to hold 255 characters
    std::cout << "Enter your name: ";
    std::cin.getline(name, std::size(name));
    //This call to cin.getline() will read up to 254 characters into name (leaving room for the null terminator!). Any excess characters will be discarded. In this way, we guarantee that we will not overflow the array!
    std::cin.ignore(32767, '\n');
    std::cout << "You entered: " << name << '\n';
}

int main()
{
    char myString[]{"string"};
    const int length{static_cast<int>(std::size(myString))};
    //  const int length{ sizeof(myString) / sizeof(myString[0]) }; // use instead if not C++17 capable
    std::cout << myString << " has " << length << " characters.\n";
    for (int index{0}; index < length; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';
    std::cout << '\n';
    std::cout << myString;
    getCStyleString();

    char source[]{"Copy this!"};
    std::cout << source << " has " << std::strlen(source) << " letters.\n";

    return 0;
    return 0;
}