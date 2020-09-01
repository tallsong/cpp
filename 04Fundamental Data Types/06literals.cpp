#include<iostream>
#include<bitset>
int main()
{
    int bin{0b1010'1010};
    long value{23'345'343'344};//C++14 features
    std::bitset<8> bin1{0b1100'1101};
    std::bitset<8> bin2{0xc5};//equal 1100 0101
    std::cout << bin1 << ' ' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // we can also print from std::bitset directly
    /*
    This prints:

    11000101 11000101
    1010
    */
    return 0;
}