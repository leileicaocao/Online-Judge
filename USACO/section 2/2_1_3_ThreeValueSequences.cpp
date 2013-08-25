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
	MainStructure: 主结构
*/
void MainStructure();

/*
	Process：处理每一组数据
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
	string inputStr = "C:/Users/cao/Desktop/算法/USACO/USACO全部测试数据/2.1.3 Sorting a Three-Valued Sequence/input8.txt";
	//string inputStr = "D:/2挑战编程/input/110205.inp";
	string outputStr = "C:/Users/cao/Desktop/算法/USACO/USACO全部测试数据/1.outp";
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

