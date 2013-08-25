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


using namespace std;

#define _MY_DEBUG_

const int DIRECTION_NUM = 4;

char forest[12][12];

bool used[12][12][4];

int dirMap[4][2] =
{
	-1, 0,
	0, 1,
	1, 0,
	0, -1
};

struct Node
{
	int x;
	int y;
	int direction;
	int time;

	Node(int _x, int _y, int _direction, int _time) :
	x(_x), y(_y), direction(_direction), time(_time)
	{}

};

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();


int BFS(int farmX, int farmY, int cowX, int cowY);

int Simulation(int farmX, int farmY, int cowX, int cowY);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/2.4.1 The Tamworth Two/input9.txt";
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
	for (int i = 0; i < 12; ++i)
	{
		// ���桢����
		forest[0][i] = '*';
		forest[11][i] = '*';

		for (int j = 0; j < DIRECTION_NUM; ++j)
		{
			used[0][i][j] = true;
			used[11][i][j] = true;
		}

		// ��ߡ��ұ�
		forest[i][0] = '*';
		forest[i][11] = '*';

		for (int j = 0; j < DIRECTION_NUM; ++j)
		{
			used[i][0][j] = true;
			used[i][11][j] = true;
		}
		
	}

	int farmX, farmY;
	int cowX, cowY;
	char ch;
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			cin >> ch;
			if (ch == 'C')
			{
				cowX = i;
				cowY = j;
			}
			if (ch == 'F')
			{
				farmX = i;
				farmY = j;
			}
			if (ch == '*')
			{
				for (int k = 0; k < DIRECTION_NUM; ++k)
				{
					used[i][j][k] = true;	
					forest[i][j] = '*';
				}
			}
		}
	}
	int ans = Simulation(farmX, farmY, cowX, cowY);
	if (ans != -1)
	{
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
	}

}

int BFS(int farmX, int farmY, int cowX, int cowY)
{
	int ans = 0;
	queue<Node *> q;
	Node *n = new Node(farmX, farmY, 0, 0);
	used[farmX][farmY][0] = true;
	q.push(n);

	while (!q.empty())
	{
		Node *curNode = q.front();
		q.pop();
		// �Ƿ����յ�
		if (curNode->x == cowX && curNode->y == cowY)
		{
			return curNode->time;
		}
		// ��ʼ��չ:Ҫô��ǰ�ߣ�Ҫôת����
		// ��ǰ��
		int dir = curNode->direction;
		int curX = curNode->x;
		int curY = curNode->y;
		int newX = curX + dirMap[dir][0];
		int newY = curY + dirMap[dir][1];
		// ���������չ
		if (!used[newX][newY][dir])
		{
			Node *nextNode = new Node(newX, newY, dir, curNode->time + 1);
			used[newX][newY][dir] = true;
			q.push(nextNode);
		}
		// ����ת��
		int newDir = (dir + 1) % DIRECTION_NUM;
		if (!used[curX][curY][newDir])
		{
			Node *nextNode = new Node(curX, curY, newDir, curNode->time + 1);
			used[curX][curY][newDir] = true;
			q.push(nextNode);
		}		
	}
	return -1;
}

int Simulation(int farmX, int farmY, int cowX, int cowY)
{
	int count = 0;
	int farmDir = 0;
	int cowDir = 0;
	while (count < 401)
	{
		if (farmX == cowX && farmY == cowY)
		{
			return count;
		}
		// ģ��farm
		// �Ƿ������ǰ��
		int newFarmX = farmX + dirMap[farmDir][0];
		int newFarmY = farmY + dirMap[farmDir][1];
		if (forest[newFarmX][newFarmY] != '*')
		{
			farmX = newFarmX;
			farmY = newFarmY;
		}
		else
		{ // ����ת��
			farmDir = (farmDir + 1) % DIRECTION_NUM;
		}

		// �Ƿ������ǰ��
		int newCowX = cowX + dirMap[cowDir][0];
		int newCowY = cowY + dirMap[cowDir][1];
		if (forest[newCowX][newCowY] != '*')
		{
			cowX = newCowX;
			cowY = newCowY;
		}
		else
		{ // ����ת��
			cowDir = (cowDir + 1) % DIRECTION_NUM;
		}
		++count;
	}
	return -1;
}