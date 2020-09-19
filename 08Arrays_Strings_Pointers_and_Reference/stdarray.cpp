
#include <algorithm> // for std::sort
#include <array>
#include <iostream>
 
int main1()
{
    std::array myArray { 7, 3, 1, 9, 5 };
    std::sort(myArray.begin(), myArray.end()); // sort the array forwards
//  std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards
 
    for (int element : myArray)
        std::cout << element << ' ';
 
    std::cout << '\n';
 
    return 0;
}


int main2()
{
    std::array myArray { 7, 3, 1, 9, 5 };
 
    // std::array<int, 5>::size_type is the return type of size()!
    for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
 
    std::cout << '\n';
 
    return 0;
}


#include <array>
#include <iostream>
 
int main3()
{
    std::array myArray { 7, 3, 1, 9, 5 };
 
    for (std::size_t i{ 0 }; i < myArray.size(); ++i)
        std::cout << myArray[i] << ' ';
 
    std::cout << '\n';
 
    return 0;
}

int main4()
{
    std::array myArray { 7, 3, 1, 9, 5 };
 
    // Print the array in reverse order.
    for (auto i{ myArray.size() }; i-- > 0; )
        std::cout << myArray[i] << ' ';
 
    std::cout << '\n';
 
    return 0;
}

 
struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};
 
struct Array
{
    House value[3]{};
};
 
int main()
{
    // With braces, this works.
    Array houses{
        { { 13, 4, 30 }, { 14, 3, 10 }, { 15, 3, 40 } }
    };
 
    for (const auto& house : houses.value)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }
 
    return 0;
}