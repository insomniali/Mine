#pragma once
#define Picture_Width 20
#define Mine_Number 40
#define Floor_Row 16
#define Floor_Col 16

typedef struct Mine
{
	int Mine_Num;
	bool Has_Mine;
	bool Is_Dug;
}Cell;

class Lei
{
public: 
	int point[Floor_Row][Floor_Col] = { 0 };
	void Set_Mine();				//设置炸弹函数
	void Draw_Floor();				//描绘地形函数
	void Draw_Text();				//用来输出文字标题等的函数
	void Lei_Travel();
	
	Lei();							//构造函数
	~Lei();							//析构函数

};




