#include <iostream>
#include<cmath>
#include<vector>
#include<stack>
#include <algorithm>
#include<map>
#include<string>
#include<fstream>
#include<queue>
#include<set>
#include<climits>
#include<math.h>
using namespace std;
/*
晚上，有n个人过河，分别需要n1、n2、n3、nn分钟。只有一把手电筒，过河的必要条件是有手电筒。
最多可以两个人同时过河，但必须以两人中较慢的那个人的速度过去。问：所有人都过河，至少需几分钟。

解题思路： 当n==1或者n==2时：所有人直接过河即可。

当n==3时：用时最长和用时最短的人先一起过去，然后用时最短的人回来，再在和剩下的一个人一起过去。
当n==4时：假设time[0]为用时最短的人所用的时间，time[1]为用时第二短的人所用的时间, time[n-1]为用时最长的人所用的时间，   time[n-2]为用时第二长的人所用的时间。
则有两种过河方式：      
2*time[0]+time[n-1]+time[n-2]表示：用时最长的人和用时最短的人先一起过去，然后用时最短的人把手电筒带回来，再和用时第二长的人一起过去，用时最短的人回来。   
2*time[1]+time[0]+time[n-1]表示：  用时最短和用时第二短的人一起过去，然后用时最短的人把手电筒带回来，然后用时最长和用时第二长的人一起过去，用时第二短的人回来。     
比较两种过河方式：2*time[0]+time[n-1]+time[n-2]<2*time[1]+time[0]+time[n-1]      这样相当于每次都过去了两个人，所以n-=2，   再对剩下的n-2个人执行相同的操作，直至不足4人即可。
————————————————
*/
int acrpss_river(vector<int> arr, int n)
{
	arr.resize(n);
	sort(arr.begin(), arr.end());
	if (arr.size() == 1 || arr.size() == 2)
	{
		return arr[arr.size() - 1];
	}
	else if (arr.size() == 3)
	{
		return arr[0] + arr[1] + arr[2];
	}
	else
	{
		return guohe(arr, n - 2) + min(arr[n - 1] + arr[n - 2] + 2 * arr[0],arr[n - 1] + arr[1] * 2 + arr[0]);
	}
}

