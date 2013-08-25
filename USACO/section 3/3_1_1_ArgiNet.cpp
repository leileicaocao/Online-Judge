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
#include <limits>
#include <cfloat>
#include <iomanip>


using namespace std;

#define _MY_DEBUG_

const int MAXV = 101;

int dist[MAXV][MAXV];

bool used[MAXV];

int minDist[MAXV];

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

int Prim(int start, int num);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.1.1 Agri-Net/input10.txt";
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
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> dist[i][j];
		}
	}
	
	cout << Prim(0, num) << endl;
}

int Prim(int start, int num)
{
	int ans = 0;
	used[start] = true;
	for (int i = 0; i < num; ++i)
	{
		minDist[i] = dist[start][i];
	}

	int count = num - 1;
	while (count--)
	{
		// ����̵�
		int curDist = 0x7FFFFFFF;
		int curNode = -1;
		for (int i = 0; i < num; ++i)
		{
			if (!used[i])
			{
				if (minDist[i] < curDist)
				{
					curDist = minDist[i];
					curNode = i;
				}
			}
		}
		ans += curDist;
		used[curNode] = true;
		// ����
		for (int i = 0; i < num; ++i)
		{
			if (!used[i])
			{
				if (dist[curNode][i] < minDist[i])
				{
					minDist[i] = dist[curNode][i];
				}
			}
		}
	}

	return ans;
}