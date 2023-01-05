#include <iostream>
#include <array>
#include <vector>
int *allocateArray(int size)
{
    return new int[size];
}

int main1()
{
    int *array{allocateArray(25)};

    // do stuff with array

    delete[] array;
    return 0;
}

// Returns a reference to the index element of array
int &getElement(std::array<int, 25> &array, int index)
{
    // we know that array[index] will not be destroyed when we return to the caller (since the caller passed in the array in the first place!)
    // so it's okay to return it by reference
    return array[index];
}

int main2()
{
    std::array<int, 25> array;

    // Set the element of array with index 10 to the value 5
    getElement(array, 10) = 5;

    std::cout << array[10] << '\n';
    return 0;
}

#include <tuple>
#include <iostream>

inline std::tuple<int, double, int> returnTuple() // return a tuple that contains an int and a double
{
    return {5, 6.7, 6};
}
int main()
{
    std::tuple s{returnTuple()};                                                           // get our tuple
    std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << ' ' << std::get<2>(s) << '\n'; // use std::get<n> to get the nth element of the tuple
    // int a;
    // double b;
    // int c;
    // std::tie(a, b, c) = returnTuple();
    auto [a, b, c]{returnTuple()}; //C++ 17
    return 0;
}

int sunTo(const int x);
struct Employee
{
    int a;
};

void printEmployeeName(const Employee &employee);

std::pair<int, int> minmax(const int x, const int y);

int getIndexOfLargestValue(std::vector<int> &ve);

const std::string& getElement(const std::vector<std::string>& array,const int x );