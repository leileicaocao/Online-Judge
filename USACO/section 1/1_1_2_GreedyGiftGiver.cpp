#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define _MY_DEBUG_

const int MAXV = 11;

// person name;
string names[MAXV];
// ����
int output[MAXV];
// ����
int input[MAXV];





/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

int FindIndexByStr(int numPerson, string str);


int main()
{
	MainStructure();
	return 0;
}

void MainStructure()
{
	
#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.1.2 Greedy Gift Givers/gift1.in9";
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
	int count = 0;
	string str;
	while (getline(cin, str))
	{
		if (str == "")
		{
			break;
		}
		int numPerson = 0;
		stringstream ss(str);
		ss >> numPerson;
		for (int i = 0; i < numPerson; ++i)
		{
			cin >> names[i];
		}
		for (int i = 0; i < numPerson; ++i)
		{
			string curName;
			cin >> curName;
			int curIndex = FindIndexByStr(numPerson, curName);
			// ׼���ͳ�ȥ��Ǯ
			int price = 0;
			// ����
			int num = 0;
			// ÿ����Ҫ�õ���Ǯ
			cin >> price >> num;
			if (price == 0 || num == 0)
			{
				continue;
			}
			int singleMoney = price / num;

			// �ͳ�ȥ��Ǯ��
			output[curIndex] -= singleMoney * num;
			
			for (int j = 0; j < num; ++j)
			{
				string friendName;
				cin >> friendName;
				int friendIndex = FindIndexByStr(numPerson, friendName);
				output[friendIndex] += singleMoney;
			}
		}
		if (count)
		{
			cout << endl;
		}
		++count;

		for (int i = 0; i < numPerson; ++i)
		{
			
			cout << names[i] << ' ' << (output[i]) << endl;
		}
		//cin.ignore();
	}

}

int FindIndexByStr(int numPerson, string str)
{
	for (int i = 0; i < numPerson; ++i)
	{
		if (names[i] == str)
		{
			return i;
		}
	}
	return -1;
}