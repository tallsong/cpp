#include<iostream>
//Using g++, you can use the -I option to specify an alternate include directory.
//g++ -o main -I/source/includes main.cpp
#define DEBUG
#define FOO 9 // Here's a macro substitution
int main()
{
    #ifdef DEBUG
    std::cout<<"bug~~~";
    #endif
    #ifndef DEBUG
    std::cout<<"fuck";
    #endif

    #if 0  //This provides a convenient way to “comment out” code that contains multi-line comments.
    int void();
    #endif

    #ifdef FOO // This FOO does not get replaced because it’s part of another preprocessor directive
    std::cout << FOO; // This FOO gets replaced with 9 because it's part of the normal code
    #endif
    return 0;
}