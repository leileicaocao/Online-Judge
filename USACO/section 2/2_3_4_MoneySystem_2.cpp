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

// Ӳ����
const int MAXV = 26;
// Ӳ������
int coins[MAXV];

int s[10001][MAXV];

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.2.4 Money Systems/input2.txt";
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
	int V, N;
	cin >> V >> N;
	coins[0] = 0;
	for (int i = 1; i <= V; ++i)
	{
		cin >> coins[i];
	}
	sort(coins, coins + V + 1);
	for (int i = 1; i <= N; ++i)
	{
		if (i % coins[1] == 0)
		{
			s[i][1] = 1;
		}
	}
	

	// Ǯ��Ϊi�������ֵΪcoins[j]�ĸ���
	for (int i = coins[1] + 1; i <= N; ++i)
	{
		for (int j = 2; (j <= V) && (i >= coins[j]); ++j)
		{
			int num = coins[j];
			int kind = 0;

			for (int k = 1; k * num < i; ++k)
			{
				for (int t = j - 1; t > 0; --t)
				{
					kind += s[i-k*num][t];
				}					
			}
			if (i % coins[j] == 0)
			{
				kind += 1;
			}
			s[i][j] = kind;
		}
	}
	int ans = 0;
	for (int i = 1; i <= V; ++i)
	{
		ans += s[N][i];
		//cout << s[N][i] << endl;
	}
	cout << ans << endl;
}