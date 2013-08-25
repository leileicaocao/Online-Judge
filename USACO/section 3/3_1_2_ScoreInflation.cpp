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

const int MAXV = 10001;

int s[MAXV];

// ÿ�����Ļ���
int costTime[MAXV];

// ÿ�����ļ�ֵ
int price[MAXV];

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.1.2 Score Inflation/input4.txt";
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
	int totalTime;
	int category;

	cin >> totalTime >> category;
	for (int i = 0; i < category; ++i)
	{
		cin >> price[i] >> costTime[i];
	}
	s[0] = 0;
	for (int i = 1; i <= totalTime; ++i)
	{
		int cur = 0;
		for (int j = 0; j < category; ++j)
		{
			int tmpTime = i - costTime[j];
			if (tmpTime >= 0)
			{
				int tmpPrice = s[tmpTime] + price[j];
				if (tmpPrice > cur)
				{
					cur = tmpPrice;
				}
			}
		}
		s[i] = cur;
		//if (cur != 0)
		//{
		//	cout << i << ' ' << cur << endl;
		//}
	}

	cout << s[totalTime] << endl;
}

