#include <iostream>

/*
class Base
{
public:
	int m_value;
};
 
class Derived : public Base
{
private:
	using Base::m_value;
 
public:
	Derived(int value)
	// We can't initialize m_value, since it's a Base member (Base must initialize it)
	{
		// But we can assign it a value
		m_value = value;
	}
};
 
int main()
{
	Derived derived(7);
 
	// The following won't work because m_value has been redefined as private
	std::cout << derived.m_value;


    
	// We can still access the function deleted in the Derived class through the Base class
	std::cout << static_cast<Base>(derived).getValue();
 
	return 0;
}

*/


/*
#include <iostream>
class Base
{
private:
	int m_value;
 
public:
	Base(int value)
		: m_value(value)
	{
	}
 
	int getValue() { return m_value; }
};
 
class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}
 
 
	int getValue() = delete; // mark this function as inaccessible
};
 
int main()
{
	Derived derived(7);
 
	// The following won't work because getValue() has been deleted!
	std::cout << derived.getValue();
 
	return 0;
}
 */