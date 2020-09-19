#include <string>
#include <iostream>

struct A
{
    std::string bat;
};

struct B
{
    A a;
};

int main()
{
    B b{{"fuck"}};
    B *bptr{&b};
    std::cout << bptr->a.bat;
}
