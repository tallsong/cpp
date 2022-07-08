#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        if(a.size() > b.size())
        {
            swap(a,b);
        }
        int gap_size{int(b.size()) - int(a.size())};
        int carry{0};
        for (int index{int(a.size() )- 1}; index >= 0; --index)
        {
            int t1{a.at(index) - '0'};
            int t2{b.at(gap_size + index) - '0'};
            int temp{carry + t1 + t2 };
            if (temp > 1)
            {
                carry = 1;
                b.at(gap_size + index) = temp - 2 + '0';
            }
            else
            {
                carry = 0;
                b.at(gap_size + index) = temp + '0';
            }
        }
        for (int index{gap_size - 1}; index >= 0; --index)
        {
            int temp{carry + b.at(index) - '0'};
            if (temp > 1)
            {
                carry = 1;
                b.at(index) = temp - 2  + '0';
            }
            else
            {
                carry = 0;
                b.at(index) = temp + '0';
            }
        }

        if (carry)
            b.insert(0, 1, '1');
        return b;
    }
};

int main()
{
    Solution s;
    std::string a = "1", b = "11";
    std::cout << s.addBinary(a, b);


    std::cout<<std::strstr("hello,world!","");
    return 0;
}