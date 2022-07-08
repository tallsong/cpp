#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;
        for(int index{0};index<=haystack.size()-needle.size();++index)
        {
            if(haystack.substr( index,needle.size()) == needle)
                return index;
            
        }
        return -1;   
    }
};

int main()
{
    Solution s;
    std::string a = "1", b = "11";
    std::cout << s.addBinary(a, b);

    std::cout << std::strstr("hello,world!", "");
    return 0;
}