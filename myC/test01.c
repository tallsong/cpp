#define _crt_secure_no_warnings
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int bubble()
{
	int arr[10] = { 1,1,2,1,1,8,9,0,3,3 };
	int len = 10;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i=0; i < 10; i++)
	{
		printf("%d\n",arr[i]);
	}
	return  EXIT_SUCCESS;
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b =temp;
}
void bubble2(char ** arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
	
			if (*arr[j] > *arr[j + 1])
			{
				char * temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main2()
{
	char *arr[] = { "cshdf", "ehsdhf", "bjhdjfhd","abee" };

	bubble2(arr, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", arr[i]);
	}

	return EXIT_SUCCESS;
}