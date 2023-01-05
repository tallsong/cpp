#include <iostream>

void add(int x)
{
    int y{4};
    std::cout << x << '\t' << y;
    x = 3;
    std::cout << x << '\t' << y;
}

int main()
{
    int x{1};
    int y{2};                    // comment1
    std::cout << x << '\t' << y; //comment2
    add(x);
    std::cout << x << '\t' << y;
    std::cout << "Hello "
                 "world!";
    return 0;
}