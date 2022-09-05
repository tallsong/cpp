#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;
/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void reverse(std::vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            std::swap(nums.at(start++), nums.at(end--));
        }
    }
    void rotate(std::vector<int> &nums, int k)
    {
        k%=nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};

// @lc code=end

int main()
{
    vector<int> mastrx{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(mastrx, 3);
    for (auto i : mastrx)
    {
        std::cerr << i << '\t';
    }

    return 0;
}
