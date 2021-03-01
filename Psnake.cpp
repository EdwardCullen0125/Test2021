#include"Food.h"
#include "Psnake.h"
#include"Gamecontrol.h"
#include<iostream>
#include<conio.h>
#include<vector>
#define WIN_Left 20//
#define WIN_Up 2//上边距
#define Game_Hight 30  //游戏窗格高度 
#define Game_Length  100//游戏窗格宽度
#define Speed 300//速度
using namespace std;


Psnake::Psnake(int x, int y, int length,int speed,int sc,Direction dir, char pic)
{
	snake_x = x;
	snake_y = y;
	snake_dir=dir;//判断蛇将要前进的方向
	snake_len = length;//蛇身长度
	snake_speed=speed;//设置蛇行进的速度//将蛇身在构造函数中进行初始化
	score = sc;
	for (int i = 0; i < length; i++)
	{
		CUnit snake_body(0, 0, '*');
		snake.push_back(snake_body);
		switch (dir)
		{
		case LEFT:
			snake[i].m_iX = snake_x + i;
			snake[i].m_iY = snake_y;
			break;
		case RIGHT:
			snake[i].m_iX = snake_x -i;
			snake[i].m_iY = snake_y;
			break;
		case UP:
			snake[i].m_iY = snake_y - i;
			snake[i].m_iX = snake_x;
			break;
		case DOWN:
			snake[i].m_iY = snake_y + i;
			snake[i].m_iX = snake_x;
			break;
		}
	}
}

Psnake::~Psnake()
{
	//todo
}


void Psnake::Snake_Show()
{
	for (int i = 0; i <snake_len; i++)
	{
		snake[i].show();
	}
}

void Psnake::Snake_move()//移动
{
		Psnake::Snake_Show();
		Sleep(Speed);
		snake[snake_len - 1].erase();
		for (int i = snake_len - 1; i >0; i--)
		{
			snake[i].m_iX = snake[i - 1].m_iX;
			snake[i].m_iY = snake[i - 1].m_iY;
		}
		Snake_turn(snake_dir);
}

void Psnake::Snake_turn(Direction dire)
{
	char keyboad;
	Direction dir=dire;
	while (_kbhit())
	{
		keyboad = _getch();
		switch (keyboad)
		{
		case 87://向上
			if (snake_dir != DOWN&&snake_dir!=UP)
			{
				snake[0].m_iY-1;
				snake_dir = UP;
				break;
			}	
			else
				break;
		case 83://向下
			if (snake_dir != DOWN && snake_dir != UP)
			{
				snake[0].m_iY+1;
				snake_dir = DOWN;
				break;
			}
			else
				break;		
		case 65://向左
			if (snake_dir != RIGHT&& snake_dir != LEFT)
			{
				snake[0].m_iX-1;
				snake_dir = LEFT;
				break;
			}
			else
				break;
		case 68://向右
			if (snake_dir != LEFT&&snake_dir!=RIGHT)
			{
				snake[0].m_iX+1;
				snake_dir = RIGHT;
				break;
			}
			else
				break;			
		}
	}//判断方向	
	switch (snake_dir)
	{
	case UP:
		snake[0].m_iY--;
		break;
	case DOWN:
		snake[0].m_iY++;
		break;
	case RIGHT:
		snake[0].m_iX++;
		break;
	case LEFT:
		snake[0].m_iX--;
		break;
	default:
		break;
	}		
}

void Psnake::Snake_grow()//蛇身长大
{
	CUnit snake_body(snake[snake_len - 1].m_iX, snake[snake_len - 1].m_iY, '*');
	snake.push_back(snake_body);//todo
	snake_len++;
}

void Psnake::Self_eat()
{
	int j;
	vector<CUnit> snakecopy;
	for (int k = 0; k < snake_len; k++)
	{
			snakecopy.push_back(snake[k]);
	}
	for (j = 3; j < snake_len; j++)
	{
		if (snake[0].m_iX == snakecopy[j].m_iX && snake[0].m_iY == snakecopy[j].m_iY)
		{
			int m;
			for (m = snake_len - 1; m > j; m--)
			{
				snake[m].erase();
				snake.pop_back();
				snake_len--;
				int Score_change=0;//随机加分或减分
				srand((unsigned)time(NULL));
				int control = rand()% 5;//定义控制函数，判断加分或者是减分
				switch (control)
				{
				case 0:
					Score_change = -15;
					break;
				case 1:
					Score_change = -10;
					break;
				case 2:
					Score_change = -5;
					break;
				case 3:
					Score_change = -1;
					break;
				case 4:
					Score_change = 15;
					break;
				}
				score=score+Score_change;
			}
			Snake_Show();
		}
	}
}