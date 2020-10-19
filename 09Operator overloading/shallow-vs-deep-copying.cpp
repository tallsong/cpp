#include <cstring> // for strlen()
#include <cassert> // for assert()
 
class MyString
{
private:
    char *m_data{};
    int m_length{};
 
public:
MyString& operator=(const MyString & source);
MyString(const MyString& source);
    MyString(const char *source="")
    {
        assert(source); // make sure source isn't a null string
 
        // Find the length of the string
        // Plus one character for a terminator
        m_length = std::strlen(source) + 1;
        
        // Allocate a buffer equal to this length
        m_data = new char[m_length];
        
        // Copy the parameter string into our internal buffer
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source[i];
    
        // Make sure the string is terminated
        m_data[m_length-1] = '\0';
    }
    void deepCopy(const MyString& source);
    ~MyString() // destructor
    {
        // We need to deallocate our string
        delete[] m_data;
    }
 
    char* getString() { return m_data; }
    int getLength() { return m_length; }
};


// assumes m_data is initialized
void MyString::deepCopy(const MyString& source)
{
    // first we need to deallocate any value that this string is holding!
    delete[] m_data;
 
    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;
 
    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[m_length];
 
        // do the copy
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = nullptr;
}
 
// Copy constructor
MyString::MyString(const MyString& source)
{
    deepCopy(source);
}




// Assignment operator
MyString& MyString::operator=(const MyString & source)
{
    // check for self-assignment
    if (this != &source)
    {
        // now do the deep copy
        deepCopy(source);
    }
 
    return *this;
}
int main()
{
    return 0;
}