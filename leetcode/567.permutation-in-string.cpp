/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    std::string current{""};
    bool checkInclusion(string s1, string s2)
    {
        std::vector<bool> visited(s1.size(), false);
        std::ranges::sort(s1);
        return helper(visited, s1, s2);
    }

    bool helper(std::vector<bool>& visited, const string& s1, string& s2)
    {

        if (current.size() == s1.size() && s2.find(current) != std::string::npos)
        {
            return true;
        }
        for (int i{0}; i < s1.size(); ++i)
        {
            if (visited[i])
                continue;
            if (i > 0 && s1[i] == s1[i - 1] && !visited[i - 1])
                continue;
            current.push_back(s1.at(i));
            visited[i] = true;
            if (helper(visited, s1, s2))
            {
                return true;
            }
            visited[i] = false;
            current.pop_back();
        }
        return false;
    }
};
// @lc code=end
