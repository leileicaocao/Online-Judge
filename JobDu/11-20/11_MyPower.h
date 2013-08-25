#ifndef __MY_POWER__
#define __MY_POWER__

#include <iostream>

using namespace std;


const double EPSILON = 1e-7;

// �ж�һ�����Ƿ����0
bool IsEqualZero(double num);

double MyPower(double base, int exp);


double MyPowerHelpRecursion(double base, int exp);

double MyPowerHelpIterator(double base, int exp);

void Test_11_MyPower();

#endif