#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define _MY_DEBUG_

// һ��7��
const int DAY_OF_WEEKDAY = 7;
// һ��12����
const int MONTH_OF_YEAR = 12;

// 13��ÿһ���ĸ���
int weekday[DAY_OF_WEEKDAY];

int months[MONTH_OF_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

// �Ƿ�������
bool IsRunYear(int year);

/*
	��������
*/
void TestRunYear();

int main()
{
	MainStructure();
	return 0;
}

void MainStructure()
{
	
#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.1.3 Friday the Thirteenth/input8.txt";
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
	//TestRunYear();
}

void Process()
{
	int year;
	cin >> year;
	// ��1990��1��0�ſ�ʼ,sunday:0,monday:1
	int totalDay = 0;

	// ����
	for (int i = 0; i < year; ++i)
	{
		// һ���12����
		for (int j = 0; j < MONTH_OF_YEAR; ++j)
		{
			totalDay += 13;
			int remain = totalDay % DAY_OF_WEEKDAY;
			++weekday[remain];

			totalDay -= 13;

			// �����2�£���������
			if (j == 1 && IsRunYear(1900 + i))
			{
				totalDay += 29;
			}
			else
			{
				totalDay += months[j];
			}
		}
	}
	// ���
	// ����
	cout << weekday[6];
	for (int i = 0; i < 6; ++i)
	{
		cout << ' ' << weekday[i];
	}
}


bool IsRunYear(int year)
{
	if (((year % 100 != 0) && (year % 4 == 0)) ||
		(year % 400 == 0))
	{
		return true;
	}
	return false;
}


void TestRunYear()
{
	cout << IsRunYear(1900) << endl;
	cout << IsRunYear(1901) << endl;
	cout << IsRunYear(1902) << endl;
	cout << IsRunYear(1903) << endl;
	cout << IsRunYear(1904) << endl;
	cout << IsRunYear(1905) << endl;
	cout << IsRunYear(2000) << endl;
}