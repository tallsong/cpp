#include <iostream>
int doubleNumber(int x)
{
    return 2*x;
}
int main()
{
    int x{};
    std::cin>>x;
    std::cout<<doubleNumber(x)<<'\n';
    return 0;
}