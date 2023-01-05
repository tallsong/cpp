#include <iostream>
#include <cstring>

template <class T, int size> // size is the expression parameter
class StaticArray
{
private:
    // The expression parameter controls the size of the array
    T m_array[size]{};

public:
    T *getArray() { return m_array; }

    T &operator[](int index)
    {
        return m_array[index];
    }
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
    for (int count{0}; count < size; ++count)
        std::cout << array[count] << ' ';
}

// overload of print() function for partially specialized StaticArray<char, size>
template <int size>
void print(StaticArray<char, size> &array)
{
    for (int count{0}; count < size; ++count)
        std::cout << array[count];
}

int main()
{
    // Declare an char array of size 14
    StaticArray<char, 14> char14{};

    std::strcpy(char14.getArray(), "Hello, world!");

    // Print the array
    print(char14);

    // Now declare an char array of size 12
    StaticArray<char, 12> char12{};

    std::strcpy(char12.getArray(), "Hello, mom!");

    // Print the array
    print(char12);
    StaticArray<int, 4> int4{};
    int4[0] = 0;
    int4[1] = 1;
    int4[2] = 2;
    int4[3] = 3;

    // Print the array
    print(int4);

    return 0;
}