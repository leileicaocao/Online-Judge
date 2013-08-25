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


using namespace std;

#define _MY_DEBUG_

const int MAXV = 151;

// λ��
int pos[MAXV][2];

// �ڽӾ���
double dist[MAXV][MAXV];

double maxDist[MAXV];


////////////////////////////////////////////////////////////////////////////
// ���鼯
int unionFather[MAXV];
 
int GetFatherUnion(int v)
{
    if (unionFather[v] == v)
	{
       return v;
	}
    return (unionFather[v] = GetFatherUnion(unionFather[v]));
}
 
bool Same(int x,int y)
{
     return (GetFatherUnion(x) == GetFatherUnion(y));
}

void Judge(int x,int y){
    int fx,fy;
    fx = GetFatherUnion(x);
    fy = GetFatherUnion(y);

    if (fx == fy) 
		return ;

    unionFather[fx] = fy;
}

void UnionInit(int N)
{
	for (int i = 0; i < N; ++i)
	{
		 unionFather[i] = i;
	}
}


////////////////////////////////////////////////////////////////////////////



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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.4.3 Cow Tours/input1.txt";
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
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> pos[i][0] >> pos[i][1];
	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			dist[i][j] = 0x7FFFFFFF;
		}
	}

	UnionInit(num);

	string str;
	cin.ignore();
	for (int i = 0; i < num; ++i)
	{
		getline(cin, str);
		for (int j = 0; j < num; ++j)
		{
			char ch = str[j];
			if (ch == '1')
			{
				double x = fabs(double(pos[i][0] - pos[j][0]));
				double y = fabs(double(pos[i][1] - pos[j][1]));
				double len = sqrt(x * x + y * y);
				dist[i][j] = len;
				dist[j][i] = len;

				Judge(i, j);
			}
		}
	}
	// Floyd
	for (int k = 0; k < num; ++k)
	{
		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num; ++j)
			{
				if (i != j && i != k && j != k)
				{
					double cur = dist[i][j];
					if ((dist[i][k] != 0x7FFFFFFF) &&
						(dist[k][j] != 0x7FFFFFFF) &&
						(dist[i][k] + dist[k][j] < cur))
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}

	// 1.���鼯�ĸ���
	// 2.ÿ�����鼯�����뾶
	// 3.�������鼯ֱ�ӵ���С�뾶
	// ����ֻ����������
	double max1 = 0;
	int f1;
	for (int i = 0; i < num; ++i)
	{
		double mDist = 0;
		for (int j = 0; j < num; ++j)
		{			
			if (i != j)
			{
				if (dist[i][j] != 0x7FFFFFFF)
				{
					if (dist[i][j] > mDist)
					{
						mDist = dist[i][j];
					}
				}
			}
		}
		maxDist[i] = mDist;
		if (mDist > max1)
		{
			max1 = mDist;
			f1 = GetFatherUnion(i);
		}
	}
	double max2 = 0;
	int f2;
	for (int i = 0; i < num; ++i)
	{
		if (GetFatherUnion(i) != f1)
		{
			if (maxDist[i] > max2)
			{
				max2 = maxDist[i];
				f2 = GetFatherUnion(i);
			}
		}
	}
	double minDist = 0x7FFFFFFF;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			if (!Same(i, j))
			{
				double x = fabs(double(pos[i][0] - pos[j][0]));
				double y = fabs(double(pos[i][1] - pos[j][1]));
				double len = sqrt(x * x + y * y);
				if (len < minDist)
				{
					minDist = len;
				}
			}
		}
	}
	double total = max1 + max2 + minDist;
	printf("%lf.6\n", total);
}

