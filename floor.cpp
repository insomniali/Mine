#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Lei::Lei()														//���캯��
{
	
}

Lei::~Lei()														//��������
{
	
}

void Lei::Set_Lei()
{
							
	srand((unsigned)time(NULL));
	int flag = 0;
	for (int row = 0; row < 9; row++) {
		int seed = 0;
		while (flag != 3)
		{
			seed = rand() % 9;
			while (mine[row][seed] != 0) {
				seed = rand() % 9;
			}
			mine[row][seed] = 9;
			flag++;
		}
		flag = 0;
	}
	return ;
}


void Lei::Draw_Floor()											//��ӡ�Ź���
{
	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout <<   "��";
			if (8 == j)
				cout << endl;
		}
	}
	return;
}

void Lei::Draw_Num()											//��ӡ�Ź������֣��ɿ���ը������λ�ã����Բ��Եĺ�����������ע�ͣ��������������ģʽ
{
	cout << endl<<endl<< endl << endl << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << mine[i][j]<<" ";
			if (8 == j)
				cout << endl;
		}
	}
	return;
}

void Lei::Lei_Travel() {
	int row = 1, line = 1;
	int mark = 0;
	if (mine[0][0] != 9) {                                    //���Ͻ�
		if (mine[0][1] == 9)
		{
			mark++;
		}
		if (mine[1][1] == 9)
		{
			mark++;
		}
		if (mine[1][0] == 9)
		{
			mark++;
		}
		mine[0][0] = mark;
		mark = 0;
	}
	if (mine[0][8] != 9) {                           //���Ͻ�
		if (mine[0][7] == 9)
		{
			mark++;
		}
		if (mine[1][7] == 9)
		{
			mark++;
		}
		if (mine[1][8] == 9)
		{
			mark++;
		}
		mine[0][8] = mark;
		mark = 0;
	} 
	if (mine[8][0] != 9) {                      //���½�
		if (mine[7][0] == 9)
		{
			mark++;
		}
		if (mine[7][1] == 9)
		{
			mark++;
		}
		if (mine[8][1] == 9)
		{
			mark++;
		}
		mine[8][0] = mark;
		mark = 0;
	}
	if (mine[8][8] != 9) {                      //���½�
		if (mine[7][8] == 9)
		{
			mark++;
		}
		if (mine[7][7] == 9)
		{
			mark++;
		}
		if (mine[8][7] == 9)
		{
			mark++;
		}
		mine[8][8] = mark;
		mark = 0;
	}
	row = 0; line = 1;                                   //��һ��
	for (; line < 8; line++) {
		if (mine[row][line] != 9) {                      
			if (mine[row][line-1] == 9)
			{
				mark++;
			}
			if (mine[row][line+1] == 9)
			{
				mark++;
			}
			if (mine[row+1][line-1] == 9)
			{
				mark++;
			}
			if (mine[row + 1][line] == 9)
			{
				mark++;
			}
			if (mine[row + 1][line + 1] == 9)
			{
				mark++;
			}
			mine[row][line] = mark;
			mark = 0;
		}
	}
	row = 8; line = 1;                                   //�ھ���
	for (; line < 8; line++) {
		if (mine[row][line] != 9) {
			if (mine[row][line - 1] == 9)
			{
				mark++;
			}
			if (mine[row][line + 1] == 9)
			{
				mark++;
			}
			if (mine[row - 1][line - 1] == 9)
			{
				mark++;
			}
			if (mine[row - 1][line] == 9)
			{
				mark++;
			}
			if (mine[row - 1][line + 1] == 9)
			{
				mark++;
			}
			mine[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 0;                                   //��һ��
	for (; row < 8; row++) {
		if (mine[row][line] != 9) {
			if (mine[row-1][line] == 9)
			{
				mark++;
			}
			if (mine[row+1][line] == 9)
			{
				mark++;
			}
			if (mine[row + 1][line + 1] == 9)
			{
				mark++;
			}
			if (mine[row][line+1] == 9)
			{
				mark++;
			}
			if (mine[row - 1][line + 1] == 9)
			{
				mark++;
			}
			mine[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 8;                                   //�ھ���
	for (; row < 8; row++) {
		if (mine[row][line] != 9) {                      
			if (mine[row-1][line] == 9)
			{
				mark++;
			}
			if (mine[row+1][line] == 9)
			{
				mark++;
			}
			if (mine[row-1][line-1] == 9)
			{
				mark++;
			}
			if (mine[row][line-1] == 9)
			{
				mark++;
			}
			if (mine[row + 1][line - 1] == 9)
			{
				mark++;
			}
			mine[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 1;             //�ڲ�7x7����
	for (; row < 8; row++) {
		for (; line < 8; line++) {
			if (mine[row][line] != 9) {
				if (mine[row - 1][line - 1] == 9)
				{
					mark++;
				}
				if (mine[row - 1][line ] == 9)
				{
					mark++;
				}
				if (mine[row - 1][line + 1] == 9)
				{
					mark++;
				}
				if (mine[row ][line - 1] == 9)
				{
					mark++;
				}
				if (mine[row ][line + 1] == 9)
				{
					mark++;
				}
				if (mine[row + 1][line - 1] == 9)
				{
					mark++;
				}
				if (mine[row + 1][line ] == 9)
				{
					mark++;
				}
				if (mine[row + 1][line + 1] == 9)
				{
					mark++;
				}
				mine[row][line] = mark;
				mark = 0;
			}
		}
		line = 1;
	}
	return;
}