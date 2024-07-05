/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int start{0};
        int end{int(arr.size() - 1)};
        while (start + 1 < end)
        {

            int mid{(start + end) / 2};
            if (arr[mid] < arr[mid + 1])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if (arr[start] > arr[end])
        {
            return start;
        }
        else

        {
            return end;
        }
    }
};
// @lc code=end
