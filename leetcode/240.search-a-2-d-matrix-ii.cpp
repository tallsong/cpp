/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
#include <vector>
// @lc code=start
class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        while (x < m && y >= 0)
        {
            int value{matrix[x][y]};
            if (value == target)
                return true;
            else if (value > target)
            {
                --y;
            }
            else
                ++x;
        }
        return false;
    };
};
// @lc code=end

int
t()
{
    std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    Solution s;
    s.searchMatrix(matrix, 5);
    return 0;
}

int main()
{
    std::vector<std::vector<int>> matrix{{-5}};
    Solution s;
    s.searchMatrix(matrix, -5);
    return 0;
}