#include <cstdint>
#include <iostream>

 
int main2()
{
        // Define a bunch of physical/emotional states
	constexpr std::uint_fast8_t isHungry{	1 << 0 }; // 0000 0001
	constexpr std::uint_fast8_t isSad{		1 << 1 }; // 0000 0010
	constexpr std::uint_fast8_t isMad{		1 << 2 }; // 0000 0100
	constexpr std::uint_fast8_t isHappy{	1 << 3 }; // 0000 1000
	constexpr std::uint_fast8_t isLaughing{ 1 << 4 }; // 0001 0000
	constexpr std::uint_fast8_t isAsleep{	1 << 5 }; // 0010 0000
	constexpr std::uint_fast8_t isDead{		1 << 6 }; // 0100 0000
	constexpr std::uint_fast8_t isCrying{	1 << 7 }; // 1000 0000
 
	std::uint_fast8_t me{}; // all flags/options turned off to start
	me |= isHappy | isLaughing; // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing
 
	// Query a few states
	// (we'll use static_cast<bool> to interpret the results as a boolean value)
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
 
	return 0;
}



int main3()
{
    constexpr std::uint_fast8_t option_viewed{ 0x01 };
    constexpr std::uint_fast8_t option_edited{ 0x02 };
    constexpr std::uint_fast8_t option_favorited{ 0x04 };
    constexpr std::uint_fast8_t option_shared{ 0x08 };
    constexpr std::uint_fast8_t option_deleted{ 0x10 };
 
    std::uint_fast8_t myArticleFlags{};
    myArticleFlags |= option_viewed;
    bool isDeleted (myArticleFlags & option_deleted);
    myArticleFlags &= ~option_favorited;
    return 0;
}
int main()
{
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7
 
    std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags
 
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
 
    return 0;
}