#include <iostream>
#include <iterator>
namespace StudentNames
{
    enum StudentNames
    {
        kenny,       // 0
        kyle,        // 1
        stan,        // 2
        butters,     // 3
        cartman,     // 4
        wendy,       // 5
        max_students // 6
    };
}
int main()
{
    // int length{};
    // std::cin >> length;
    // int array[length]; // Not ok -- length is not a compile-time constant!

    // // using a runtime const variable
    // int temp{5};
    // const int length{temp}; // the value of length isn't known until runtime, so this is a runtime constant, not a compile-time constant!
    // int array[length]{};    // Not ok
    constexpr int length{5};
    int array[length]{5};
    int array2[]{0, 1, 2, 3, 4};
    std::cout << array[0] << array2[0] << '\n';

    int testScores[StudentNames::max_students]{}; // allocate 6 integers
    testScores[StudentNames::stan] = 76;
    std::cout << "size of testScores is " << std::size(testScores)<<'\n';

    int prime[5]{}; // hold the first 5 prime numbers
    prime[5] = 13;
    std::cout<<prime[5];
    return 0;
}