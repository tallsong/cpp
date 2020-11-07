#ifndef ARRAY_H
#define ARRAY_H
 
#include <cassert>
 
template <class T>
class Array
{
private:
    int m_length{};
    T *m_data{};
 
public:
 
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }
 
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
 
    ~Array()
    {
        delete[] m_data;
    }
 
    void Erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }
 
    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
 
    // templated getLength() function defined below
    int getLength() const; 
};
 
// member functions defined outside the class need their own template declaration
template <class T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
  return m_length;
}
 
#endif