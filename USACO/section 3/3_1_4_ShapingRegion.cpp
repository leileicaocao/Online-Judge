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

const int COLOR_NUM = 2501;

// ���
int colCount[COLOR_NUM];


struct Rec
{
	int llx;
	int lly;
	int urx;
	int ury;
	int color;
	Rec() : llx(0), lly(0), urx(0), ury(0), color(1)
	{}
	Rec(int _llx, int _lly, int _urx, int _ury, int _color) 
		: llx(_llx), lly(_lly), urx(_urx), ury(_ury), color(_color)
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

/*
	r1����r2:0
	r1����r2:1
	r2����r1:2
	r1�ཻr2:3
	��ȫ���:4
*/
int RelationshipOfRecs(Rec *r1, Rec *r2);

/*
	���Ƿ���Rec��
*/
bool PointInRec(Rec *r, int x, int y);

// ����ʱ�ķָ���²����ķ���Set��
void SpliteEightDivide(Rec *r1, Rec *r2, set<Rec *> &tmpSet);

// �ཻʱ�ķָ���²����ķ���Set��,��r2��ȥ��r1�Ĳ���
void IntersectDivide(Rec *r1, Rec *r2, set<Rec *> &tmpSet);

// �ཻʱ�ĵ���
int IntersectPointNum(Rec *r1, Rec *r2);

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
	int col, row, rNum;
	cin >> col >> row >> rNum;

	set<Rec *> ansRec;
	Rec *initRec = new Rec(0, 0, col - 1, row - 1, 1);

	ansRec.insert(initRec);

	for (int i = 0; i < rNum; ++i)
	{
		Rec *r = new Rec();;
		cin >> r->llx >> r->lly >> r->urx >> r->ury >> r->color;
		--r->urx;
		--r->ury;

		// ��ʱ�����²�����Rec
		set<Rec *>addNewRec;
		for (set<Rec *>::iterator itr = ansRec.begin(); itr != ansRec.end(); ++itr)
		{			
			Rec *curTmp = (*itr);
			int rel = RelationshipOfRecs(r, curTmp);
			switch (rel)
			{
			case 0:
				// ���룬ʲôҲ���ô���
				break;
			case 4: // ��ȫ���			
			case 1:
				// r1����r2:1����curTmpɾ��
				delete curTmp;
				ansRec.erase(curTmp);
				break;
			case 2: // r2����r1��r1��r2���ֳ�8��С������
				SpliteEightDivide(r, curTmp, addNewRec);

				delete curTmp;
				ansRec.erase(curTmp);
				break;
			case 3: // �ཻr1��r2�ཻ����r2�е�r1ȥ��
				IntersectDivide(r, curTmp, addNewRec);
				break;			
			}
		}
		ansRec.insert(r);
		// ��anddNewRec����ansRec
		for (set<Rec *>::iterator itr = addNewRec.begin(); itr != addNewRec.end(); ++itr)
		{
			ansRec.insert(*itr);
		}
	}
	for (set<Rec *>::iterator itr = ansRec.begin(); itr != ansRec.end(); ++itr)
	{
		Rec *curTmp = (*itr);
		int w = curTmp->urx - curTmp->llx + 1;
		int h = curTmp->ury - curTmp->lly + 1;
		int color = curTmp->color;
		colCount[color] += (w * h);
	}
	for (int i = 1; i < COLOR_NUM; ++i)
	{
		if (colCount[i])
		{
			cout << i << ' ' << colCount[i] << endl;
		}
	}

}

/*
	r1����r2:0
	r1����r2:1
	r2����r1:2
	r1�ཻr2:3
	��ȫ���:4
*/
int RelationshipOfRecs(Rec *r1, Rec *r2)
{
	// ��ȫ���
	if ((r1->llx == r2->llx) &&
		(r1->lly == r2->lly) &&
		(r1->urx == r2->urx) &&
		(r1->ury == r2->ury))
	{
		return 4;
	}
	
	// r1����r2
	if ((r1->llx <= r2->llx) &&
		(r1->lly <= r2->lly) &&
		(r1->urx >= r2->urx) &&
		(r1->ury >= r2->ury))
	{
		return 1;
	}

	// r2����r1
	if ((r2->llx <= r1->llx) &&
		(r2->lly <= r1->lly) &&
		(r2->urx >= r1->urx) &&
		(r2->ury >= r1->ury))
	{
		return 2;
	}

	// r1�ཻr2
	if (PointInRec(r1, r2->llx, r2->lly) ||
		PointInRec(r1, r2->llx, r2->ury) ||
		PointInRec(r1, r2->urx, r2->lly) ||
		PointInRec(r1, r2->urx, r2->ury))
	{
		return 3;
	}
	return 0;
}

bool PointInRec(Rec *r, int x, int y)
{
	if ((x >= r->llx && x <= r->urx) &&
		(y >= r->lly && y <= r->ury))
	{
		return true;
	}
	return false;
}

void SpliteEightDivide(Rec *r1, Rec *r2, set<Rec *> &tmpSet)
{ // ������ɫ
	bool left = (r2->llx < r1->llx);
	bool down = (r2->lly < r1->lly);
	bool right = (r2->urx > r1->urx);
	bool up = (r2->ury > r1->ury);
	
	if (left)
	{
		Rec *curRec3 = new Rec(r2->llx, r1->lly, r1->llx, r1->ury, r2->color);
		tmpSet.insert(curRec3);
		if (down)
		{
			Rec *curRec1 = new Rec(r2->llx, r2->lly, r1->llx, r1->lly, r2->color);
			tmpSet.insert(curRec1);
		}		
	}
	if (down)
	{
		Rec *curRec2 = new Rec(r1->llx, r2->lly, r1->urx, r1->lly, r2->color);
		tmpSet.insert(curRec2);
	}

	if (right)
	{
		Rec *curRec3 = new Rec(r1->urx, r1->lly, r2->urx, r1->ury, r2->color);
		tmpSet.insert(curRec3);
		if (up)
		{
			Rec *curRec1 = new Rec(r1->urx, r1->ury, r2->urx, r2->ury, r2->color);
			tmpSet.insert(curRec1);
		}		
	}
	if (up)
	{
		Rec *curRec2 = new Rec(r1->llx, r1->ury, r1->urx, r2->ury, r2->color);
		tmpSet.insert(curRec2);
	}

	if (up && left)
	{
		Rec *curRec2 = new Rec(r2->llx, r1->ury, r1->llx, r2->ury, r2->color);
		tmpSet.insert(curRec2);
	}

	if (down && right)
	{
		Rec *curRec1 = new Rec(r1->urx, r2->lly, r2->urx, r1->lly, r2->color);
		tmpSet.insert(curRec1);
	}
}


void IntersectDivide(Rec *r1, Rec *r2, set<Rec *> &tmpSet)
{
	int pointNum = IntersectPointNum(r1, r2);

	bool leftLow = PointInRec(r1, r2->llx, r2->lly);
	bool leftUp = PointInRec(r1, r2->llx, r2->ury);
	bool rightLow = PointInRec(r1, r2->urx, r2->lly);
	bool rightUp = PointInRec(r1, r2->urx, r2->ury);

	if (leftLow && leftUp && rightLow && rightUp)
	{
		Rec *curRec1 = new Rec(r1->urx, r1->ury, r2->urx, r2->ury, r2->color);
		tmpSet.insert(curRec1);

		Rec *curRec2 = new Rec(r2->llx, r1->ury, r1->urx, r2->ury, r2->color);
		tmpSet.insert(curRec2);

		Rec *curRec3 = new Rec(r1->llx, r2->lly, r2->urx, r1->ury, r2->color);
		tmpSet.insert(curRec3);

	}

	if (leftLow && !leftUp && !rightLow && !rightUp)
	{
	}

	if (!leftLow && leftUp && !rightLow && !rightUp)
	{
	}

	if (!leftLow && !leftUp && !rightLow && rightUp)
	{
	}

	if (leftLow && leftUp && rightLow && rightUp)
	{
	}

	if (leftLow && leftUp && rightLow && rightUp)
	{
	}

	if (leftLow && leftUp && rightLow && rightUp)
	{
	}

	if (leftLow && leftUp && rightLow && rightUp)
	{
	}
}

int IntersectPointNum(Rec *r1, Rec *r2)
{
	return 0;
}