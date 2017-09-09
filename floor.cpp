#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>


using namespace std;

Lei::Lei()														//���캯��
{
	
}

Lei::~Lei()														//��������
{
	
}

//void Lei::Set_Mine()
//{
//	for(int i = 0; i < Floor_Row; i++)
//	{
//		for (int j = 0; j < Floor_Col; j++)
//		{
//			point[i][j].Mine_Num = 0;  
//			point[i][j].Has_Mine = false;
//			point[i][j].Is_Dug = false;
//		}
//
//	}
//	srand((unsigned)time(NULL));										//�������������
//	int count = 0;														//���õ�ǰ��������
//	int Mine[Mine_Number];												//���õ��׼���40�����ף�
//	while(count < Mine_Number)
//	{
//		if (0 == count)												
//			Mine[0] = rand() % (Floor_Row * Floor_Col);					//����0-256�����������ʽ�ٶ���
//		else
//		{
//			Mine[count] = rand() % (Floor_Row * Floor_Col);
//		}
//		count++;
//	}
//
//	for(int i = 0; i < Mine_Number; i++)
//	{
//		point[Mine[i] / Floor_Row == 0 ? 0 : Mine[i] / Floor_Row - 1][Mine[i] - 1].Has_Mine = true;		//ʹ����Ŀ�������������λ�ö�Ӧ����ͼ��
//	}
//						
//
//	
//}


void Lei::Draw_Floor()											
{
	IMAGE cell, none, mine, number;
	loadimage(&cell,_T("./IMAGE/cell.jpg"));
	loadimage(&none, _T("./IMAGE/s.jpg"));
	for(int i = 0;i < Floor_Row; i++)
	{
		for (int j = 0; j < Floor_Col; j++)
		{
			putimage(i * Picture_Width, j * Picture_Width, &cell);
			putimage(i * Picture_Width, j * Picture_Width, &none);
		}
			
	}


}


void Lei::Draw_Text()
{
	TCHAR message[] = _T("This is a game about Mine");						//Ҫ���������
	RECT rect = { 250,100,550,200 };										//�������Χ
	LOGFONT font;															//�������壨�ṹ�壩
	COLORREF color = RGB(200,128,37);										//���õ�ǰ������ɫ
	setcolor(color);														//�޸ĵ�ǰ������ɫ
	gettextstyle(&font);													//��ȡ��ǰ������Ϣ
	font.lfHeight = 22;														//���õ�ǰ����߶�Ϊ16
	font.lfWidth = 0;														//���õ�ǰ����������Ӧ
	font.lfWeight = 400;													//���õ�ǰ����ʻ���ϸ
	font.lfItalic = true;													//���õ�ǰ����Ϊб��
	wcscpy_s(font.lfFaceName, _T("����"));									//���õ�ǰ����Ϊ����
	settextstyle(&font);													//��������޸�����
	drawtext(message, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);		//��ָ�����η�Χ�ھ������
}


void Lei::Set_Mine() {
	srand((unsigned)time(NULL));
	int flag = 0;
	for (int row = 0; row < 16; row++) {
		int seed = 0;
		while (flag != 4)
		{
			seed = rand() % 16;
			while (point[row][seed] != 0) {
				seed = rand() % 16;
			}
			point[row][seed] = 9;
			flag++;
		}
		flag = 0;
	}
	return;
}

void Lei::Lei_Travel() {
	int row = 1, line = 1;
	int mark = 0;
	if (point[0][0] != 9) {                                    //���Ͻ�
		if (point[0][1] == 9)
		{
			mark++;
		}
		if (point[1][1] == 9)
		{
			mark++;
		}
		if (point[1][0] == 9)
		{
			mark++;
		}
		point[0][0] = mark;
		mark = 0;
	}
	if (point[0][Floor_Col - 1] != 9) {                           //���Ͻ�
		if (point[0][Floor_Col - 2] == 9)
		{
			mark++;
		}
		if (point[1][Floor_Col - 2] == 9)
		{
			mark++;
		}
		if (point[1][Floor_Col - 1] == 9)
		{
			mark++;
		}
		point[0][Floor_Col - 1] = mark;
		mark = 0;
	}
	if (point[Floor_Row - 1][0] != 9) {                      //���½�
		if (point[Floor_Row - 2][0] == 9)
		{
			mark++;
		}
		if (point[Floor_Row - 2][1] == 9)
		{
			mark++;
		}
		if (point[Floor_Row - 1][1] == 9)
		{
			mark++;
		}
		point[Floor_Row - 1][0] = mark;
		mark = 0;
	}
	if (point[Floor_Row - 1][Floor_Col - 1] != 9) {                      //���½�
		if (point[Floor_Row - 2][Floor_Col - 1] == 9)
		{
			mark++;
		}
		if (point[Floor_Row - 2][Floor_Col - 1] == 9)
		{
			mark++;
		}
		if (point[Floor_Row - 1][Floor_Col - 1] == 9)
		{
			mark++;
		}
		point[Floor_Row - 1][Floor_Col - 1] = mark;
		mark = 0;
	}
	row = 0; line = 1;                                   //��һ��
	for (; line < Floor_Col - 1; line++) {
		if (point[row][line] != 9) {
			if (point[row][line - 1] == 9)
			{
				mark++;
			}
			if (point[row][line + 1] == 9)
			{
				mark++;
			}
			if (point[row + 1][line - 1] == 9)
			{
				mark++;
			}
			if (point[row + 1][line] == 9)
			{
				mark++;
			}
			if (point[row + 1][line + 1] == 9)
			{
				mark++;
			}
			point[row][line] = mark;
			mark = 0;
		}
	}
	row = 15; line = 1;                                   //�ھ���
	for (; line < 15; line++) {
		if (point[row][line] != 9) {
			if (point[row][line - 1] == 9)
			{
				mark++;
			}
			if (point[row][line + 1] == 9)
			{
				mark++;
			}
			if (point[row - 1][line - 1] == 9)
			{
				mark++;
			}
			if (point[row - 1][line] == 9)
			{
				mark++;
			}
			if (point[row - 1][line + 1] == 9)
			{
				mark++;
			}
			point[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 0;                                   //��һ��
	for (; row < 15; row++) {
		if (point[row][line] != 9) {
			if (point[row - 1][line] == 9)
			{
				mark++;
			}
			if (point[row + 1][line] == 9)
			{
				mark++;
			}
			if (point[row + 1][line + 1] == 9)
			{
				mark++;
			}
			if (point[row][line + 1] == 9)
			{
				mark++;
			}
			if (point[row - 1][line + 1] == 9)
			{
				mark++;
			}
			point[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 15;                                   //�ھ���
	for (; row < 15; row++) {
		if (point[row][line] != 9) {
			if (point[row - 1][line] == 9)
			{
				mark++;
			}
			if (point[row + 1][line] == 9)
			{
				mark++;
			}
			if (point[row - 1][line - 1] == 9)
			{
				mark++;
			}
			if (point[row][line - 1] == 9)
			{
				mark++;
			}
			if (point[row + 1][line - 1] == 9)
			{
				mark++;
			}
			point[row][line] = mark;
			mark = 0;
		}
	}
	row = 1; line = 1;             //�ڲ�7x7����
	for (; row < 15; row++) {
		for (; line < 15; line++) {
			if (point[row][line] != 9) {
				if (point[row - 1][line - 1] == 9)
				{
					mark++;
				}
				if (point[row - 1][line] == 9)
				{
					mark++;
				}
				if (point[row - 1][line + 1] == 9)
				{
					mark++;
				}
				if (point[row][line - 1] == 9)
				{
					mark++;
				}
				if (point[row][line + 1] == 9)
				{
					mark++;
				}
				if (point[row + 1][line - 1] == 9)
				{
					mark++;
				}
				if (point[row + 1][line] == 9)
				{
					mark++;
				}
				if (point[row + 1][line + 1] == 9)
				{
					mark++;
				}
				point[row][line] = mark;
				mark = 0;
			}
		}
		line = 1;
	}
	return;
}

