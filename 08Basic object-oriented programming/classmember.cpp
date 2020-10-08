#include <iostream>
#include <vector>
class Calculator
{
public:
    using number_t = int;
    std::vector<number_t> m_resultHistory{};

    number_t add(number_t a, number_t b)
    {
        m_resultHistory.push_back(a + b);
        return a + b;
    }
};

class IntPair
{
public:
    int m_var1{};
    int m_var2{};

    void set(const int x, const int y)
    {
        m_var1 = x;
        m_var2 = y;
    }
    void print()
    {
        std::cout << m_var1 << "   " <<m_var2<<'\n';
    }
};

int Calculator_text()
{
    Calculator calculator{};
    std::cout << calculator.add(3, 5);
    std::cout << calculator.add(3, 454) << '\n';

    for (Calculator::number_t num : calculator.m_resultHistory)
    {
        std::cout << num;
    }
    return 0;
}

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)
	
	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)
 
	p1.print();
	p2.print();
 
	return 0;
}