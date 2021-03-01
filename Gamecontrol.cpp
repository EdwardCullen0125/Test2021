#include "Gamecontrol.h"
#include "Psnake.h"
#include "Unit.h"
#define WIN_Left 20//
#define WIN_Up 2//�ϱ߾�
#define Game_Hight 30  //��Ϸ����߶� 
#define Game_Length  100//��Ϸ������
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
        Interface();//���´�ӡ��Ϣ���Ը�����Ϣ
	}
}


bool Gamecontrol::Snake_live()//�жϴ��״̬
{
    if (Psnaker->snake[0].m_iX == 0 || Psnaker->snake[0].m_iX == 99 || Psnaker->snake[0].m_iY == 2 || Psnaker->snake[0].m_iY == 28)
    {

        Psnaker->Snake_Show();
        Pfood->erase();
        //��������
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
                Pfood->createPos();//���ʳ�������������������ʳ��
            }
        }
        Pfood->show();
        Psnaker->Snake_grow();//��������
        Psnaker->Snake_Show();
        Psnaker->score = Psnaker->score + 10;//�ӷ�
        int temp = level;
        level = Psnaker->score / 50 + 1;
        Interface();//���´�ӡ��Ϣ���Ը�����Ϣ
    }
}

void Gamecontrol::Interface()
{
    int line = 0, row = 0;
    CUnit::gotoxy(0, 1);
    cout << "   ̰����С��Ϸ" << "   |" << "   Made By�����ؿ�   |" << "   ��ǰ�ȼ�:   |" << level<<"\t";
    cout << "��ǰ����:" << Psnaker->score << endl;
    for (line = 0; line < 100; line++)
    {
        cout << "-";
    }
    cout << endl;
}

void Gamecontrol::Gamespace()
{
    int line = 0, row = 0;
    system("mode con cols=130 lines=31");//���ô��ڴ�С
    for (row = 0; row < Game_Length + 30; row++)
    {
        cout << "-";
    }
    for (line = 1; line <Game_Hight; line++)//��ӡ��Ϸ����
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
    cout << "�� Ϸ ˵ ��"<<endl;
    CUnit::gotoxy(105, 4);
    cout << "����ת:A  ����ת��D" ;
    CUnit::gotoxy(105, 6);
    cout << "����ת:W  ����ת��S" ;
    CUnit::gotoxy(104, 8);
    cout << "ÿ��һ��ʳ����� + 10��";
    CUnit::gotoxy(106, 10);
    cout << "����������Ϊ 50 ��";
    CUnit::gotoxy(104, 12);
    cout << "ÿ��һ�����Ի����+3";
    CUnit::gotoxy(106, 14);
    cout << "ײǽ����Ϸ�Զ�����";
    CUnit::gotoxy(106, 16);
    cout << "���ԳԵ��Լ�������";
    CUnit::gotoxy(107, 18);
    cout << "���ܻ��15�ּӷ�";
    CUnit::gotoxy(104, 20);
    cout << "����1 - 15�ֲ��ȵĿ۷�";
}