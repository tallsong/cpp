#include<iostream>
#include<cmath>


int main()
{
    double x{ std::pow(3.0, 4.5) }; 
    std::cerr<<x<<'\n';
    std::cout<<static_cast<double>(x);
    return 0;
}