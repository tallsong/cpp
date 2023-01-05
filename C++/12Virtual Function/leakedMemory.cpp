#include <iostream>
 
class Base
{
protected:
	int m_value;
 
public:
	Base(int value)
		: m_value{value}
	{
	}
 
	virtual const char* getName() { return "Base"; }
};
 
class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{
	}
 
	virtual const char* getName() { return "Derived"; }
};
 
int main()
{
	auto *d{ new Derived(5) };
	Base *b{ d };
	std::cout << b->getName() << '\n';
	delete b;
 
	return 0;
}