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

// �ֵ����ֵ������
const int MAXV = 5001;
// �ֻ��ϵļ�ֵ��һ��8������2��9
const int KEYNUM = 8;

// �ֵ�
string dict[MAXV];
// �ֵ��ж��ڵ�����
long long dictNum[MAXV];


char Map[KEYNUM][3] =
{
	'A', 'B', 'C',
	'D', 'E', 'F',
	'G', 'H', 'I',
	'J', 'K', 'L',
	'M', 'N', 'O',
	'P', 'R', 'S',
	'T', 'U', 'V',
	'W', 'X', 'Y'	
};




/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

/*
	ͨ����ĸ��������
*/
int CharToNumber(char ch);

/*
	word����������
*/
long long WordToNumber(string word);

// ��ӡ�ֵ�
void PrintDict(int count);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.2.3 Name That Number/input15.txt";
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
	// �����ֵ�
	ifstream fDict("C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.2.3 Name That Number/dict.txt");
	int count = 0;
	string word;
	while (fDict >> word)
	{
		dict[count++] = word;		
	}
	//PrintDict(count);
	// ����
	sort(dict, dict + count);

	//PrintDict(count);

	// ����word��Ӧ������
	for (int i = 0; i < count; ++i)
	{
		//long long tmp = WordToNumber(dict[i]);
		dictNum[i] = WordToNumber(dict[i]);
	}
	bool hasResult = false;
	long long fromNum;
	cin >> fromNum;
	for (int i = 0; i < count; ++i)
	{
		if (dictNum[i] == fromNum)
		{
			cout << dict[i] << endl;
			hasResult = true;
		}
	}
	if (!hasResult)
	{
		cout << "NONE" << endl;
	}
}


int CharToNumber(char ch)
{
	for (int i = 0;i < KEYNUM; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Map[i][j] == ch)
			{
				return (i + 2);
			}
		}
	}
	return -1;
}

long long WordToNumber(string word)
{
	long long ans = 0;
	int len = word.length();
	for (int i = 0; i < len; ++i)
	{
		int num = CharToNumber(word[i]);
		ans = ans * 10 + num;
	}
	return ans;
}

void PrintDict(int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << dict[i] << endl;
	}
	cout << "-------------------------------------" << endl;
}