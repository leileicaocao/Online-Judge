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

const int MAXV = 11;
// ��ʼͼ��
char initTile[MAXV][MAXV];

// Ŀ��ͼ��
char resultTile[MAXV][MAXV];

// �м�ͼ��
char middleTile[MAXV][MAXV];


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();


/*
	1������ʼͼ��˳ʱ��90�ȷ�ת
*/
bool Transform1(char start[][MAXV], char to[][MAXV], int num);

/*
	2������ʼͼ��˳ʱ��180�ȷ�ת
*/
bool Transform2(char start[][MAXV], char to[][MAXV], int num);

/*
	3������ʼͼ��˳ʱ��270�ȷ�ת
*/
bool Transform3(char start[][MAXV], char to[][MAXV], int num);

/*
	4������
*/
bool Transform4(char start[][MAXV], char to[][MAXV], int num);

/*
	5������
*/
bool Transform5(char start[][MAXV], char to[][MAXV], int num);


/*
	�ж����������Ƿ���ͬ
*/
bool IsTwoImageEqual(char start[][MAXV], char to[][MAXV], int num);

/*
	��ӡ���������
*/
void PrintImage(char start[][MAXV], int num);


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.2.2 Transformations/input8.txt";
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
	// ��¼@�������������@��һ������һ�����ܳɹ�
	int startCount = 0;
	int toCount = 0;
	char ch;
	// ������ʼͼ��
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{
			cin >> ch;
			initTile[i][j] = ch;
			if (ch == '@')
			{
				++startCount;
			}
		}
	}
	// ����Ŀ��ͼ��
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{
			cin >> ch;
			resultTile[i][j] = ch;
			if (ch == '@')
			{
				++toCount;
			}
		}
	}
	if (startCount != toCount)
	{
		cout << 7 << endl;
		return;
	}
	if (Transform1(initTile, middleTile, num))
	{
		cout << 1 << endl;
		return;
	}
	if (Transform2(initTile, middleTile, num))
	{
		cout << 2 << endl;
		return;
	}
	if (Transform3(initTile, middleTile, num))
	{
		cout << 3 << endl;
		return;
	}
	if (Transform4(initTile, middleTile, num))
	{
		cout << 4 << endl;
		return;
	}
	if (Transform5(initTile, middleTile, num))
	{
		cout << 5 << endl;
		return;
	}
	if (IsTwoImageEqual(initTile, resultTile, num))
	{
		cout << 6 << endl;
		return;
	}

	cout << 7 << endl;

}


/*
	1������ʼͼ��˳ʱ��90�ȷ�ת
*/
bool Transform1(char start[][MAXV], char to[][MAXV], int num)
{

//PrintImage(start, num);
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{
			to[j][num + 1 - i] = start[i][j];
		}
	}
//PrintImage(to, num);

	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}
	return false;
}

bool Transform2(char start[][MAXV], char to[][MAXV], int num)
{

//PrintImage(start, num);
	// ��ʱ����
	char tmpTile[MAXV][MAXV];	
	memcpy(tmpTile, start, MAXV * MAXV);
//PrintImage(tmpTile, num);
	// ˳ʱ����ת90
	Transform1(tmpTile, to, num);
	Transform1(to, tmpTile, num);
	// �����������middleTile��
	memcpy(to, tmpTile, MAXV * MAXV);

//PrintImage(to, num);
	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}
	return false;
}

bool Transform3(char start[][MAXV], char to[][MAXV], int num)
{
//PrintImage(start, num);

	// ��ʱ����
	char tmpTile[MAXV][MAXV];
	memcpy(tmpTile, start, MAXV * MAXV);
	// ˳ʱ����ת90
	Transform1(tmpTile, to, num);
	Transform1(to, tmpTile, num);
	Transform1(tmpTile, to, num);

//PrintImage(to, num);
	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}
	return false;
	
}

bool Transform4(char start[][MAXV], char to[][MAXV], int num)
{
//PrintImage(start, num);

	memcpy(to, start, MAXV * MAXV);

	int middle = num / 2;
	for (int j = 1; j <= middle; ++j)
	{
		for (int i = 1; i <= num; ++i)
		{			
			to[i][j] = start[i][num + 1 - j];
			to[i][num + 1 - j] = start[i][j];
		}
	}

//PrintImage(to, num);

	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}
	return false;
}

/*
	5������
*/
bool Transform5(char start[][MAXV], char to[][MAXV], int num)
{
	// ��ʱ����
	char tmpTile[MAXV][MAXV];
	// ����
	Transform4(start, tmpTile, num);

	Transform1(tmpTile, to, num);
	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}
	
	Transform2(tmpTile, to, num);
	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}

	Transform3(tmpTile, to, num);
	if (IsTwoImageEqual(to, resultTile, num))
	{
		return true;
	}

	return false;
}

bool IsTwoImageEqual(char start[][MAXV], char to[][MAXV], int num)
{
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{			
			if (start[i][j] != to[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void PrintImage(char start[][MAXV], int num)
{
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= num; ++j)
		{			
			cout << start[i][j];
		}
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}