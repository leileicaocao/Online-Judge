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

// �Ÿ���
const int CLOCKNUM = 9;

// ÿһ�������ʱ��
int clocks[CLOCKNUM];

// 9��������ÿ��������Ӧ�ı�
int opr[CLOCKNUM][5] = 
{
	0, 1, 3, 4,-1,
	0, 1, 2, -1, -1,
	1, 2, 4, 5, -1,
	0, 3, 6, -1, -1,
	1, 3, 4, 5, 7,
	2, 5, 8, -1, -1,
	3, 4, 6, 7, -1,
	6, 7, 8, -1, -1,
	4, 5, 7, 8, -1
};

/*
	��ӳ�䣺
	3->0
	6->1
	9->2
	12->3	
	˳ʱ����ת90�Ⱥ�
	(i + 3) % 12
*/


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

/*
	BFS
*/
void BFS();

/*
	�ж��Ƿ��ǽ��
*/
bool IsAnswer(int *curClock);

/*
	��ӡ���
*/
void PrintAnser(string str);

/*
	������ת��Ϊ����
*/
unsigned VecToInt(int *curClock);



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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.4.2 The Clocks/input9.txt";
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
	for (int i = 0; i < CLOCKNUM; ++i)
	{
		cin >> num;
		if (num == 12)
		{
			clocks[i] = 0;
		}
		else
		{
			clocks[i] = num;
		}
	}
	BFS();


}

void BFS()
{
	int *curClock;
	string str;

	queue<int *> qNum;;
	qNum.push(clocks);

	// ������
	queue<string> qRes;
	qRes.push("");

	// ״̬set
	set<int> states;
	unsigned num = VecToInt(clocks);
	states.insert(num);

	while (!qNum.empty())
	{
		curClock = qNum.front();
		qNum.pop();

		str = qRes.front();
		qRes.pop();
		// 1.����ǽ��
		if (IsAnswer(curClock))
		{
			// ��ӡ���
			PrintAnser(str);
			// �����ڴ�
			while (!qNum.empty())
			{
				curClock = qNum.front();
				qNum.pop();
				delete []curClock;
			}
			return;
		}
		// 2.�Ե�ǰclock����1��9�ı任
		for (int i = 0; i < CLOCKNUM; ++i)
		{
			int *newClock = new int[CLOCKNUM];
			memcpy(newClock, curClock, sizeof(int) * CLOCKNUM);
			string newStr = str;
			for (int j = 0; j < 5; ++j)
			{
				int index = opr[i][j];
				if (index == -1)
				{
					break;
				}
				newClock[index] = (newClock[index] + 3) % 12;
			}
			// ���û�����״̬���ż���
			unsigned curState = VecToInt(newClock);
			if (states.find(curState) == states.end())
			{				
				qNum.push(newClock);
				newStr.append(1, ('1' + i));
				qRes.push(newStr);
				states.insert(curState);
			}
			else
			{
				//cout << "exist" << endl;
				// �ͷ��ڴ氡
				delete []newClock;
			}
		}
	}
	
	// �ͷ��ڴ�
	delete []curClock;
}

// ֻ��ȫ��0���ǽ��
bool IsAnswer(int *curClock)
{
	for (int i = 0; i < CLOCKNUM; ++i)
	{
		if (curClock[i] != 0)
		{
			return false;
		}
	}
	return true;
}

void PrintAnser(string str)
{
	cout << str[0];
	for (int i = 1; i < str.length(); ++i)
	{
		cout << ' ' << str[i];
	}
	cout << endl;
}

unsigned VecToInt(int *curClock)
{
	unsigned ans = 0;
	for (int i = 0; i < CLOCKNUM; ++i)
	{
		ans = ans * 10 + curClock[i];
	}
	return ans;
}