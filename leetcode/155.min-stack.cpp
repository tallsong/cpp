/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <stack>

// @lc code=start
class MinStack
{
    std::stack<int> s;
    std::stack<int> min;

public:
    MinStack()
    {
        min.push(INT_MAX);
    }

    void push(int val)
    {
        s.push(val);
        min.push(std::min(min.top(), val));
    }

    void pop()
    {
        s.pop();
        min.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
