#include <iostream>
#include <functional>
 
int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}
 
char getOperation()
{
    char op{};
 
    do
    {   
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');
 
    return op;
}
 
int add(int x, int y)
{
    return x + y;
}
 
int subtract(int x, int y)
{
    return x - y;
}
 
int multiply(int x, int y)
{
    return x * y;
}
 
int divide(int x, int y)
{
    return x / y;
}


// type alias named arithmeticFcn for a pointer to a function that takes two integer parameters and returns an integer. 
using arithmeticFcn = std::function<int(int, int)>;   
 
arithmeticFcn getArithmeticFcn(char op)
{
	switch (op)
	{
	default: // default will be to add
	case '+': return add;
	case '-': return subtract;
	case '*': return multiply;
	case '/': return divide;
	}
}
 

int foo() // code starts at memory address 0x002717f0
{
    return 5;
}
 
int main1()
{
    std::cout << foo << '\n'; // we meant to call foo(), but instead we're printing foo itself!
    std::cout << reinterpret_cast<void*>(foo) << '\n'; // Tell C++ to interpret function foo as a void pointer
    return 0;
}


int main()
{
    int x{ getInteger() };
    char op{ getOperation() };
    int y{ getInteger() };
 
    arithmeticFcn fcn{ getArithmeticFcn(op) };
    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
    main1();
    return 0;
}