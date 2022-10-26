/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <string>
#include <utility>

class Solution
{
public:
    bool helper(int i, int j, int k, std::vector<std::vector<char>> &board, std::string &word, std::vector<std::vector<bool>> &visited)
    {
        if (board.at(i).at(j) != word.at(k))
            return false;
        if (k == word.size() - 1)
            return true;
        visited.at(i).at(j) = true;
        std::vector<std::pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &direction : directions)
        {
            auto new_i{i + direction.first};
            auto new_j{j + direction.second};
         
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board.at(0).size())
            {
                if (!visited.at(new_i).at(new_j))
                {
                    if (helper(new_i, new_j, k + 1, board, word, visited))
                        return true;
                }
            }
        }

        visited.at(i).at(j) = false;
        return false;
    }

    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        int h = board.size(), w = board[0].size();
        std::vector<std::vector<bool>> visted(h, std::vector<bool>(w));
        for (int i{0}; i < h; ++i)
        {
            for (int j{0}; j < w; ++j)
            {

                if (helper(i, j, 0, board, word, visted))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word{"ABCB"};

    //注意这个特殊情况
    // std::vector<std::vector<char>> board{{'a'}};
    // std::string word{"a"};
    // std::vector<std::vector<char>> board{{'a', 'b'}};
    // std::string word{"ba"};
    Solution s;
    s.exist(board, word);

    return 0;
}
