#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define _MY_DEBUG_

// �������350��
const int MAXV = 351;

char necklace[MAXV];


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();



int main()
{
	MainStructure();
	return 0;
}

void MainStructure()
{
	
#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.1.4 Broken Necklace/necklace.in7";
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
	int neckNum = 0;
	cin >> neckNum;
	for (int i = 0; i < neckNum; ++i)
	{
		cin >> necklace[i];
	}
	int maxNum = 0;

	// ���м�Ͽ����Ͽ�λ��Ϊ(i, i+1)
	for (int i = 0; i < neckNum; ++i)
	{
		int curMax = 2;

		// ��i��ǰ��
		// ���һ��ʼ���ǰ�ɫ��
		bool isStartWhite = false;
		char ch1 = necklace[i];
		if (ch1 == 'w')
		{
			isStartWhite = true;
		}

		for (int j = i - 1; ; --j)
		{
			j = (j + neckNum) % neckNum;
			if (j == i)
			{
				break;
			}

			if (isStartWhite)
			{
				ch1 = necklace[j];
				if (ch1 != 'w')
				{
					isStartWhite = false;
				}
			}
			if (necklace[j] == ch1 || necklace[j] == 'w')
			{
				++curMax;
			}
			else
			{
				break;
			}
		}
		if (curMax >= neckNum)
		{
			maxNum = neckNum;
			break;
		}

		// ��i+1�����
		isStartWhite = false;
		char ch2 = necklace[(i + 1) % neckNum];
		if (ch2 == 'w')
		{
			isStartWhite = true;
		}
		for (int j = i + 2; ; ++j)
		{
			j = j % neckNum;
			if (j == i + 1)
			{
				break;
			}
			if (isStartWhite)
			{
				ch2 = necklace[j];
				if (ch2 != 'w')
				{
					isStartWhite = false;
				}
			}
			if (necklace[j] == ch2 || necklace[j] == 'w')
			{
				++curMax;
			}
			else
			{
				break;
			}
		}
		if (curMax >= neckNum)
		{
			maxNum = neckNum;
			break;
		}
		if (curMax > maxNum)
		{
			maxNum = curMax;
		}
	}
	cout << maxNum << endl;
}


