#pragma once
#include "Unit.h"
#include<cstdlib>
#include<ctime>
using namespace std;

class Food:
	public CUnit
{
public:
	Food(int x = 0, int y = 0, char fpic = '$');
	virtual ~Food() ;
	void createPos();
};

