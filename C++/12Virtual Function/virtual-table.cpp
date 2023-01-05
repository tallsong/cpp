#include<iostream>
class Base
{
public:
    virtual void function1() {std::cout<<"B:f1\n";};
    virtual void function2() {std::cout<<"B:f2\n";};
};
 
class D1: public Base
{
public:
    virtual void function1() {std::cout<<"D1:f1\n";};
};
 
class D2: public Base
{
public:
    virtual void function2() {std::cout<<"D2:f2\n";};
};

int main()
{
    Base b;
    Base *bPtr = &b;
    bPtr->function1();
 
    return 0;
}