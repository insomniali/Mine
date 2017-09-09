#pragma once
#include "floor.h"

class Game
{
public:
	void GameStart();
	void GameOver_Win();
	void GameOver_Lose();
	void GameRun();
	void Judge(int row,int col);
	Game();
	~Game();
};