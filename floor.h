#pragma once

class Lei
{
public: 
	int mine[9][9] = { 0 };			//9X9ɨ�׵���
	int the_mine = 1;				//ը��
	
	void Set_Lei();				//����ը������
	void Draw_Floor();				//�����κ���
	void Draw_Num();				//���Բ�������ը�������Ƿ���ʵĺ���
	void Lei_Travel();              //�����׵�
	
	Lei();							//���캯��
	~Lei();							//��������


};


