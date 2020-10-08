#include <iostream>

class Cal
{
private:
    int m_value;

public:
    Cal(int value = 0) : m_value{value} {}
    Cal &add(int value)
    {
        m_value += value;
        return *this;
    }
    Cal &sub(int value)
    {
        m_value -= value;
        return *this;
    }
    int getValue() { return m_value; };
};

int main()
{
    Cal cal(5);
    std::cout << cal.add(12).sub(9).getValue();
}
