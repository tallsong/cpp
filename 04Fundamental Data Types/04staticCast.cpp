#include<iostream>

int main()
{
    char ch{'a'};
    std::cout<<ch<<'\n';
    std::cout<<static_cast<int>(ch)<<'\n';
    std::cout<<ch<<'\n';  
    std::cout<<static_cast<int>(45)<<'\n'; 
    return 0;
}