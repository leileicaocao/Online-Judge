#ifndef __3_FIND_NUMBER_IN_YOUNG_MATRIX__
#define __3_FIND_NUMBER_IN_YOUNG_MATRIX__


/*
 * ������	��FindNumberInYoungMatrix
 * ����	�������Ͼ����в���һ����������������ڣ�����true��ͬʱ����row��col������
 * ����	��
 * ʱ��	��
 * ����ֵ��
	@matrix	������
	@row	�����������
	@col	�����������
	@num	�������ҵ���
	@ansRow	�����ڵ��У�������ڵĻ������򷵻�-1��
	@ansCol	�����ڵ��У�������ڵĻ������򷵻�-1��
 * ����ֵ��
	true	�������ҵ����ھ�����
	false	�������ҵ������ھ�����
 */
bool FindNumberInYoungMatrix(int *matrix, int row, int col, int num, int &ansRow, int &ansCol);

void Test_3_FindNumberInYoungMatrix();






#endif __3_FIND_NUMBER_IN_YOUNG_MATRIX__