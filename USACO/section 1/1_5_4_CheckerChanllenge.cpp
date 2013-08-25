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

const int MAXV = 14;

int check[MAXV];
// ���
bool leftCheck[MAXV][MAXV];
// �Ҳ�
bool rightCheck[MAXV][MAXV];
// ÿһ��
bool line[MAXV];

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

void DFS(int N, int step, int &total);


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.5.4 Checker Challenge/input8.txt";
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
	
	memset(leftCheck, 0, sizeof(leftCheck));
	memset(rightCheck, 0, sizeof(rightCheck));
	memset(line, 0, sizeof(line));

	int total = 0;
	DFS(N, 0, total);
	cout << total << endl;
}

void DFS(int N, int step, int &total)
{
	// step��ͷ��N��1��
	if (step == N)
	{
		if (total < 3)
		{
			// ������
			cout << (check[0] + 1);
			for (int i = 1; i < N; ++i)
			{
				cout << ' ' << (check[i] + 1);
			}
			cout << endl;
		}
		++total;
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (step == 0)
		{ // ��0��
			check[step] = i;
			// �Ѻ����ȫ������Ϊtrue
			for (int j = step, k = i; j < N && k >= 0; ++j, --k)
			{
				leftCheck[j][k] = true;
			}
			//leftCheck[step][i] = true;
			for (int j = step, k = i; j < N && k < N; ++j, ++k)
			{
				rightCheck[j][k] = true;
			}
			//rightCheck[step][i] = true;
			line[i] = true;

			DFS(N, step + 1, total);

			for (int j = step, k = i; j < N && k >= 0; ++j, --k)
			{
				leftCheck[j][k] = false;
			}

			//leftCheck[step][i] = false;
			for (int j = step, k = i; j < N && k < N; ++j, ++k)
			{
				rightCheck[j][k] = false;
			}
			//rightCheck[step][i] = false;
			line[i] = false;
		}
		else
		{
			// N��λ�ÿ�ѡ
			if (!line[i])
			{ // ����û��
			
				
				if (!leftCheck[step][i] && !rightCheck[step][i])
				{
					check[step] = i;
					for (int j = step, k = i; j < N && k >= 0; ++j, --k)
					{
						leftCheck[j][k] = true;
					}
					//leftCheck[step][i] = true;
					for (int j = step, k = i; j < N && k < N; ++j, ++k)
					{
						rightCheck[j][k] = true;
					}
					line[i] = true;
					DFS(N, step + 1, total);
					for (int j = step, k = i; j < N && k >= 0; ++j, --k)
					{
						leftCheck[j][k] = false;
					}

					//leftCheck[step][i] = false;
					for (int j = step, k = i; j < N && k < N; ++j, ++k)
					{
						rightCheck[j][k] = false;
					}
					line[i] = false;
				}
			}			
		}
	}
}