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

const int PRIME_NUM = 101;
const int MAXV = 100001;

unsigned prime[PRIME_NUM];

unsigned pointer[PRIME_NUM];

unsigned numbers[MAXV];

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.1.3 Humble Numbers/input8.txt";
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
	unsigned K, N;
	cin >> K >> N;

	prime[0] = 1;
	for (unsigned i = 1; i <= K; ++i)
	{
		cin >> prime[i];
	}
	sort(prime, prime + K);

	for (unsigned i = 1; i <= K; ++i)
	{
		// ÿһ������0��ʼ����
		pointer[i] = 0;
	}
	// ��0��
	numbers[0] = 1;

	for (unsigned i = 1; i <= N; ++i)
	{
		unsigned minPointer = 0x7FFFFFFF;
		unsigned index = 0;
		unsigned curMax = numbers[i - 1];
		for (unsigned j = 1; j <= K; ++j)
		{
			unsigned tmp = numbers[pointer[j]] * prime[j];
			// �ҵ���һ����curMax�����
			while (tmp <= curMax)
			{				
				tmp = numbers[++pointer[j]] * prime[j];
			}
			if (tmp < minPointer)
			{
				minPointer = tmp;
				index = j;
			}
		}
		numbers[i] = minPointer;
	}
	cout << numbers[N] << endl;
}

