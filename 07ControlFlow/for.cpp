#include<iostream>


int sumTo(int x)
{
    int res{};
    for(int i=1;i<=x;++i)
    {
        res+=i;
    }
    return res;
}

int main()
{
    for(int i=0;i<=20;i+=2)
    {
        std::cout<<i<<'\t';
    }
    std::cout<<sumTo(5);
    char ch{};
    std::cout<<"~~"<<ch<<'~'<<'\n';
    return 0;
}