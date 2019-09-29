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

string decodeString(string s)
{
	int num = 0;
	stack<int> nums;
	string res = "";
	stack<string> strs;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + s[i] - '0';
		}
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			res = res + s[i];
		}
		if (s[i] == '[')
		{
			nums.push(num);
			num = 0;
			strs.push(res);
			res = "";
		}
		if (s[i] == ']')
		{
			int times = nums.top(); 
			nums.pop();
			for (int i = 0; i < times; i++)
			{
				strs.top() += res;
			}
			res = strs.top();
			strs.pop();
		}

	}
	return res;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
	queue<pair<int,int>> q;
	int w = image[0].size();
	int h = image.size();
	q.push({sr,sc});
	int oldColor = image[sr][sc];
	if(oldColor == newColor) return image;
	

	while(!q.empty())
	{		
		pair<int,int> pos = q.front();
		int nsr = pos.first;
		int nsc = pos.second;
		image[nsr][nsc] = newColor;
		q.pop();
		if (nsc > 0 && image[nsr][nsc-1] == oldColor) q.push({ nsr,nsc - 1 });
		if (nsc < w - 1 && image[nsr][nsc + 1] == oldColor) q.push({ nsr,nsc + 1 });
		if (nsr > 0 && image[nsr-1][nsc] == oldColor) q.push({ nsr - 1,nsc });
		if (nsr < h - 1 && image[nsr+1][nsc] == oldColor) q.push({ nsr + 1,nsc });
	}
	return image;
}

vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0)
				dist[i][j] = 0;
			else {
				for (int k = 0; k < rows; k++)
					for (int l = 0; l < cols; l++)
						if (matrix[k][l] == 0) {
							int dist_01 = abs(k - i) + abs(l - j);
							dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
						}
			}
		}
	}
	return dist;

}

vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
	int rows = matrix.size();
	if (rows == 0)
		return matrix;
	int cols = matrix[0].size();
	vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
	queue<pair<int, int> > q;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] == 0) 
			{
				dist[i][j] = 0;
				q.push({ i, j }); //Put all 0s in the queue.
			}

	int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
			if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) 
			{
				if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
					dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
					q.push({ new_r, new_c });
				}
			}
		}
	}
	return dist;
}
