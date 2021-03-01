#include "Gamecontrol.h"
#include "Psnake.h"
#include "Unit.h"
#define WIN_Left 20//
#define WIN_Up 2//上边距
#define Game_Hight 30  //游戏窗格高度 
#define Game_Length  100//游戏窗格宽度
using namespace std;

Gamecontrol::Gamecontrol(int le)
{
	this ->Pfood = new Food;//todo
	this->Psnaker=new Psnake();
    level = le;
}

Gamecontrol::~Gamecontrol()
{
    delete Pfood;
    Pfood = NULL;
    delete Psnaker;
    Psnaker = NULL;//todo
}

void Gamecontrol::GameWorking()
{
    Psnake snake;
	Food food;
    Gamespace();
    Interface();
    Pfood->createPos();
    Pfood->show();
    Psnaker->Snake_Show();
	while (Snake_live())
	{
        Psnaker->Snake_move();
        Snake_Eatfood(); 
        Psnaker->Self_eat();
        Interface();//重新打印信息栏以更新信息
	}
}


bool Gamecontrol::Snake_live()//判断存活状态
{
    if (Psnaker->snake[0].m_iX == 0 || Psnaker->snake[0].m_iX == 99 || Psnaker->snake[0].m_iY == 2 || Psnaker->snake[0].m_iY == 28)
    {

        Psnaker->Snake_Show();
        Pfood->erase();
        //结束界面
        return false;
    }
    else
        return true;
}

void Gamecontrol::Snake_Eatfood()
{
    while (Psnaker->snake[0].m_iX == Pfood->m_iX && Psnaker->snake[0].m_iY == Pfood->m_iY)
    {
        int j = 0;
        Pfood->createPos();
        for (int j = 0; j < Psnaker->snake_len - 1; j++)
        {
            if (Pfood->m_iX == Psnaker->snake[j].m_iX && Pfood->m_iY == Psnaker->snake[j].m_iY)
            {
                Pfood->createPos();//如果食物出现在蛇身，重新生成食物
            }
        }
        Pfood->show();
        Psnaker->Snake_grow();//蛇身增长
        Psnaker->Snake_Show();
        Psnaker->score = Psnaker->score + 10;//加分
        int temp = level;
        level = Psnaker->score / 50 + 1;
        Interface();//重新打印信息栏以更新信息
    }
}

void Gamecontrol::Interface()
{
    int line = 0, row = 0;
    CUnit::gotoxy(0, 1);
    cout << "   贪吃蛇小游戏" << "   |" << "   Made By：徐韶康   |" << "   当前等级:   |" << level<<"\t";
    cout << "当前积分:" << Psnaker->score << endl;
    for (line = 0; line < 100; line++)
    {
        cout << "-";
    }
    cout << endl;
}

void Gamecontrol::Gamespace()
{
    int line = 0, row = 0;
    system("mode con cols=130 lines=31");//设置窗口大小
    for (row = 0; row < Game_Length + 30; row++)
    {
        cout << "-";
    }
    for (line = 1; line <Game_Hight; line++)//打印游戏主体
    {
        for (row = 0; row < Game_Length+20; row++)
        {
            if (line == Game_Hight)
            {
                cout << "-";
                while (row == 129)
                {
                    cout << endl;
                    break;
                }
            } 
        }
        for (row = 0; row < Game_Length; row++) 
        {
            if (row == 0)
                cout << "|";
            else if (row == Game_Length - 1)
            {
                cout << "|";
                cout << endl;
            }
            else
                cout << " ";
        }
    }
    for (row = 0; row < Game_Length + 30; row++)
    {
        cout << "-";
        while (row == 129)
        {
            cout << endl;
            break;
        }
    }
    CUnit::gotoxy(109, 2);
    cout << "游 戏 说 明"<<endl;
    CUnit::gotoxy(105, 4);
    cout << "向左转:A  向右转：D" ;
    CUnit::gotoxy(105, 6);
    cout << "向上转:W  向下转：S" ;
    CUnit::gotoxy(104, 8);
    cout << "每吃一个食物可以 + 10分";
    CUnit::gotoxy(106, 10);
    cout << "蛇升级分数为 50 分";
    CUnit::gotoxy(104, 12);
    cout << "每升一级可以获得身长+3";
    CUnit::gotoxy(106, 14);
    cout << "撞墙后游戏自动结束";
    CUnit::gotoxy(106, 16);
    cout << "可以吃掉自己的身体";
    CUnit::gotoxy(107, 18);
    cout << "可能获得15分加分";
    CUnit::gotoxy(104, 20);
    cout << "或者1 - 15分不等的扣分";
}