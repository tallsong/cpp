#include<iostream>
void isEqual()
{
    std::cout<<"Enter a integer: ";
    int x{};
    std::cin>>x;
    std::cout<<"Enter another integer: ";
    int y{};
    std::cin>>y;
    std::cout<<x<<" and "<<y<<" is equal?";
    std::cout<<std::boolalpha<<'\t';
    std::cout<<(x==y)<<'\n';
    std::cout<<std::noboolalpha;
}

int main()
{
    bool mybool{};//default flase
    if(!mybool)
    {
        std::cout<<"fuck!"<<'\n';
    }
    std::cout<<true<<"\n";
    std::cout<<std::boolalpha;
    std::cout<<true<<"\n";
    std::cout<<std::noboolalpha;
    std::cout<<true<<"\n";
    isEqual();
    return 0;
}