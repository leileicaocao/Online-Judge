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

const int MAXV = 40;

unsigned f[MAXV][MAXV * (MAXV + 1) / 2];

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.2.2 Subset Sums/input6.txt";
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

/*
	������ǰi�����������Ϊj������
	�Ż��߲���
*/
void Process()
{
	int N;
	cin >> N;
	int multi = N * (N + 1) / 2;
	if (multi & 1)
	{
		cout << 0 << endl;
		return;
	}
	multi >>= 1;

	f[1][1] = 1;
	f[1][0] = 1;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= multi; ++j)
		{
			if (j >= i)
			{
				f[i][j] = f[i-1][j] + f[i-1][j-i];
			}
			else
			{
				f[i][j] = f[i-1][j];
			}
		}
	}

	cout << f[N][multi] / 2 << endl;
}

