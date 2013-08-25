#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <cstring>
#include <cctype>
#include <queue>
#include <cmath>


using namespace std;

#define _MY_DEBUG_

const int MAXV = 1001;

int arr[MAXV];
int order[MAXV];


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();


/*
	ID: raycao
	PROG: transform
	LANG: C++
*/
int main()
{
	MainStructure();
	return 0;
}

void MainStructure()
{
	
#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.1.3 Sorting a Three-Valued Sequence/input8.txt";
	//string inputStr = "D:/2��ս���/input/110205.inp";
	string outputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.outp";
	ifstream fin;
	fin.open(inputStr);	

	cin.rdbuf(fin.rdbuf());	

	ofstream fout;
	fout.open(outputStr);

	//cout.rdbuf(fout.rdbuf());
#endif

	Process();

}

void Process()
{
	int ans = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	memcpy(order, arr, sizeof(int) * N);
	sort(order, order + N);

	for (int i = 0; i < N; ++i)
	{
		if (arr[i] != order[i])
		{
			int tmp = arr[i];
			for (int j = N - 1; j > i; --j)
			{
				if ((arr[j] != order[j]) &&
					(arr[j] == order[i]) &&
					(arr[i] == order[j]))
				{
					swap(arr[i], arr[j]);
					++ans;
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] != order[i] && arr[i] == 1)
		{
			ans += 2;
		}
	}

	/*for (int i = 0; i < N; ++i)
	{
		if (arr[i] != order[i])
		{
			int tmp = arr[i];
			for (int j = N - 1; j > i; --j)
			{
				if ((arr[j] != order[j]) &&
					arr[j] == order[i])
				{
					swap(arr[i], arr[j]);
					++ans;
					break;
				}
			}
		}
	}*/

	cout << ans << endl;
}

