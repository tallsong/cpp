#include<iostream>

bool isEven(int x)
{
    return (x%2)==0;
}

int main2()
{
    std::cout<<"Enter an integer: ";
    int x{};
    std::cin>>x;
    if(isEven(x))
        std::cout<<x<<" is even";
    else
        std::cout<<x<<" is odd";
    return 0;
}


int main()
{
    int x{ 1 };
    int y{ 2 };
    double z{ 0.1+0.1+0.1 }; 
    if(z == 0.3)
       std::cout << (++x, ++y); // increment x and y, evaluates to the right operand
    else
    {
        std::cerr<<z<<'\n';
        std::cout<<"0.1 + 0.1 + 0.1 != 0.3";
    }
    
 
    return 0;
}