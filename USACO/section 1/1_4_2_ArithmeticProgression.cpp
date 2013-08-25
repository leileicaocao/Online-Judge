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


using namespace std;

#define _MY_DEBUG_

const int MAXV = 130000;
bool bitMap[MAXV];

int nums[MAXV];

struct Node
{
	int start;
	int diff;
};

// ������
vector<Node> ans;


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

/*
	�������
*/
bool CMP(const Node &n1, const Node &n2);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.4.3 Arithmetic Progressions/input9.txt";
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
	bool hasAnswer = false;
	int len = 0;
	int upNum = 0;
	cin >> len >> upNum;
	for (int i = 0; i <= upNum; ++i)
	{
		for (int j = i; j <= upNum; ++j)
		{
			int cur = i * i + j * j;
			bitMap[cur] = true;
		}
	}
	int index = 0;
	for (int i = 0; i < MAXV; ++i)
	{
		if (bitMap[i])
		{
			nums[index++] = i;
		}
	}

	int maxNum = nums[index - 1];

	for (int i = 0; i < index; ++i)
	{
		for (int j = i + 1; j < index; ++j)
		{
			int start = nums[i];
			int diff = nums[j] - start;
			if (start + diff * (len - 1) > maxNum)
			{
				break;
			}
			bool isOK = true;
			for (int k = 1; k < len; ++k)
			{
				int cur = start + k * diff;
				if (!bitMap[cur])
				{
					isOK = false;
					break;
				}
			}
			if (isOK)
			{
				//cout << start << ' ' << diff << endl;
				Node n;
				n.start = start;
				n.diff = diff;
				ans.push_back(n);
				hasAnswer = true;
			}
		}	
	}

	if (!hasAnswer)
	{
		cout << "NONE" << endl;
	}
	else
	{
		// ����
		sort(ans.begin(), ans.end(), CMP);
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i].start << ' ' << ans[i].diff << endl;				 
		}
	}
}


bool CMP(const Node &n1, const Node &n2)
{
	if (n1.diff < n2.diff)
	{
		return true;
	}
	else
	{
		if (n1.diff > n2.diff)
		{
			return false;
		}
		else
		{
			if (n1.start < n2.start)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}