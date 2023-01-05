#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
	// Your code here
	bool flag = bits.test(3);
	bits <<= 1;
	if (flag)
	{
		bits.set(0);
	}
	return bits;
}

std::bitset<4> rotlExtra(std::bitset<4> bits)
{
	// Your code here
	bool flag = (int)((bits>>3).to_ulong()) % 2;
	bits <<= 1;
	if (flag)
	{
		bits |= 0b0001;
	}
	return bits;
}

std::bitset<4> rotlExtra_good(std::bitset<4> bits)
{
	// bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits<<1) | (bits>>3);
}
 

int main()
{
	std::bitset<4> bits1{0b0001};
	std::cout << rotlExtra(bits1) << '\n';

	std::bitset<4> bits2{0b1001};
	std::cout << rotlExtra(bits2) << '\n';

	return 0;
}