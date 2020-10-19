#include <iostream>

class Point
{
private:
    int m_x;
    int m_y;
    int m_z;

public:
    Point(int x = 0, int y = 0, int z = 0) : m_x{x}, m_y{y}, m_z{z} {}
    friend std::ostream &operator<<(std::ostream &out, const Point &p);
    friend std::istream &operator>>(std::istream &in, Point &point);
};
std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &point)

{
    in >> point.m_x>>point.m_y>>point.m_z;
    return in;
}




class Fraction
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator(numerator), m_denominator(denominator)
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}
 
	// We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
 
	void reduce()
	{
		if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd = Fraction::gcd(m_numerator, m_denominator);
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
 
	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
    friend std::ostream& operator<<(std::ostream &out,const Fraction & fraction);
    friend std::istream& operator>>(std::istream &in,Fraction & fraction);
	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};
 
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
 
Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}
 
Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}
std::ostream& operator<<(std::ostream &out,const Fraction & fraction)
{
    out<<fraction.m_numerator<<'/'<<fraction.m_denominator;
    return out;
}
std::istream &operator>>(std::istream &in, Fraction &f1)
{
    // Overwrite the values of f1
    in >> f1.m_numerator;

    // Ignore the '/' separator
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

    in >> f1.m_denominator;

    // Since we overwrite the existing f1, we need to reduce again
    f1.reduce();
    return in;
}
int main()
{
    Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
    Point point1(2.0, 3.5, 4.0);
    Point point2(6.0, 7.5, 8.0);
    Point point3;
    std::cin>>point3;
    std::cout << point1 << " " << point2 <<point3<<" "<< '\n';
 
    return 0;
}