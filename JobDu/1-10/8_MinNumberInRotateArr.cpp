#include <iostream>

#include "8_MinNumberInRotateArr.h"

using namespace std;


int MinNumberInRotateArr(int arr[], int left, int right)
{
	if (arr == NULL || left < 0 || right < left)
	{
		throw std::exception("Invalid input");
	}
	if (left == right)
	{
		return arr[left];
	}
	while (arr[left] >= arr[right])
	{
		if (left + 1 == right)
		{
			return arr[right];
		}
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			// ��Ҫ���Բ���
			int ans = arr[left];
			for (int i = left + 1; i <= right; ++i)
			{
				ans = min(ans, arr[i]);
			}
			return ans;
		}
		// ֻ����ߴ����м��ʱ�򣬲ű�����һ���֣����򣬾��ǵڶ�����
		if (arr[left] > arr[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return arr[left];
}

int MinNumberInRotateArr2(int arr[], int left, int right)
{
	if (arr == NULL || left < 0 || right < left)
	{
		throw std::exception("Invalid input");
	}
	if (left == right)
	{
		return arr[left];
	}
	while (arr[left] >= arr[right])
	{
		if (left + 1 == right)
		{
			return arr[right];
		}
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			// ��Ҫ���Բ���
			int ans = arr[left];
			for (int i = left + 1; i <= right; ++i)
			{
				ans = min(ans, arr[i]);
			}
			return ans;
		}		
		if (arr[mid] >= arr[right])
		{
			left = mid;
		}
		else 
		{
			left = mid;
		}
	}
	return arr[left];
}

int FindNumberInRotateArr(int arr[], int length, int key)
{
	if (arr == NULL || length < 0)
	{
		throw std::exception("Invalid Input");
	}
	int left = 0;
	int right = length - 1;
	while (left + 1 < right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == key)
		{
			return mid;
		}
		if (arr[left] <= key && key <= arr[mid] ||
			arr[left] >= key && key >= arr[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	if (arr[left] == key)
	{
		return left;
	}
	if (arr[right] == key)
	{
		return right;
	}
	return -1;
}

void Test_8_MinNumberInRotateArr()
{
	int arr[] = 
	{
		1, 1,1,1, 0,1
	};
	try
	{
		int minNum = MinNumberInRotateArr2(arr, 0, sizeof(arr) / sizeof(int) - 1);
		cout << minNum << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
