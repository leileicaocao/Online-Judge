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

const int MAXV = 101;

char mMap[MAXV][MAXV];

char tmpMap[MAXV][MAXV];

int dirMap[4][2] = 
{
	-1, 0,
	0, 1,
	1, 0,
	0, -1
};


/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

int DFS(int posx, int posy, int dir, int row, int col, int energy, int singleEnergy, int ans);

int DFSHelper(int posx, int posy, int dir, int row, int col, int energy, 
	int singleEnergy, int ans, char type);


void FindWater(int posx, int posy, int &waterX, int waterY, int row, int col);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/3.1.6 Stamps/1.txt";
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
	int row, col, energyNum, initEnergy;
	while (cin >> row >> col >> energyNum >> initEnergy)
	{
		if (row == 0 && col == 0 && energyNum == 0 && initEnergy == 0)
		{
			break;
		}
		// ��Χ
		memset(mMap, '|', sizeof(mMap));
		// Ģ����
		int roomNum = 0;
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				char ch;
				cin >> ch;
				mMap[i][j] = ch;
				if (ch == '$')
				{
					++roomNum;
				}
			}
		}

		int best = 0;
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					memcpy(tmpMap, mMap, sizeof(mMap));
					char ch = tmpMap[i][j];
					if ((ch == '#') ||
						(ch >= '0' && ch <= '9'))
					{
						continue;
					}					
							
					int cur = DFS(i, j, k, row, col, initEnergy, energyNum, 0);
					if (cur > best)
					{
						best = cur;
					}			
				}
			}
		}
		cout << best << endl;
	}	
}

int DFS(int posx, int posy, int dir, int row, int col, int energy, int singleEnergy, int ans)
{
	char ch = tmpMap[posx][posy];
	if (energy <= 0 && ch != '$')
	{		
		return ans;
	}
	// ��������ۣ�
	// .�հ�
	// $Ģ��
	if (ch == '$')
	{		
		tmpMap[posx][posy] = '.';
		return DFSHelper(posx, posy, dir, row, col, energy, singleEnergy, ans + 1, '$');
	}
	if (ch == '.')
	{
		return DFSHelper(posx, posy, dir, row, col, energy, singleEnergy, ans, '.');
	}
	if (isupper(ch))
	{ // Aˮ��
		int waterX = 0;
		int waterY = 0;
		FindWater(posx, posy, waterX, waterY, row, col);
		// ʹ��ˮ��
		return DFS(waterX, waterY, dir, row, col, energy - 1, singleEnergy, ans);
		// ��ʹ��ˮ��
		return DFSHelper(posx, posy, dir, row, col, energy, singleEnergy, ans, '.');
	}
	if (isdigit(ch))
	{ // 1����
		int num = ch - '0';
		int newX = posx + dirMap[dir][0] * num;
		int newY = posx + dirMap[dir][1] * num;
		char newCh = tmpMap[newX][newY];
		if (newCh == '#' || newCh == '|')
		{
			return ans;
		}
		return DFS(newX, newY, dir, row, col, energy, singleEnergy, ans);
	}
	return -1;
}

void FindWater(int posx, int posy, int &waterX, int waterY, int row, int col)
{
	waterX = -1;
	waterY = -1;
	char ch = tmpMap[posx][posy];
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			if (tmpMap[i][j] == ch)
			{
				if (i != posx || j != posy)
				{
					waterX = i;
					waterY = j;
					break;
				}
			}
		}
	}
}


int DFSHelper(int posx, int posy, int dir, int row, int col, int energy, 
	int singleEnergy, int ans, char type)
{
	// ��4��������չ
	for (int i = 0; i < 4; ++i)
	{
		int newX = posx + dirMap[i][0];
		int newY = posy + dirMap[i][1];
		char newCh = tmpMap[newX][newY];
		if (newCh != '#' && newCh != '|')
		{ // ������չ
			if (type == '$')
			{
				return DFS(newX, newY, i, row, col, energy + singleEnergy - 1, singleEnergy, ans);
			}
			if (type == '.')
			{
				return DFS(newX, newY, i, row, col, energy - 1, singleEnergy, ans);
			}
		}
	}
	return -1;
}