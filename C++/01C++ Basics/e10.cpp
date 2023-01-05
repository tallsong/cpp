#include <iostream>
#define ENABLE_DEBUG
int getValue()
{
#ifdef ENABLE_DEBUG
std::cerr << "getValue() called\n";
#endif
    return 4;
}

int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n";
#endif
    std::cout << getValue();

    return 0;
}