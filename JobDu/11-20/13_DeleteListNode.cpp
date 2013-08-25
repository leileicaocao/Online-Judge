#include <iostream>

#include "13_DeleteListNode.h"

using namespace std;


void DeleteListNode(ListNode *pHead, ListNode *pNode)
{
	if (pHead == NULL || pNode == NULL)
	{
		throw std::exception("Invalid Input");
	}
	// �����β���ڵ��أ�����pNode������β���ڵ�
	if (pNode->next == NULL)
	{
		throw std::exception("delete node is the tail node");
	}
	ListNode *pDel = pNode->next;
	pNode->key = pDel->key;
	pNode->next = pDel->next;
	// ��Ϊ����new�����ģ������޷�ʹ��delete������ڴ档���ú���ֱ�ӵ���ջ��OK��
	//delete pDel;
}
void Test_13_DeleteListNode()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	DeleteListNode(&n1, &n3);
	DeleteListNode(&n1, &n1);

}