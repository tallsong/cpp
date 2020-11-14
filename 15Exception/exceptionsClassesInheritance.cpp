#include <iostream>
#include <string>

class ArrayException
{
private:
    std::string m_error;

public:
    ArrayException(std::string error)
        : m_error(error)
    {
    }

    const char *getError() const { return m_error.c_str(); }
};

class IntArray
{
private:
    int m_data[3]; // assume array is length 3 for simplicity
public:
    IntArray() {}

    int getLength() const { return 3; }

    int &operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayException("Invalid index");

        return m_data[index];
    }
};

int main()
{
    IntArray array;

    try
    {
        int value{array[5]};
    }
    catch (const ArrayException &exception) //since ArrayException is its own unique type, we can specifically catch exceptions thrown by the array class
                                            //and treat them differently from other exceptions if we wish.
    {
        std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
    }
}