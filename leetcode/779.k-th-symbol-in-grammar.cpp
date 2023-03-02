/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */
#include <string>

// @lc code=start
class Solution
{
public:
    int grammar(int n, int k)
    {
        if (n == 1)
            return 0;
 

        if (k % 2)
        {
            return !grammar(n - 1, k / 2);
        }
        else
        {
            return grammar(n - 1, k / 2);
        }
    }
    int kthGrammar(int n, int k)
    {
        return grammar(n, k - 1);
    }
};

// @lc code=end
int main()
{
    Solution s;
    s.kthGrammar(3, 1);
}