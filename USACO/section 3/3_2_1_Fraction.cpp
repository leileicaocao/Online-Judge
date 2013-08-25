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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.2.1 Factorials/input10.txt";
	//string inputStr = "D:/2��ս���/input/110205.inp";
	string outputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.1.5 Contact/out.txt";
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
	int ans = 1;
	
	for (int i = 2; i <= num; ++i)
	{
		ans *= i;
		while ((ans % 10) == 0)
		{
			ans /= 10;
		}

		ans %= 10000;

		//ans *= i;
	}
	while ((ans % 10) == 0)
	{
		ans /= 10;
	}
	cout << (ans % 10) << endl;
}


