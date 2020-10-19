#include <iostream>
class Cents2;
class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) : m_cents{cents} {}

    // add Cents + Cents using a friend function
    friend Cents operator+(const Cents &c1, const Cents2 &c2);

    int getCents() const { return m_cents; }
};
class Cents2
{
private:
    int m_cents;

public:
    Cents2(int Cents) : m_cents{Cents} {}

    // add Cents2 + Cents2 using a friend function
    friend Cents operator+(const Cents &c1, const Cents2 &c2);

    int getCents2() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents2 &c2)
{
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents(c1.m_cents + c2.m_cents);
}

int Cents_test()
{
    Cents cents1{6};
    Cents2 cents2{8};
    Cents centsSum{cents1 + cents2};
    std::cout << "I have " << centsSum.getCents() << " cents.\n";

    return 0;
}

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    
    Fraction(int intger = 0, int fraction = 1) : m_numerator{intger}, m_denominator{fraction}
    {
        reduce();
    }
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
    void print() const
    {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }
    friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
    friend Fraction operator*(int x, const Fraction &fraction);
    friend Fraction operator*(const Fraction &fraction, int x);
    void reduce()
	{
		if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd{ Fraction::gcd(m_numerator, m_denominator) };
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
};
Fraction operator*(const Fraction &fraction1, const Fraction &fraction2)
{
    return Fraction{fraction1.m_numerator * fraction2.m_numerator, fraction2.m_denominator * fraction1.m_denominator};
}
Fraction operator*(int x, const Fraction &fraction)
{
    return Fraction{fraction.m_numerator * x, fraction.m_denominator};
}
Fraction operator*(const Fraction &fraction, int x)
{
    return Fraction{fraction.m_numerator * x, fraction.m_denominator};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();
 
    Fraction f2{3, 8};
    f2.print();
 
    Fraction f3{ f1 * f2 };
    f3.print();
 
    Fraction f4{ f1 * 2 };
    f4.print();
 
    Fraction f5{ 2 * f2 };
    f5.print();
 
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
 
    Fraction f7{0, 6};
    f7.print();
 
 
    return 0;
}