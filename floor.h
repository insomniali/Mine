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
	void Set_Mine();				//����ը������
	void Draw_Floor();				//�����κ���
	void Draw_Text();				//����������ֱ���ȵĺ���
	void Lei_Travel();
	
	Lei();							//���캯��
	~Lei();							//��������

};




