/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */



#include<vector>
#include<iostream>
#include<algorithm>

// @lc code=start
class Solution
{
public:
    int heightChecker(std::vector<int> &heights)
    {
        std::vector temp{heights};
        std::sort(heights.begin(),heights.end());
        int result{0};
        for(size_t i{0};i<heights.size();++i)
        {
            if(temp.at(i)!=heights.at(i))
                ++result;
        }


        return result;
    }
};
// @lc code=end
int main()
{
    std::vector v{1,1,4,2,1,3};
    Solution s;
    std::cerr<<s.heightChecker(v);
    return 0;
}