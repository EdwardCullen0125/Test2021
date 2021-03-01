#include "Food.h"
#include"Unit.h"
#include<iostream>
#include <Windows.h>
#define WIN_Left 20//
#define WIN_Up 3//上边距
#define Game_Hight 30  //游戏窗格高度 
#define Game_Length  100//游戏窗格宽度
using namespace std;

Food::Food(int x, int y,char fpic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = fpic;
}

Food::~Food()
{
	//todo
}

void Food::createPos()
{
	srand((unsigned)time(NULL));
	m_iY = rand() % (Game_Hight-5) +3;
	m_iX =rand()% (Game_Length- 2)+1;//控制食物的位置
}