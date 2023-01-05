#ifndef BITMASKS_H
#define BITMASKS_H
#include <cstdint>
// C++14
namespace c14
{
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

}

namespace c11e
{
    //Defining bit masks in C++11 or earlier
    constexpr std::uint_fast8_t mask0{ 1 << 0 }; // 0000 0001 
    constexpr std::uint_fast8_t mask1{ 1 << 1 }; // 0000 0010
    constexpr std::uint_fast8_t mask2{ 1 << 2 }; // 0000 0100
    constexpr std::uint_fast8_t mask3{ 1 << 3 }; // 0000 1000
    constexpr std::uint_fast8_t mask4{ 1 << 4 }; // 0001 0000
    constexpr std::uint_fast8_t mask5{ 1 << 5 }; // 0010 0000
    constexpr std::uint_fast8_t mask6{ 1 << 6 }; // 0100 0000
    constexpr std::uint_fast8_t mask7{ 1 << 7 }; // 1000 0000
    
}
#endif