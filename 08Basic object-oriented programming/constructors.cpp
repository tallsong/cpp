#include <string>
#include <iostream>
#include <cstdint>
class Date
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Explicitly defaulted constructor
    Date() = default;
};

class Date2
{
private:
    // Note: No initializations at member declarations
    int m_year;
    int m_month;
    int m_day;

public:
    // Empty user-provided constructor
    Date2(){};
};

class Ball
{
private:
    std::string m_color{};
    double m_radius{};

public:
    Ball(double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    Ball(const std::string &color = "black", double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;

public:
    Something(int value1, double value2, char value3 = 'c')    // this line already has a lot of stuff on it
        : m_value1{value1}, m_value2{value2}, m_value3{value3} // so we can put everything indented on next line
    {
    }
};

class RGBA
{

public:
    using component_type = std::uint_fast8_t;

private:
    component_type m_red;
    component_type m_green;
    component_type m_blue;
    component_type m_alpha;

public:
    RGBA(component_type red = 0, component_type green = 0, component_type blue = 0, component_type alpha = 255)
        : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
    {
    }
    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green)
                  << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha);
    }
};

class Ball_new
{
private:
    std::string m_color{"black"};
    double m_radius{};

public:
    // Constructor with only radius parameter (color will use default value)
    Ball_new(double radius)
        : m_radius{radius}
    {
    }

    // Constructor with both color and radius parameters
    Ball_new(const std::string &color = "black", double radius = 10.0)
        : m_color{color}, m_radius{radius}
    {
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    Date today{};     // today is 0, 0, 0
    Date2 tomorrow{}; // tomorrows's members are uninitialized

    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    RGBA teal{0, 127, 127};
    teal.print();

    Ball_new def2{};
    def2.print();

    Ball_new blue2{"blue"};
    blue2.print();

    Ball_new twenty2{20.0};
    twenty2.print();

    Ball_new blueTwenty2{"blue", 20.0};
    blueTwenty2.print();

    return 0;
}