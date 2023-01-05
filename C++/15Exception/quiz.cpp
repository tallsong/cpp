#include <iostream>
#include <stdexcept> // for std::runtime_error
 
class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		if (m_denominator == 0)
			throw std::runtime_error("Invalid denominator");
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Fraction &f1);
 
};
 
std::ostream& operator<<(std::ostream &out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}
 
int main()
{
	std::cout << "Enter the numerator: ";
	int numerator;
	std::cin >> numerator;
 
	std::cout << "Enter the denominator: ";
	int denominator;
	std::cin >> denominator;
 
	try
	{
		Fraction f(numerator, denominator);
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
 
	return 0;
}