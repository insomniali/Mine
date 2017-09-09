#include "Game.h"
#include <graphics.h>
#include <conio.h>

Lei L;
MOUSEMSG mouse;
IMAGE replace, re;
int positionx = 0, positiony = 0;

Game::Game()
{
	
}

Game::~Game()
{
	
}


void Game::GameStart()
{
	initgraph(Picture_Width * Floor_Row, Picture_Width * Floor_Col);    // 初始化绘图窗口
	L.Draw_Floor();
	L.Set_Mine();
	L.Lei_Travel();
//	L.Draw_Text();
}


void Game::GameRun()                                                //游戏运行
{	
	int ClickCount = 0;												//鼠标点击次数	
	loadimage(&re, _T("./IMAGE/cell.jpg"));
	mouse = GetMouseMsg();
	while (1) 
	{
		if (mouse.uMsg == WM_LBUTTONDOWN)                           //左键选择
		{                                                      
			positionx = mouse.x / Picture_Width;
			positiony = mouse.y / Picture_Width;
			Judge(positionx, positiony);
			if (9 == L.point[positionx][positiony])
				GameOver_Lose();
			ClickCount++;
		}
		if (Floor_Row * Floor_Col - Mine_Number == ClickCount)
			GameOver_Win();
		mouse = GetMouseMsg();
	}
}

void Game::GameOver_Win()
{
	IMAGE win;
	loadimage(&win, _T("./IMAGE/icon.jpg"));
	for (int row = 0; row < Floor_Row; ++row)
		for (int col = 0; col < Floor_Col; ++col)
			Judge(row, col);

	Sleep(10000);
	cleardevice();
	putimage(5 * Picture_Width, 5 * Picture_Width, &win);

	_getch();               // 按任意键继续
	closegraph();           // 关闭图形界面
}

void Game::GameOver_Lose()
{
	IMAGE lose;
	loadimage(&lose, _T("./IMAGE/icon.jpg"));

	for (int row = 0; row < Floor_Row; ++row)
		for (int col = 0; col < Floor_Col; ++col)
			Judge(row, col);

	Sleep(10000);
	cleardevice();
	putimage(5 * Picture_Width, 5 * Picture_Width, &lose);

	_getch();               // 按任意键继续
	closegraph();           // 关闭图形界面
}

void Game::Judge(int row,int col)
{
	switch (L.point[row][col])
	{
	case 1:loadimage(&replace, _T("./IMAGE/1.jpg"));
		break;
	case 2:loadimage(&replace, _T("./IMAGE/2.jpg"));
		break;
	case 3:loadimage(&replace, _T("./IMAGE/3.jpg"));
		break;
	case 4:loadimage(&replace, _T("./IMAGE/4.jpg"));
		break;
	case 5:loadimage(&replace, _T("./IMAGE/5.jpg"));
		break;
	case 6:loadimage(&replace, _T("./IMAGE/6.jpg"));
		break;
	case 7:loadimage(&replace, _T("./IMAGE/7.jpg"));
		break;
	case 8:loadimage(&replace, _T("./IMAGE/8.jpg"));
		break;
	case 9:loadimage(&replace, _T("./IMAGE/bomb.jpg"));
		break;
	}
	putimage(row * Picture_Width, col * Picture_Width, &re);
	putimage(row * Picture_Width, col * Picture_Width, &replace);
}
