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

// �������
char digits[30];

// ÿ������ֻ�ܳ���һ��
bool used[30];



/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

bool IsRunroundNumber(unsigned num);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.2.3 Runaround Numbers/input7.txt";
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
	unsigned long start;
	cin >> start;
	++start;
	while (true)
	{
		if (IsRunroundNumber(start))
		{
			cout << start << endl;
			break;
		}
		++start;
	}

}

bool IsRunroundNumber(unsigned num)
{
	memset(digits, 0, sizeof(digits));
	memset(used, 0, sizeof(used));
	int count = 0;
	while (num)
	{
		int remain = num % 10;
		if (remain == 0)
		{
			return false;
		}
		num /= 10;
		digits[count++] = remain;
		if (used[remain])
		{
			return false;
		}
		used[remain] = true;
	}
	memset(used, 0, sizeof(used));
	// һ��count��
	int pos = count;
	int begin = digits[pos-1];
	int init = begin;
	used[begin] = true;
	for (int i = 1; i < count; ++i)
	{
		pos = pos - begin;
		while (pos <= 0)
		{
			pos += count;
		}
		begin = digits[pos - 1];
		if (used[begin])
		{
			return false;
		}
		used[begin] = true;
	}
	pos = pos - begin;
	while (pos <= 0)
	{
		pos += count;
	}
	if (digits[pos-1] != init)
	{
		return false;
	}
	return true;
}