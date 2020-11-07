#include<iostream>
template <class T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
    {
         m_value = value;
    }
 
    ~Storage()
    {
    }
 
    void print()
    {
        std::cout << m_value << '\n';
    }
};
template <>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}
template <>
Storage<char*>::Storage(char* value)
{
    // Figure out how long the string in value is
    int length=0;
    while (value[length] != '\0')
        ++length;
    ++length; // +1 to account for null terminator
 
    // Allocate memory to hold the value string
    m_value = new char[length];
 
    // Copy the actual value string into the m_value memory we just allocated
    for (int count=0; count < length; ++count)
        m_value[count] = value[count];
}
template <>
Storage<char*>::~Storage()
{
    delete[] m_value;
}
//Although the above examples have all used member functions, you can also specialize non-member template functions in the same way.
int main()
{
    // Dynamically allocate a temporary string
    char *string = new char[40];
 
    // Ask user for their name
    std::cout << "Enter your name: ";
    std::cin >> string;
 
    // Store the name
    Storage<char*> storage(string);
 
    // Delete the temporary string
    delete[] string;
 
    // Print out our value
    storage.print(); // This will print garbage
}