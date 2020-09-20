#include <bitset>
#include <iostream>
 int main1()
{
    std::bitset<4> x { 0b1100 };
 
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000
 
    return 0;
}

// This prints:
// 1100
// 0110
// 1000

/*
0 0 0 1 XOR
0 0 1 1 XOR
0 1 1 1
--------
0 1 0 1

*/




int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)
 
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';
 
    return 0;
}