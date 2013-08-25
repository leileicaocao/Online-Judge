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

// ǰ��26�Ǵ�д������26��Сд
const int MAXV = 52;

int dist[MAXV][MAXV];

int ans[MAXV];

bool exist[MAXV];

bool vis[MAXV];

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

void Dij(int start, int size);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.4.4 Bessie Come Home/input7.txt";
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
	int count = 0;
	cin >> count;
	char a, b;
	int len;
	int gap = 'a' - 'A';
	for (int i = 0; i < MAXV; ++i)
	{
		for (int j = 0; j < MAXV; ++j)
		{
			dist[i][j] = 0x7FFFFFFF;			
		}
	}

	for (int i = 0; i < count; ++i)
	{
		cin >> a >> b >> len;
		// 
		int index1;
		int index2;
		if (a >= 'A' && a <= 'Z')
		{
			index1 = a - 'A';
			exist[index1] = true;
		}
		else
		{
			index1 = a - 'a' + 26;
		}
		if (b >= 'A' && b <= 'Z')
		{
			index2 = b - 'A';
			exist[index2] = true;
		}
		else
		{
			index2 = b - 'a' + 26;
		}
		if (len < dist[index1][index2])
		{
			dist[index1][index2] = len;
			dist[index2][index1] = len;
		}
	}

	Dij(25, MAXV);
	

	int minLen = 0x7FFFFFFF;
	char resChar = ' ';
	for (int i = 0; i < 25; ++i)
	{
		if (ans[i] < minLen)
		{
			minLen = ans[i];
			resChar = char('A' + i);
		}
	}
	cout << resChar << ' ' << minLen << endl;
}

void Dij(int start, int size)
{
	for (int i = 0; i < size; ++i)
	{
		ans[i] = dist[start][i];
	}

	vis[start] = true;
	ans[start] = 0;
	
	int count = size - 1;
	while (count--)
	{
		int curLen = 0x7FFFFFFF;
		int curNode = 0;
		for (int i = 0; i < size; ++i)
		{
			// Ѱ�����
			if (!vis[i])
			{
				if (ans[i] < curLen)
				{
					curLen = ans[i];
					curNode = i;
				}
			}
		}
		if (curLen == 0x7FFFFFFF)
		{
			break;
		}

		vis[curNode] = true;
		ans[curNode] = curLen;
		// ���£��ɳ��㷨
		for (int i = 0; i < size; ++i)
		{
			// û�б��������������б�����
			if (!vis[i] && (dist[curNode][i] != 0x7FFFFFFF))
			{
				if (curLen + dist[curNode][i] < ans[i])
				{
					ans[i] = curLen + dist[curNode][i];
				}
			}
		}
	}
}