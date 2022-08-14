/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 == -1)
            {
                cur = nums2[p2--];
            }
            else if (p2 == -1)
            {
                cur = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2])
            {
                cur = nums1[p1--];
            }
            else
            {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

// @lc code=end

int main()
{
    Solution solution;
    std::vector<int> v1{0};
    std::vector<int> v2{1};

    solution.merge(v1, 0, v2, 1);

    return 0;
}
