#include <iostream>
class Base
{
public:
	Base() {}
 
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream &out, const Base &b)
	{
		// Delegate printing responsibility for printing to member function print()
		return b.print(out);
	}
 
	// We'll rely on member function print() to do the actual printing
	// Because print is a normal member function, it can be virtualized
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};
 
class Derived : public Base
{
public:
	Derived() {}
 
	// Here's our override print function to handle the Derived case
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};
 
int main()
{
	Base b;
	std::cout << b << '\n';
 
	Derived d;
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects
 
	Base &bref = d;
	std::cout << bref << '\n';
 
	return 0;
}