#include <iostream>

int add(int a, int b);

int main()
{
    std::cout << add(3, 5);
    return 0;
}
int add(int a, int b)
{
    return a + b;
}