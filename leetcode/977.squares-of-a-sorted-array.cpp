/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */


#include<iostream>
#include<vector>




// @lc code=start
class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        int n = nums.size();
        int negative = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < 0)
            {
                negative = i;
            }
            else
            {
                break;
            }
        }

        std::vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n)
        {
            if (i < 0)
            {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
            else if (j == n)
            {
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                ans.push_back(nums[i] * nums[i]);
                --i;
            }
            else
            {
                ans.push_back(nums[j] * nums[j]);
                ++j;
            }
        }

        return ans;
    }
};
// @lc code=end


int f1()
{
    std::cerr<<"call f1\n";
    return 1;
}



int f2()
{
    std::cerr<<"call f2\n";
    return 2;
}
int main()
{
    std::cerr<<f1()*f2()<<'\n';
    std::vector<int> v{-4,-1,0,3,10};
    Solution s;
    for(auto num:s.sortedSquares(v))
    {
        std::cerr<<num<<'\t';
    }
    return 0;
}
