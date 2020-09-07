#include<iostream>

int main0()
{
    enum class Color
    {
        red,
        blue
    };
    Color color{Color::red};
}


int main()
{
    enum class Color
    {
        red,
        blue
    };
 
    Color color{ Color::blue };
 
    std::cout << static_cast<int>(color); // will print 1
 
    return 0;
}