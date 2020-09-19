
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool contaionNut(std::string_view str)
{
    return str.find("nuut") != std::string_view::npos;
}

int main1()
{

    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};
    auto found{std::find_if(arr.begin(), arr.end(), contaionNut)};
    if (found != arr.end())
    {
        std::cout << "founded " << *found << "!";
    }
    else
    {
        std::cout << "not founded!";
    }
    return 0;
}



void doubleNumber(int &i)
{
  i *= 2;
}
 
int main()
{
  std::array arr{ 1, 2, 3, 4 };
 
  std::for_each(arr.begin(), arr.end(), doubleNumber);
 
  for (int i : arr)
  {
    std::cout << i << ' ';
  }
 
  std::cout << '\n';
 
  return 0;
}