/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <set>
// @lc code=start
class Solution
{
public:
    int thirdMax(std::vector<int> &nums)
    {
        std::set<int> s;
        for (auto num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    };
};
// @lc code=end
int main()
{
    std::vector v{2, 2, 3, 1};
    Solution s;
    std::cerr << s.thirdMax(v);
    return 0;
}