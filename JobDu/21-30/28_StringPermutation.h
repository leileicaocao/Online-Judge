#include <iostream>
#include <string>
#include <set>

using namespace std;

void StringPermutation(string str);

void StringPermutationDFS(string str, int step);

void Test_28_StringPermutation();

// �����ַ�����ɵ����
void StringCombination(string str);

void StringCombinationDFS(string str, bool used[], string ans, int len);

void StringCombinationDFS(string str, bool used[], string ans, int len, set<string> &strSet);