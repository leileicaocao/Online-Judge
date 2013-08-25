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

const int MAXV = 257;
int ans[MAXV];

int total, B, dis;

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

bool DFS(int step, int maxNum, int curNum);

int Distance(int num1, int num2);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.1.5 Hamming Codes/input11.txt";
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

	
	cin >> total >> B >> dis;
	// �ҳ�N���������ΪB������ΪD
	int maxNum = pow(double(2), double(B));
	DFS(0, maxNum, 0);
	for (int i = 0; i < total; ++i)
	{
		if ((i % 10) == 0)
		{
			cout << ans[i];
		}
		else
		{
			cout << ' ' << ans[i];
		}
		if ((i % 10) == 9)
		{
			cout << endl;
		}
	}
	if ((total % 10) != 0)
	{
		cout << endl;
	}

}

bool DFS(int step, int maxNum, int curNum)
{
	if (step == total)
	{
		return true;
	}
	for (int i = curNum; i <= maxNum; ++i)
	{
		bool isOK = true;
		// 1.�Ƿ���ǰ���step-1������
		for (int j = 0; j < step; ++j)
		{
			if (Distance(ans[j], i) < dis)
			{
				isOK = false;
				break;
			}
		}
		// 2.�������Ƿ��������������
		if (isOK)
		{
			int num = 0;
			for (int k = i + 1; k <= maxNum; ++k)
			{
				if (Distance(k, i) >= dis)
				{
					++num;
				}
				if (num >= (total - step - 1))
				{
					break;
				}
			}
			if (num < (total - step - 1))
			{
				isOK = false;
			}

		}
		if (isOK)
		{
			ans[step] = i;
			if (DFS(step + 1, maxNum, i + 1))
			{
				return true;
			}
		}
	}
	return false;
}
int Distance(int num1, int num2)
{
	int ans = 0;
	for (int i = 0; i < B; ++i)
	{
		if ((num1 & (1 << i)) != (num2 & (1 << i)))
		{
			++ans;
		}
	}
	return ans;
}
