#include <iostream>
enum Color : int; // Okay
int main()
{

    enum Color
    {
        red,
        green,
        blue,
    };

    // Use an 8 bit unsigned integer as the enum base.
    enum Colornew : std::uint_least8_t
    {
        COLOR_BLACK,
        COLOR_RED,
        // ...
    };
    enum Race
    {
        orcs,
        goblins,
        trolls,
        ogres,
        skeleton,
    };
    Race race{trolls};
    Color color{red};
    color = green;
    std::cout << color << '\n';
}