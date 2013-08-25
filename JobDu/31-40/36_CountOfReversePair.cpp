#include <iostream>
#include <vector>

#include "36_CountOfReversePair.h"

using namespace std;

int CountOfReversePair(int arr[], int size)
{
	if (arr == NULL || size <= 1)
	{
		return 0;
	}
	return CountOfPairHelp(arr, 0, size - 1);
}

int CountOfPairHelp(int arr[], int from, int to)
{
	if (from >= to)
	{
		return 0;
	}
	int mid = from + ((to - from) >> 1);
	int ans = 0;
	ans += CountOfPairHelp(arr, from, mid);
	ans += CountOfPairHelp(arr, mid + 1, to);
	int left = from;
	int right = mid + 1;
	// ��Ҫ�õ��������飬�����ݴ�鲢�õ�����
	vector<int> vec;
	while (left <= mid || right <= to)
	{
		// ����Ѿ�û��
		if (left > mid)
		{
			vec.push_back(arr[right++]);
		}
		else if (right > to)
		{// �ұ��Ѿ�û��
			vec.push_back(arr[left++]);
			// �ұߵĸ���
			//ans += (to - mid);
		}
		else
		{// ���߶���
			if (arr[left] <= arr[right])
			{
				vec.push_back(arr[left++]);
			}
			else 
			{
				vec.push_back(arr[right++]);
				// ���ʣ��ĸ���
				ans += (mid - left + 1);
			}
		}
	}
	// ��vec�е���������arr��
	for (int i = 0; i < vec.size(); ++i)
	{
		arr[from + i] = vec[i];
	}
	return ans;
}

void Test_36_CountOfReversePair()
{
	int arr[] = 
	{
		7, 5, 6, 4
	};
	cout << CountOfReversePair(arr, sizeof(arr) / sizeof(int)) << endl;
}