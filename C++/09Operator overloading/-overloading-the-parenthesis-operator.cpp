#include <cassert> // for assert()
#include <string>
#include <iostream>
class Matrix
{
private:
    double m_data[4][4]{};

public:
    double &operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};

double &Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int row{0}; row < 4; ++row)
    {
        for (int col{0}; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

class Mystring
{
private:
    std::string m_string{};

public:
    Mystring(const std::string &string = "") : m_string{string} {}
    std::string operator()(const int start, const int length);
};

std::string Mystring::operator()(const int start, const int length)
{
    assert(start >= 0);
    assert(start + length <= static_cast<int>(m_string.length()) && "Mystring::operator(int, int): Substring is out of range");

    std::string ret{};
    for (int count{0}; count < length; ++count)
    {
        ret += m_string[static_cast<std::string::size_type>(start + count)];
    }

    return ret;
}

int main()
{
    Mystring string{"Hello, world!"};
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}