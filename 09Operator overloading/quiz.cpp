#include <cstdint>
#include <iostream>
#include <cassert>
#include <cmath>
class Average
{
private:
    std::int_least32_t m_total;
    std::int_least8_t m_numbers;

public:
    Average(std::int_least32_t sum = 0, std::int_least8_t numbers = 0)
        : m_total{sum}, m_numbers{numbers}
    {
    }
    Average &operator+=(const int x);
    friend std::ostream &operator<<(std::ostream &out, const Average &average);
};

Average &Average::operator+=(const int x)
{
    m_total += x;
    ++m_numbers;
    return *this;
}
std::ostream &operator<<(std::ostream &out, const Average &average)
{
    out << (static_cast<double>(average.m_total) / average.m_numbers);
    return out;
}

class IntArray
{
private:
    int m_length{0};
    int *m_array{nullptr};

public:
    IntArray(int length) : m_length{length}
    {
        assert(m_length > 0);
        m_array = new int[m_length]{};
    }
    IntArray(const IntArray &intArray) : m_length{intArray.m_length}
    {
        m_array = new int[m_length];
        for (int count{0}; count < m_length; ++count)
        {
            m_array[count] = intArray.m_array[count];
        }
    }
    ~IntArray()
    {
        delete m_array;
    }
    friend std::ostream &operator<<(std::ostream &out, const IntArray &intArray);
    int &operator[](const int index);
    IntArray &operator=(const IntArray &intArray);
};

std::ostream &operator<<(std::ostream &out, const IntArray &intArray)
{
    for (int i{0}; i < intArray.m_length; ++i)
    {
        out << intArray.m_array[i] << '\t';
    }
    return out;
}
int &IntArray::operator[](const int index)
{
    assert(index >= 0);
    assert(index < m_length);
    return m_array[index];
}
IntArray &IntArray::operator=(const IntArray &intArray)
{
    // self-assignment guard
    if (this == &intArray)
        return *this;
    delete m_array;
    m_length = intArray.m_length;
    m_array = new int[m_length];
    for (int count{0}; count < m_length; ++count)
    {
        m_array[count] = intArray.m_array[count];
    }
    return *this;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

class FixedPoint2
{
private:
    std::int_least16_t m_base{};   // here's our non-fractional part
    std::int_least8_t m_decimal{}; // here's our factional part

public:
    FixedPoint2(std::int_least16_t base = 0, std::int_least8_t decimal = 0)
        : m_base{base}, m_decimal{decimal}
    {
        // We should handle the case where decimal is > 99 or < -99 here
        // but will leave as an exercise for the reader

        // If either the base or decimal or negative
        if (m_base < 0 || m_decimal < 0)
        {
            // Make sure base is negative
            if (m_base > 0)
                m_base = -m_base;
            // Make sure decimal is negative
            if (m_decimal > 0)
                m_decimal = -m_decimal;
        }
    }
    FixedPoint2(double d) : m_base{static_cast<int_least16_t>(d)},
                            // Now we need to get the fractional component:
                            // 1) d - static_cast<int_least16_t>(d) leaves only the fractional portion
                            // 2) which can we multiply by 100 to move the digits to the left of the decimal
                            // 3) then we can round this
                            // 4) and finally static cast to an integer to drop any extra decimals
                            m_decimal{static_cast<std::int_least8_t>(std::round((d - static_cast<int_least16_t>(d)) * 100))}
    {
    }
    operator double() const
    {
        return m_base + static_cast<double>(m_decimal) / 100.0;
    }
    friend bool operator== (const FixedPoint2 &fp1, const FixedPoint2 &fp2)
    {
        return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
    }
    FixedPoint2 operator-() const
	{
		return FixedPoint2(-m_base, -m_decimal);
	}
};

// This doesn't require access to the internals of the class, so it can be defined outside the class
std::ostream &operator<<(std::ostream &out, const FixedPoint2 &fp)
{
    out << static_cast<double>(fp);
    return out;
}

std::istream& operator >> (std::istream &in, FixedPoint2 &fp)
{
	double d{};
	in >> d;
	fp = FixedPoint2(d);
 
	return in;
}
FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
	return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
}

int main1()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{avg};
    std::cout << copy << '\n';

    IntArray a{fillArray()};
    std::cout << a << '\n';

    auto &ref{a}; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}

int main()
{
    FixedPoint2 a{0.01};
    std::cout << a << '\n';

    FixedPoint2 b{-0.01};
    std::cout << b << '\n';

    FixedPoint2 c{5.01}; // stored as 5.0099999... so we'll need to round this
    std::cout << c << '\n';

    FixedPoint2 d{-5.01}; // stored as -5.0099999... so we'll need to round this
    std::cout << d << '\n';

    return 0;
}