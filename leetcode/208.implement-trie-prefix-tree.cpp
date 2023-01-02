/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <string>
#include <vector>
// @lc code=start

class Trie
{
private:
    std::vector<Trie *> children;
    bool is_end;
    Trie *searchPrefix(std::string word)
    {
        auto node{this};
        for (auto ch : word)
        {
            ch -= 'a';
            if (!node->children[ch])
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), is_end(false)
    {
    }

    void insert(std::string word)
    {
        auto node{this};
        for (auto ch : word)
        {
            ch -= 'a';
            if (!node->children[ch])
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->is_end = true;
    }

    bool search(std::string word)
    {
        auto node{searchPrefix(word)};
        return node && node->is_end;
    }

    bool startsWith(std::string prefix)
    {
        return searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
