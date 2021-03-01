#pragma once
#include"Food.h"
#include "Psnake.h"

class Gamecontrol
{
public:
	Gamecontrol(int level=1);
	~Gamecontrol();
public:
	Psnake* Psnaker;
	Food* Pfood;
	
	int level;
public:
	void GameWorking();
	bool Snake_live();
	void Interface();
	void Gamespace();
	void Snake_Eatfood();
	//bool 




};