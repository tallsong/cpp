#include <iostream>
#include <cstddef>
#include <string>
#include <algorithm>
#include <limits> // std::numeric_limits
int main1()
{
    int *ptr{new int{56}};
    *ptr = 87; //heap
    int p{87}; //stack
    std::cout << &p << '\n'
              << ptr;
    return 0;
}
int main2()
{
    int *ptr{new int}; // dynamically allocate an integer
    *ptr = 7;          // put a value in that memory location

    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

    std::cout << *ptr; // Dereferencing a dangling pointer will cause undefined behavior
    delete ptr;        // trying to deallocate the memory again will also lead to undefined behavior.

    return 0;
}
void doSomething()
{
    int *ptr{new int{}};
    ptr = nullptr; //mewmory leak
}

int main3()
{
    std::size_t length{};
    std::cin >> length;
    int *array{new int[length]{}};
    array[0] = 7;
    delete[] array;
    std::string *arraybak{new std::string{"dfhdjk djkfsd"}};
    return 0;
}

std::size_t getInput()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length{};
    std::cin >> length;

    return length;
}

int main()
{

    std::size_t length{getInput()};
    std::string *array{new std::string[length]{}};
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (std::size_t index{0}; index < length; ++index)
    {
        
        std::cout << "Enter name #" << index + 1 << ": ";
        std::getline(std::cin, array[index]);
    }
    std::sort(array, array + length);
    for (std::size_t index{0}; index < length; ++index)
    {
        std::cout << array[index]<<'\t';
    }
    return 0;
}