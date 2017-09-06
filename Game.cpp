#include "Game.h"
#include <graphics.h>
#include <conio.h>

Lei L;
MOUSEMSG mouse;
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


void Game::GameRun()                                                     //游戏运行
{
	IMAGE replace,re;
	loadimage(&re, _T("./IMAGE/cell.jpg"));
	loadimage(&replace, _T("./IMAGE/bomb.jpg"));
	mouse = GetMouseMsg();
	while (1) {
		if (mouse.uMsg == WM_RBUTTONDOWN)                      //右键退出
		{
			break;
		}
		if (mouse.uMsg == WM_LBUTTONDOWN)                         //左键选择
		{                                                      
			positionx = mouse.x / Picture_Width;
			positiony = mouse.y / Picture_Width;
			switch (L.point[positionx][positiony])
			{
			    case 1:loadimage(&replace, _T("./IMAGE/1.jpg"));
				putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
				putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
				break;
				case 2:loadimage(&replace, _T("./IMAGE/2.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 3:loadimage(&replace, _T("./IMAGE/3.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 4:loadimage(&replace, _T("./IMAGE/4.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 5:loadimage(&replace, _T("./IMAGE/5.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 6:loadimage(&replace, _T("./IMAGE/6.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 7:loadimage(&replace, _T("./IMAGE/7.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				case 8:loadimage(&replace, _T("./IMAGE/8.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
				default:loadimage(&replace, _T("./IMAGE/bomb.jpg"));
					putimage(positionx*Picture_Width, positiony*Picture_Width, &re);
					putimage(positionx*Picture_Width, positiony*Picture_Width, &replace);
					break;
			}
		}
		if (L.point[positionx][positiony]==9)
		{
			break;
		}
			mouse = GetMouseMsg();
	}
}

void Game::GameOver()
{
	IMAGE end;
	if (L.point[positionx][positiony] == 9)                     //失败情况
	{
		loadimage(&end, _T("./IMAGE/icon.jpg"));
		putimage(5*Picture_Width, 5*Picture_Width, &end);
	}
	_getch();               // 按任意键继续
	closegraph();           // 关闭图形界面
}