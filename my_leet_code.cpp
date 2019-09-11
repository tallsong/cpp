#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
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