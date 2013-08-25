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

inline int OneCount(unsigned num)
{
	int ans = 0;
	while (num)
	{
		ans += (num & 1);
		num >>= 1;
	}
	return ans;
}


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.2.2 Stringsobits/input10.txt";
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
	unsigned len, limit, count;
	cin >> len >> limit >> count;
	unsigned num = (unsigned)(pow((double)2, (double)len)) - 1;

	unsigned index = 0;
	for (unsigned i = 0; i <= num; ++i)
	{
		// ���㡮1���ĸ���
		if (OneCount(i) <= limit)
		{
			++index;
			if (index >= count)
			{
				string res;
				int curLen = 0;
				while (i)
				{
					char ch = '0';
					if (i & 1)
					{
						ch = '1';
					}
					i >>= 1;
					res.insert(0, 1, ch);
					++curLen;
				}
				while (curLen < len)
				{
					res.insert(0, 1, '0');
					++curLen;
				}
				cout << res << endl;
				break;
			}
		}
	}
}


