#ifndef __1_OPERATER_FUNCTION__
#define __1_OPERATER_FUNCTION__

#include <iostream>

using namespace std;

/*
	Ϊ���½ṹ���帳ֵ�����
*/

/*
 * ���ܣ��Զ����ַ����ṹ���������캯�����������캯������ֵ���캯������������
 * 
 */
  
struct CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString & str);
	// Ϊ��֧��str[i] = 
	/*
	 * ������		�� = 
	 * ����		�� caolei
	 * ����		�� 2013-08-15
	 * ����		�� ����Զ����ַ����Ŀ�����ֵ����
	 * �������
			str���������ַ���
	 * ����ֵ		�� ������ɵ��ַ��������ã�Ϊ��������ֵ������str1 = str2 = str3;
	 */
	CMyString & operator = (const CMyString & str);
	~CMyString();

private:
	/*
	 * �����洢�ַ���ָ��
	*/
	char * m_pData;
};

void Test_1_OperatorFunction();

#endif 