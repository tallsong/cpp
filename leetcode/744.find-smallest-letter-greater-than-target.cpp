/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */
#include <cmath>
#include <climits>
#include <vector>
// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        int left{0};
        int right = letters.size();

        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            if (letters[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return letters[left % letters.size()];
    }
};
// @lc code=end

int main()
{
    std::vector<char> letter{'c', 'f', 'g'};
    std::vector<char> letter2{'x', 'x', 'y', 'y'};

    Solution s;
    s.nextGreatestLetter(letter, 'a');
    s.nextGreatestLetter(letter2, 'z');

    return 0;
}
