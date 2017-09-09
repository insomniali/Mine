#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>


using namespace std;

Lei::Lei()														//构造函数
{
	
}

Lei::~Lei()														//析构函数
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
//	srand((unsigned)time(NULL));										//设置随机数种子
//	int count = 0;														//设置当前地雷数量
//	int Mine[Mine_Number];												//设置地雷集（40个地雷）
//	while(count < Mine_Number)
//	{
//		if (0 == count)												
//			Mine[0] = rand() % (Floor_Row * Floor_Col);					//设置0-256的随机数，公式百度有
//		else
//		{
//			Mine[count] = rand() % (Floor_Row * Floor_Col);
//		}
//		count++;
//	}
//
//	for(int i = 0; i < Mine_Number; i++)
//	{
//		point[Mine[i] / Floor_Row == 0 ? 0 : Mine[i] / Floor_Row - 1][Mine[i] - 1].Has_Mine = true;		//使用三目运算符，将地雷位置对应到地图中
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
	TCHAR message[] = _T("This is a game about Mine");						//要输出的内容
	RECT rect = { 250,100,550,200 };										//输出矩阵范围
	LOGFONT font;															//设置字体（结构体）
	COLORREF color = RGB(200,128,37);										//设置当前字体颜色
	setcolor(color);														//修改当前字体颜色
	gettextstyle(&font);													//获取当前字体信息
	font.lfHeight = 22;														//设置当前字体高度为16
	font.lfWidth = 0;														//设置当前字体宽度自适应
	font.lfWeight = 400;													//设置当前字体笔画纤细
	font.lfItalic = true;													//设置当前字体为斜体
	wcscpy_s(font.lfFaceName, _T("黑体"));									//设置当前字体为宋体
	settextstyle(&font);													//完成字体修改设置
	drawtext(message, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);		//在指定矩形范围内居中输出
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
	if (point[0][0] != 9) {                                    //左上角
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
	if (point[0][Floor_Col - 1] != 9) {                           //右上角
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
	if (point[Floor_Row - 1][0] != 9) {                      //左下角
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
	if (point[Floor_Row - 1][Floor_Col - 1] != 9) {                      //右下角
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
	row = 0; line = 1;                                   //第一行
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
	row = 15; line = 1;                                   //第九行
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
	row = 1; line = 0;                                   //第一列
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
	row = 1; line = 15;                                   //第九列
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
	row = 1; line = 1;             //内部7x7格子
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

