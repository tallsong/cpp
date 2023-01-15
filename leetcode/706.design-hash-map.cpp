/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */
#include <vector>
#include <list>
#include <utility>
// @lc code=start
class MyHashMap
{
private:
    std::vector<std::list<std::pair<int, int>>> data;
    static constexpr int base = 1024;
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashMap() : data(base)
    {
    }

    void put(int key, int value)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it).first == key)
            {

                (*it).second = value;
                return;
            }
        }
        data[hash(key)].push_back({key, value});
    }

    int get(int key)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it).first == key)
            {

                return (*it).second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        for (auto it{data[hash(key)].begin()}; it != data[hash(key)].end(); ++it)
        {
            if ((*it).first == key)
            {

                data[hash(key)].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
