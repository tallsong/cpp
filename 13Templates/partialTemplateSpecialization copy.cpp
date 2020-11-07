#include <iostream>

template <class T, int size> // size is the expression parameter
class StaticArray_Base
{
protected:
    // The expression parameter controls the size of the array
    T m_array[size]{};

public:
    T *getArray() { return m_array; }

    T &operator[](int index)
    {
        return m_array[index];
    }

    void print()
    {
        for (int i{0}; i < size; ++i)
            std::cout << m_array[i];
        std::cout << '\n';
    }

    virtual ~StaticArray_Base() = default;
};

template <class T, int size> // size is the expression parameter
class StaticArray : public StaticArray_Base<T, size>
{
public:
};

template <int size> // size is the expression parameter
class StaticArray<double, size> : public StaticArray_Base<double, size>
{
public:
    void print()
    {
        for (int i{0}; i < size; ++i)
            std::cout << std::scientific << this->m_array[i] << ' ';
        // note: The this-> prefix in the above line is needed.
        // See https://stackoverflow.com/a/6592617 or https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members for more info on why.
        std::cout << '\n';
    }
};

int main()
{
    // declare an integer array with room for 6 integers
    StaticArray<int, 6> intArray{};

    // Fill it up in order, then print it
    for (int count{0}; count < 6; ++count)
        intArray[count] = count;

    intArray.print();

    // declare a double buffer with room for 4 doubles
    StaticArray<double, 4> doubleArray{};

    for (int count{0}; count < 4; ++count)
        doubleArray[count] = (4.0 + 0.1 * count);

    doubleArray.print();

    return 0;
}