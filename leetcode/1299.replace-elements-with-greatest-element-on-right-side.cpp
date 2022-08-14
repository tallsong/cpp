/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    std::vector<int> replaceElements(std::vector<int> &arr)
    {
        int temp{-1};
        int n { int(arr.size()) };
        for (int i{n - 1}; i >= 0; --i)
        {
            auto t{arr.at(i)};
            if (i == n - 1)
            {
                arr.at(i) = -1;
            }
            else
            {
                
                arr.at(i) = arr.at(i+1) > temp ? arr.at(i+1) : temp;
            }
            temp=t;
        }
        return arr;
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<int> v{0};
    for(auto i: s.replaceElements(v))
    {
        std::cerr<<i<<'\t';
    }
    return 0;
}
