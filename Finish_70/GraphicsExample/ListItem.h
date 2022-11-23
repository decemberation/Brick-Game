#pragma once
#include "Item.h"
#include "Ball.h"
class ListItem
{
private:
	Item Bonus[10];
	bool danhdauBonus[10];
	Item it[6][12];
	bool danhdau[6][12];
	int tmp = 0;
	int n = 0;
public:
	void Init();
	bool WinPvP();
	void DrawItemPvP(int);
	void DrawItemPvC();
	void CheckBonus(Ball&, int);
	bool CheckVaCham(Ball&, Item, int);
	void checkColor(int, int);
	void checkItemPvP(Ball&, int);
	void checkItemPvC(Ball&, int);
	void checkItemLevelUp(Ball&, int);
};

