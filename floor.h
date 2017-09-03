#pragma once

class Lei
{
public: 
	int mine[9][9] = { 0 };			//9X9扫雷地形
	int the_mine = 1;				//炸弹
	
	void Set_Lei();				//设置炸弹函数
	void Draw_Floor();				//描绘地形函数
	void Draw_Num();				//用以测试设置炸弹函数是否合适的函数
	void Lei_Travel();              //遍历雷点
	
	Lei();							//构造函数
	~Lei();							//析构函数


};


