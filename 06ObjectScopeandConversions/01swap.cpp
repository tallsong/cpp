#include<iostream>

int getInput()
{
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    std::cout<<"Enter an integer: ";
    int x{getInput()};
    std::cout<<"Enter a larger integer: ";
    int y{getInput()};
    std::cout<<"Swapping the value\n";
    int tmp{};
    if(x>y)
        std::swap(x,y);
    std::cout<<"The small value is "<<x<<'\n';
    std::cout<<"The larger value is "<<y;
    return 0;
}