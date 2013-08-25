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


using namespace std;

#define _MY_DEBUG_

const int MAXV = 1001;

int a[MAXV][MAXV];


int s[MAXV][MAXV];


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.5.1 Number Triangles/input10.txt";
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
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> a[i][j];
		}
	}
	// ��̬�滮
	s[1][1] = a[1][1];
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)
			{
				s[i][j] = s[i-1][j] + a[i][j];
			}
			else if (j == i)
			{
				s[i][j] = s[i-1][j-1] + a[i][j];
			}
			else
			{
				int left = s[i-1][j-1];
				if (s[i-1][j] > left)
				{
					left = s[i-1][j];
				}
				s[i][j] = left + a[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (s[N][i] > ans)
		{
			ans = s[N][i];
		}
	}
	cout << ans << endl;
}


