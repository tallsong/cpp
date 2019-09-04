//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	long long max_x = -(1 << 63), max_y = -(1 << 63), min_x = (1 << 63) - 1, min_y = (1 << 63) - 1;
//	long long x = 0, y = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x >> y;
//		if (x > max_x) max_x = x;
//		if (y > max_y) max_y = y;
//		if (x < min_x) min_x = x;
//		if (y < min_y) min_y = y;
//	}
//	long long long_x = abs(max_x - min_x);
//	long long long_y = abs(max_y - min_y);
//	long long l = long_x > long_y ? long_x : long_y;
//	cout << l * l;
//	return 0;
//
//
//}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n < 3)
	{
		cout << -1;
		return 0;
	}
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 2)
		{
			for (int j = 0; j < i; j++)
			{
				int sum = 0;
				int max = a[0];

				sum += a[i];
				if (a[j] > max)
				{
					max = a[j];
				}
				if (sum - max > max)
				{
					return i;
				}

			}
			return -1;
			
		}
	}
	

}