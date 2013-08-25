#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;

#define _MY_DEBUG_

struct Node
{
	int start;
	int end;
};

// 
const int MAXV = 5001;
// ����ʱ���
//list <Node> work;
Node work[MAXV];


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

/*
	����
*/
bool Cmp(const Node &a, const Node &b);

int Cmp(const void *a, const void *b);



int main()
{
	MainStructure();
	//TestCmp();
	return 0;
}

void MainStructure()
{
	
#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.2.1 Milking Cows/input8.txt";
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
	// ����
	unsigned num;
	// ���æʱ��
	int maxBusy = 0;
	// �����ʱ��
	int maxRelax = 0;

	// ��ʱ����
	int start = 0;
	int end = 0;
	// ��һ��
	cin >> num;
	for (unsigned i = 0; i < num; ++i)
	{
		//Node n;
		//cin >> n.start >> n.end;
		//work.push_back(n);
		cin >> work[i].start >> work[i].end;
	}
	// ����:���տ�ʼʱ����������,�����ʼʱ����ͬ�����ս���ʱ������
	qsort((void *)work, num, sizeof(Node), Cmp);
	//sort(work.begin(), work.end(), Cmp);

	// ȥ��������Ϣ
	for (unsigned i = 0; i < num; ++i)
	{
		for (unsigned j = i + 1; j < num; ++j)
		{
			if (work[i].start <= work[j].start && work[i].end >= work[j].end)
			{
				work[j].start = -1;
				work[j].end = -1;
			}
			/*if (work..start <= work[j].start && work[i].end >= work[j].end)
			{
				work.erase(work.begin() + j);
				--j;
			}*/

		}
	}


	int curBusy = work[0].end - work[0].start;
	int curBusyStart = work[0].start;
	int lastEnd = work[0].end;

	maxBusy = curBusy;

	int curRelax = 0;

	for (unsigned i = 1; i < num; ++i)
	{
		if (work[i].start == -1)
		{
			continue;
		}
		if (work[i].start <= lastEnd)
		{
			curBusy = work[i].end - curBusyStart;
			if (curBusy > maxBusy)
			{
				maxBusy = curBusy;
			}
			lastEnd = work[i].end;
		}		
		else
		{
			curRelax = work[i].start - lastEnd;
			curBusyStart = work[i].start;
			lastEnd = work[i].end;
			if (curRelax > maxRelax)
			{
				maxRelax = curRelax;
			}
		}
	}
	cout << maxBusy << ' ' << maxRelax << endl;

}


int Cmp(const void *a, const void *b)
{
	Node *n1 = (Node *)a;
	Node *n2 = (Node *)b;
	if (n1->start != n2->start)
	{
		return (n1->start - n2->start);
	}
	return (n1->end - n2->end);
}

bool Cmp(const Node &n1, const Node &n2)
{
	if (n1.start < n2.start)
	{
		return true;
	}
	else if (n1.start > n2.start)
	{
		return false;
	}
	else
	{
		if (n1.end <= n2.end)
		{
			return true;
		}
		return false;
	}
}
