#include <cassert>
#include <iostream>
 
class Fraction
{
private:
    int m_numerator;
    int m_denominator;
 
public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }
 
    // Copy constructor
    Fraction(const Fraction &fraction) :
        m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
        // Note: We can access the members of parameter fraction directly, because we're inside the Fraction class
    {
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }
 
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};
 
std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}
 
int main()
{
	Fraction fiveThirds(5, 3); // Direct initialize a Fraction, calls Fraction(int, int) constructor
	Fraction fCopy(fiveThirds); // Direct initialize -- with Fraction copy constructor
    Fraction fiveThirds2(Fraction(5, 3));//  The compiler may change this to:Fraction fiveThirds2(5, 3);  
	std::cout << fCopy << '\n';
}