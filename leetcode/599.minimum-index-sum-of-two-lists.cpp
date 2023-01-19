/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
// @lc code=start
class Solution
{
public:
    std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2)
    {
        std::unordered_map<std::string, int> hashtable;
        std::vector<std::string> common_string;
        int least_index{INT_MAX};
        for (int i{0}; i < list1.size(); ++i)
        {
            hashtable.insert(std::make_pair(list1[i], i));
        }
        for (int i{0}; i < list2.size(); ++i)
        {
            if (hashtable.count(list2[i]))
            {
                int sum = i + hashtable[list2[i]];
                if (sum == least_index)
                {
                    common_string.push_back(list2[i]);
                }
                else
                {
                    if (sum < least_index)
                    {
                        least_index = sum;
                        common_string.clear();
                        common_string.push_back(list2[i]);
                    }
                }
            }
        }
        return common_string;
    }
};
// @lc code=end

int main()
{
    std::vector<std::string> list1{"happy", "sad", "good"};
    std::vector<std::string> list2{"sad", "happy", "good"};
    Solution s;
    s.findRestaurant(list1, list2);

    return 0;
}