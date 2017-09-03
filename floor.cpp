#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Lei::Lei()														//构造函数
{
	
}

Lei::~Lei()														//析构函数
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


void Lei::Draw_Floor()											//打印九宫格
{
	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout <<   "■";
			if (8 == j)
				cout << endl;
		}
	}
	return;
}

void Lei::Draw_Num()											//打印九宫格数字，可看到炸弹所处位置，用以测试的函数，后期需注释，或用于设计作弊模式
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
	if (mine[0][0] != 9) {                                    //左上角
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
	if (mine[0][8] != 9) {                           //右上角
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
	if (mine[8][0] != 9) {                      //左下角
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
	if (mine[8][8] != 9) {                      //右下角
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
	row = 0; line = 1;                                   //第一行
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
	row = 8; line = 1;                                   //第九行
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
	row = 1; line = 0;                                   //第一列
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
	row = 1; line = 8;                                   //第九列
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
	row = 1; line = 1;             //内部7x7格子
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