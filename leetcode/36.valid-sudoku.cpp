/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include <utility>

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        std::unordered_map<int, std::unordered_set<int>> row;
        std::unordered_map<int, std::unordered_set<int>> column;
        std::map<std::pair<int, int>, std::unordered_set<int>> sub_box;

        for (int i{0}; i < board.size(); ++i)
        {
            for (int j{0}; j < board[0].size(); ++j)
            {
                if (auto key{board[i][j]}; key != '.')
                {
                    if (row[i].count(key) || column[j].count(key) || sub_box[{i / 3, j / 3}].count(key))
                        return false;
                    else
                    {

                        row[i].insert(key);
                        column[j].insert(key);
                        sub_box[{i / 3, j / 3}].insert(key);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    // std::vector<std::vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    //                                         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //                                         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //                                         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //                                         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //                                         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //                                         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //                                         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //                                         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.isValidSudoku(board);
    return 0;
}