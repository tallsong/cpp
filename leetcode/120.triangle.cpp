/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include<vector>
#include<climits>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<int> cache(triangle.size(), INT_MAX);
        int minimun = INT_MAX;
        cache[0] = triangle[0][0];
        for (int row{1}; row < triangle.size(); ++row)
        {
            for (int column{row}; column >= 0 ; --column)
            {
                cache[column] = triangle[row][column] + min(get_cache(row - 1, column, cache), get_cache(row - 1, column - 1, cache));
            }
        }
        return *min_element(cache.begin(), cache.end());
    }
    int get_cache(int x, int y, const vector<int>& cache)
    {
        if (x < 0 || y < 0)
            return INT_MAX;
        else
            return cache[y];
    }
};
// @lc code=end


int main()
{
  
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    s.minimumTotal(triangle);

    return 0;
}
