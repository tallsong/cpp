#include <iostream>

int getInputInterget()
{
    int input{};
    std::cin>>input;
    return input;
}

int main()
{
    int x{getInputInterget()};
    int y{getInputInterget()};
    std::cout<<x+y<<'\n';
    return 0;
}