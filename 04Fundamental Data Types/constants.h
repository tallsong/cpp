#ifndef CONSTANTS_H
#define CONSTANTS_H
 
// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 }; // inline constexpr is C++17 or newer only
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double my_gravity { 9.8 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif