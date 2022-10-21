/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>
// @lc code=start
class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        auto m{matrix.size()};
        auto n{matrix.at(0).size()};
        int start{0};
        int end{int(m * n - 1)};
        while (start <= end)
        {
            int mid{(end + start) / 2};
            if (matrix.at(mid / n).at(mid % n) == target)
                return true;
            if (matrix.at(mid / n).at(mid % n) < target)
            {
                start = mid + 1;
            }
            else
            {

                end = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    // std::vector<std::vector<int>>  v1{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::vector<std::vector<int>> v1{{1}};
    Solution s;
    s.searchMatrix(v1, 6);
    return 0;
}
