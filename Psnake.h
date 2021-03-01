#pragma once
#include "Unit.h"
#include<iostream>
#include<vector>
using namespace std;

typedef enum {
    LEFT, RIGHT, UP, DOWN
}Direction;

class Psnake 
{
public:
    int snake_x;
    int snake_y;
    int snake_speed;//蛇的速度
    Direction snake_dir;//蛇的方向
    vector<CUnit> snake;//定义蛇身的动态数组
    int snake_len;  
    int score;
public:
    Psnake(int x = 40, int y = 10, int length = 6,int speed=500,int score=10,Direction dir=RIGHT,char pic='@');
    ~Psnake();
    void Snake_Show();//打印蛇身
    void Snake_move();//移动
    void Snake_turn(Direction);//转向
    void Snake_grow();//蛇身长大
    void Self_eat();
};

