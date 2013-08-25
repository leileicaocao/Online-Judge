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

using namespace std;

#define _MY_DEBUG_

// cow�����
const int MAXV = 201;

// ����
int cow[MAXV];

struct Inter
{
	int len;
	int from;
	int to;
};

Inter middle[MAXV];



/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

bool Cmp(const Inter& n1, const Inter& n2);


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.3.2 Barn Repair/barn1.in10";
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
	int m;
	int s;
	int c;
	cin >> m >> s >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> cow[i];
	}
	// ��cow����
	sort(cow, cow + c);
	for (int i = 0; i < c - 1; ++i)
	{
		middle[i].len = cow[i+1] - cow[i] - 1;
		middle[i].from = cow[i];
		middle[i].to = cow[i+1];
	}
	// ����
	sort(middle, middle + c - 1, Cmp);
	int minus = 0;
	minus += (cow[0] - 1);
	minus += (s - cow[c - 1]);
	for (int i = 0; i < m - 1; ++i)
	{
		minus += middle[i].len;
	}
	
	cout << (s - minus) << endl;

}

bool Cmp(const Inter& n1, const Inter& n2)
{
	if (n1.len > n2.len)
	{
		return true;
	}
	else
	{
		return false;
	}
}