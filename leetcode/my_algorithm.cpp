#include <iostream>
#include <vector>
using namespace std;

void quick_sort(int arr[], int low, int high)
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (true)
	{
		/*从左向右找比key大的值*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*从右向左找比key小的值*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*交换i,j对应的值*/
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	/*中枢值与j对应值交换*/
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	quick_sort(arr, low, j - 1);
	quick_sort(arr, j + 1, high);
}

int binarySearch(vector<int>& nums, int target) {//二分查找模板1
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid - 1; }
	}

	// End Condition: left > right
	return -1;
}
int search(vector<int>& nums, int target) //二分查找
{
	if (nums.size() == 0) {
		return -1;
	}
	int start = 0;
	int end = nums.size() - 1;
	while (start + 1 < end) {
		//start和end差值为1的时候，直接就中止了。
		int mid = start + (end - start) / 2;
		if (nums[mid] < target) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	if (nums[start] == target) {
		//因为差值为1的时候，直接就中止了，所以，需要判断start和end
		return start;
	}
	if (nums[end] == target) {
		//因为差值为1的时候，直接就中止了，所以，需要判断start和end
		return end;
	}
	return -1;
}
