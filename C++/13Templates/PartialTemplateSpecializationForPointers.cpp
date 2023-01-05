// Here’s an example program that uses both partial specialization for pointers, and full specialization for char*:


#include <iostream>
#include <cstring>
 
// Our Storage class for non-pointers
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
 
// Partial-specialization of Storage class for pointers
template <class T>
class Storage<T*>
{
private:
	T* m_value;
public:
	Storage(T* value)
	{
		m_value = new T(*value);
	}
 
	~Storage()
	{
		delete m_value;
	}
 
	void print()
	{
		std::cout << *m_value << '\n';
	}
};
 
// Full specialization of constructor for type char*
template <>
Storage<char*>::Storage(char* value)
{
	// Figure out how long the string in value is
	int length = 0;
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator
 
	// Allocate memory to hold the value string
	m_value = new char[length];
 
	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}
 
// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}
 
// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first element
template<>
void Storage<char*>::print()
{
	std::cout << m_value;
}
 
int main()
{
	// Declare a non-pointer Storage to show it works
	Storage<int> myint(5);
	myint.print();
 
	// Declare a pointer Storage to show it works
	int x = 7;
	Storage<int*> myintptr(&x);
 
	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.print();
 
	// Dynamically allocate a temporary string
	char *name = new char[40]{ "Alex" }; // requires C++14
 
	// If your compiler isn't C++14 compatible, comment out the above line and uncomment these
//	char *name = new char[40];
//	strcpy(name, "Alex");
 
	// Store the name
	Storage< char*> myname(name);
 
	// Delete the temporary string
	delete[] name;
 
	// Print out our name
	myname.print();
}