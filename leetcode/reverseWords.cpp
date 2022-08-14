#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;
// 557
class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int lastSpaceIndex = -1;
        for (int strIndex = 0; strIndex < s.length(); strIndex++)
        {
            if ((strIndex == s.length() - 1) || s[strIndex] == ' ')
            {
                int reverseStrIndex =
                    (strIndex == s.length() - 1) ? strIndex : strIndex - 1;
                for (; reverseStrIndex > lastSpaceIndex; reverseStrIndex--)
                {
                    result += s[reverseStrIndex];
                }
                if (strIndex != s.length() - 1)
                {
                    result += ' ';
                }
                lastSpaceIndex = strIndex;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> mastrx{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    for (int row : s.getRow(3))
    {
        std::cerr << row << '\t';
    }

    return 0;
}
