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
    int snake_speed;//�ߵ��ٶ�
    Direction snake_dir;//�ߵķ���
    vector<CUnit> snake;//��������Ķ�̬����
    int snake_len;  
    int score;
public:
    Psnake(int x = 40, int y = 10, int length = 6,int speed=500,int score=10,Direction dir=RIGHT,char pic='@');
    ~Psnake();
    void Snake_Show();//��ӡ����
    void Snake_move();//�ƶ�
    void Snake_turn(Direction);//ת��
    void Snake_grow();//������
    void Self_eat();
};

