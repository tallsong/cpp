#include <iostream>

double getNumber()
{
    std::cout << "Enter a double value" << '\n';
    double x{};
    std::cin >> x;
    return x;
}
char getSymbol()
{
    std::cout << "Enter one of the following: +, -, *, or /:" << '\n';
    char symbol{};
    std::cin >> symbol;
    return symbol;
}

void printCaculate(double x, double y, char symbol)
{
    if (symbol == '+')
        std::cout << x + y;
    else if (symbol == '-')
        std::cout << x - y;
    else if (symbol == '*')
        std::cout << x * y;
    else if (symbol == '/')
    {
        if(y!=0)
        {
            std::cout << x / y;
        }
    }
        
}

int main()
{
    double x{getNumber()};
    double y{getNumber()};
    char symbol{getSymbol()};
    printCaculate(x, y, symbol);

    return 0;
}