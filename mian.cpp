#include <iostream>
using namespace std;
#include<cmath>
int main()
{
	int n;
	cin >> n;
	int arr[100];
	int min[2];
	cin >> arr[0];
	cin >> arr[1];
	int index;
	for (int i = 2; i < n; i++)
	{
		cin >> arr[i];
		min[0] = abs(arr[i - 2] - arr[i - 1]);
		min[1] = abs(arr[i - 2] - arr[i - 1]);
		if (min[0] < min[1])
		{
			index = i - 2;
			if(min[0] == 0)
			{
				index = i - 2;
				break;
			}
		}

	}
	cout << index << " " << index + 1;
}
