/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <vector>

// @lc code=start







class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int n{int(matrix.size())};
        for (int i{0}; i < n / 2; ++i)
        {
            //matrix.at(i).at(j) = matrix.at(n-j-1).at(i);
            for (int j{i}; j < n - 1 - i; ++j)
            {
                auto temp{matrix.at(j).at(n - 1 - i)};
                matrix.at(j).at(n - 1 - i) = matrix.at(i).at(j);
                matrix.at(i).at(j) = matrix.at(n - j - 1).at(i);
                matrix.at(n - j - 1).at(i) = matrix.at(n - i - 1).at(n - j - 1);
                matrix.at(n - i - 1).at(n - j - 1) = temp;
            }
        }
    }
};
// @lc code=end

int main()
{
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    return 0;
}