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

/*
	Ѱ����һ��
*/
int NextChar(int cur, int step, string &word);

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
	string inputStr = "C:/Users/cao/Desktop/�㷨/USACO/USACOȫ����������/1.3.3 Calf Flac/input8.txt";
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
	string words;
	string str;
	while (getline(cin, str))
	{
		words += str;
		//words += '\n';
	}
	//cout << words << endl;
	int maxLen = 0;
	int start = 0;
	int end = 0;

	int length = words.length();
	// ��iΪ���ģ���������չ
	for (int i = 0; i < length; ++i)
	{
		// �������
		if (!isalpha(words[i]))
		{
			continue;
		}
		int cur1 = 1;
		int cur1Start = i;
		int cur1End = i;
		

		// ����һ��Ϊ����
		while (true)
		{
			int left = NextChar(cur1Start - 1, -1, words);
			int right = NextChar(cur1End + 1, 1, words);
			if ((left == -1) || (right == -1))
			{
				break;
			}
			if (tolower(words[left]) == tolower(words[right]))
			{
				cur1 += 2;
				cur1Start = left;
				cur1End = right;
			}
			else
			{
				break;
			}
		}
		// ���������ұߵ�Ϊ����
		int cur2 = 1;
		int cur2Start = i;
		int cur2End = NextChar(i + 1, 1, words);
		if (cur2End != -1)
		{
			if (tolower(words[cur2Start]) == tolower(words[cur2End]))
			{
				++cur2;
				while (true)
				{
					int left = NextChar(cur2Start - 1, -1, words);
					int right = NextChar(cur2End + 1, 1, words);
					if ((left == -1) || (right == -1))
					{
						break;
					}
					if (tolower(words[left]) == tolower(words[right]))
					{
						cur2 += 2;
						cur2Start = left;
						cur2End = right;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (cur2 > cur1)
		{
			cur1 = cur2;
			cur1Start = cur2Start;
			cur1End = cur2End;
		}
		if (cur1 > maxLen)
		{
			maxLen = cur1;
			start = cur1Start;
			end = cur1End;
		}
	}
	cout << maxLen << endl;
	cout << words.substr(start, end - start + 1) << endl;

}

int NextChar(int cur, int step, string &word)
{
	int len = word.length();
	while (cur >= 0 && cur < len)
	{
		if (isalpha(word[cur]))
		{
			return cur;
		}
		cur += step;
	}
	return -1;
}