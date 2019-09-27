#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> twoSum_001(vector<int>& nums, int target) 
{
  map<int, int> a;  //建立hash表存放数组元素
  vector<int> b(2, -1);  //存放结果, 声明一个初始大小为2且初始值都为-1的向量
  for (int i = 0; i < nums.size(); i++)
    a.insert(map<int, int>::value_type(nums[i], i));
  for (int i = 0; i < nums.size(); i++) 
  {
    if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
    //判断是否找到目标元素且目标元素不能是本身,count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素。
    {
      b[0] = i;
      b[1] = a[target - nums[i]];
      break;
    }
  }
  return b;
};
vector<int> twoSum2_001(vector<int>& nums, int target) {
  map<int, int> a;  //建立hash表存放数组元素
  vector<int> b(2, -1);  //存放结果, 声明一个初始大小为2且初始值都为-1的向量
  for (int i = 0; i < nums.size(); i++) {
    if (a.count(target - nums[i]) > 0) {
      b[0] = a[target - nums[i]];
      b[1] = i;
      break;
    }
    a[nums[i]] = i;
  }
  return b;
};
int reverse_007(int x) {
  int rev = 0;
  while (x != 0) {
    int pop = x % 10;
    x /= 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
    rev = rev * 10 + pop;
  }
  return rev;
}
bool isPalindrome2_009(int x) {
  int midrev = 0;  //存储后半部分数字的反转结果
  if (x < 0 || (x % 10 == 0 && x != 0))
    return false;  //排除负数和最后一位数字为0的数字
  while (x > midrev) {
    midrev = midrev * 10 + x % 10;
    x /= 10;
  }
  return midrev == x || midrev / 10 == x;  //数字个数为偶数和奇数分两种情况
}
int numIslands_200(vector<vector<char>>& grid)
{
	int h = grid.size();
	if (!h) return 0;
	int w = grid[0].size();
	int num_islands = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == '1')
			{
				grid[i][j] = '0';
				num_islands++;
				queue < pair<int, int>> q;
				q.push({ i,j });
				while (!q.empty())
				{
					auto new_center = q.front();
					q.pop();
					int nh = new_center.first;
					int nw = new_center.second;
					if ((nh > 0) && (grid[nh - 1][nw] == '1')) { q.push({ nh - 1,nw }); grid[nh - 1][nw] = '0'; }
					if ((nw > 0) && (grid[nh][nw - 1] == '1')) { q.push({ nh,nw - 1 }); grid[nh][nw - 1] = '0'; }
					if ((nh < h - 1) && (grid[nh + 1][nw] == '1')) { q.push({ nh + 1,nw }); grid[nh + 1][nw] = '0'; }
					if ((nw < w - 1) && (grid[nh][nw + 1] == '1')) { q.push({ nh,nw + 1 }); grid[nh][nw + 1] = '0'; }
				}
			}
		}
	}
	return num_islands;
}
vector<int> dailyTemperatures_739(vector<int>& T)
{
	int n = T.size();
	vector<int> result(n);
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j += result[j])
		{
			if (T[j] > T[i])
			{
				result[i] = j - i;
				break;
			}
			else
			{
				if (result[j] == 0)
				{
					result[i] = 0;
					break;
				}
			}
		}
	}
	return result;
}

string decodeString(string s) {
	string res = "";
	stack <int> nums;
	stack <string> strs;
	int num = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + s[i] - '0';
		}
		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			res = res + s[i];
		}
		else if (s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
		{
			nums.push(num);
			num = 0;
			strs.push(res);
			res = "";
		}
		else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
		{
			int times = nums.top(); 
			nums.pop();
			for (int j = 0; j < times; ++j)
				strs.top() += res;
			res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
							  //若是左括号，res会被压入strs栈，作为上一层的运算
			strs.pop();
		}
	}
	return res;
}
