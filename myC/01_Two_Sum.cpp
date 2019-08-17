/*
暴力解法
*/
#include <vector>
#include <map>
using namespace std;

//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		int i, j;
//		for (i = 0; i < nums.size() - 1; i++)
//		{
//			for (j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[i] + nums[j] == target)
//				{
//					return { i,j };
//				}
//
//			}
//		}
//		return { i,j };
//	}
//};

/*
两遍哈希表
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//建立hash表存放数组元素
		vector<int> b(2, -1);//存放结果, 声明一个初始大小为2且初始值都为-1的向量
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
};
/*
一遍哈希表
*/
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//建立hash表存放数组元素
		vector<int> b(2, -1);//存放结果, 声明一个初始大小为2且初始值都为-1的向量
		for (int i = 0; i < nums.size(); i++)
		{
			if (a.count(target - nums[i]) > 0)
			{
				b[0] = a[target - nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;
		}
		return b;
	};
};
