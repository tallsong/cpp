#include <vector>
#include <iostream>
 
int main()
{
    std::vector<bool> array { true, false, false, true, true };
    std::cout << "The length is: " << array.size() << '\n';
 
    for (int i : array)
        std::cout << i << ' ';
 
    std::cout << '\n';

 
    return 0;
}