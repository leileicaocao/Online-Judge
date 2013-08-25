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

using namespace std;

#define _MY_DEBUG_

// ����farmer��
const int MAXV = 6001;
// 
struct Farmer
{
	// ����
	int price;
	// ��Ӧ��
	int amount;
};

// ��������ũ����
Farmer farmers[MAXV];

/*
	MainStructure: ���ṹ
*/
void MainStructure();

/*
	Process������ÿһ������
*/
void Process();

/*
	������
*/
bool Cmp(const Farmer &f1, const Farmer &f2);


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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.3.1 Mixing Milk/milk.in6";
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
	int total;
	// ũ������Ŀ
	int farmNum;
	cin >> total >> farmNum;
	for (int i = 0; i < farmNum; ++i)
	{
		cin >> farmers[i].price >> farmers[i].amount;
	}
	// ���ռ۸�ӵ͵�������,����۸���ȣ��������Ӵ�С
	sort(farmers, farmers + farmNum, Cmp);
	// �ܻ���
	int cost = 0;
	for (int i = 0; i < farmNum; ++i)
	{
		if (total >= farmers[i].amount)
		{
			cost += farmers[i].amount * farmers[i].price;
			total -= farmers[i].amount;
		}
		else
		{
			cost += total * farmers[i].price;
			break;
		}
	}
	cout << cost << endl;

}

//bool Cmp(const Farmer &f1, const Farmer &f2)
//{
//	if (f1.price < f2.price)
//	{
//		return true;
//	}
//	else if (f1.price > f2.price)
//	{
//		return false;
//	}
//	else
//	{
//		if (f1.amount >= f2.amount)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}

bool Cmp(const Farmer &f1, const Farmer &f2)
{
	if (f1.price < f2.price)
	{
		return true;
	}
	else 
	{
		return false;
	}
}