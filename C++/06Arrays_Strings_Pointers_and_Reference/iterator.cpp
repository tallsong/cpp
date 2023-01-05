#include <array>
#include <iostream>
#include<vector>
int main1()
{

    std::array nums{1, 2, 4, 56, 6, 1, 1};
    auto begin{&nums[0]};
    auto end{begin + std::size(nums)};
    /*
    auto begin{ array.begin() };
  auto end{ array.end() };
    */
    for (auto ptr{begin}; ptr != end; ++ptr)
    {
        std::cout << *ptr;
    }
    return 0;
}

int main()
{
	std::vector v { 1, 2, 3, 4, 5, 6, 7 };
 
	auto it { v.begin() };
 
	++it; // move to second element
	std::cout << &(*it) << '\n'; // ok: prints 2
 
	v.erase(it); // erase the element currently being iterated over
 
	// erase() invalidates iterators to the erased element (and subsequent elements)
	// so iterator "it" is now invalidated
	
	++it; // undefined behavior
	std::cout <<  &(*it) << '\n'; // undefined behavior
	   
	return 0;
}