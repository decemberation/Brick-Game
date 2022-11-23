#include "ListItem.h"

float x = WIDTH / 2 + 50;
float y = HEIGHT / 2 + 200;

void ListItem::Init()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			danhdau[i][j] = false;
		}
	}
}

bool ListItem::WinPvP()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if(danhdau[i][j] == true && it[i][j].getColor() != 3) return false;
		}
	}
	return true;
}

void ListItem::DrawItemPvP(int temp)
{
	Init();
	if (temp == 1) {
		int temp;
		int top = 10;
		int bottom = 40;
		int left = 40;
		int right = left + 80;
		for (int i = 0; i < 4; i++) {
			if (i == 1 || i == 3) temp = 9;
			else temp = 8;
			for (int j = 0; j < temp; j++) {
				danhdau[i][j] = true;
				it[i][j].DrawItem(top, bottom, left, right);
				if (j == 7) {
					left += 90;
					right += 80;
				}
				else {
					left += 90;
					right += 90;
				}
			}
			top += 40;
			bottom += 40;
			if (i == 0 || i == 2) {
				left = 10;
				right = left + 80;
			}
			else {
				left = 40;
				right = left + 80;
			}
		}
	}
	if (temp == 2) {
		int temp = 6;
		int tmp = 45;
		int top = 10;
		int bottom = 40;
		int left = 150;
		int right = left + 80;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < temp; j++) {
				danhdau[i][j] = true;
				it[i][j].DrawItem(top, bottom, left, right);
				left += 90;
				right += 90;
			}
			top += 40;
			bottom += 40;
			left = 150 + tmp;
			right = left + 80;
			tmp += 45;
			temp--;
		}
	}
}

void ListItem::DrawItemPvC()
{
	int temp;
	int top = HEIGHT / 2 - 50;
	int bottom = HEIGHT / 2 - 35;
	int left = 10;
	int right = left + 90;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			danhdau[i][j] = true;
			it[i][j].DrawItem(top, bottom, left, right);
			left += 100;
			right += 100;
		}
		top += 30;
		bottom += 30;
		left = 10;
		right = left + 90;
	}
}

bool tmp1 = true;
void ListItem::CheckBonus(Ball& a, int temp)
{
	if (abs(a.GetSpeedY()) > 8 && tmp1 == true)//Nếu tốc độ bóng lơn hơn 8
	{
		/*Bonus[0].DrawBonus(x, y);
		if(y < HEIGHT - 25) y += 10;
		Bonus[0].MoveBonus(10);
		Bonus[0].DeleteBonus();
		n++;*/
		Bonus[0].DrawBonus(HEIGHT / 2 + 130, HEIGHT / 2 + 155, WIDTH / 2 + 50, WIDTH / 2 + 100, 2);
		danhdauBonus[0] = true;
		tmp1 = false;
	}
}

bool ListItem::CheckVaCham(Ball& a, Item it, int temp)
{
	if (a.GetY() < it.Gettop()) // kiếm tra vị trí banh đang ở đâu
	{
		bool TouchTop = (a.GetY() + 5) >= it.Gettop() - 5 - a.GetSpeedY() && (a.GetX() - 5) >= it.Getleft() - 10 && (a.GetX() + 5) <= it.Getright() + 10;
		if (TouchTop) // Kiếm tra có đụng ở phía trên 
		{
			return true;
		}
	}
	else
	{
		if (a.GetY() > it.Getbottom()) // Kiếm tra vị trí banh
		{
			bool TouchBottom = (a.GetY() - 5) <= it.Getbottom() + 5 - a.GetSpeedY() && (a.GetX() - 5) >= it.Getleft() - 10 && (a.GetX() + 5) <= it.Getright() + 10;
			if (TouchBottom) // Kiếm tra có đụng phía dưới
			{
				return true;
			}
		}
		else
		{
			bool TouchRL = (a.GetX() + 5) >= it.Getleft() - 15 && (a.GetX() - 5) <= it.Getright() + 15 && (a.GetY() - 5) >= it.Gettop() && (a.GetY() + 5) <= it.Getbottom();
			if (TouchRL) // Kiếm tra đụng hai bên
			{
				return true;
			}
		}
	}
	return false;
}

void ListItem::checkColor(int i, int j)
{
	if (i == 1 || i == 2) {
		if (j > 0 && j < 7) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() == 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
		if (j == 0) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() == 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
		}
		if (j == 7) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() == 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
	}
	if (i == 0) {
		if (j > 0 && j < 7) {
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
		if (j == 0) {
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
		}
		if (j == 7) {
			if (danhdau[i + 1][j] != false && it[i + 1][j].getColor() == 0) {
				it[i + 1][j].setColor(1);
				it[i + 1][j].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
	}
	if (i == 3) {
		if (j > 0 && j < 7) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() <= 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
		if (j == 0) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() == 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i][j + 1] != false && it[i][j + 1].getColor() == 0) {
				it[i][j + 1].setColor(1);
				it[i][j + 1].Update(1);
			}
		}
		if (j == 7) {
			if (danhdau[i - 1][j] != false && it[i - 1][j].getColor() == 0) {
				it[i - 1][j].setColor(1);
				it[i - 1][j].Update(1);
			}
			if (danhdau[i][j - 1] != false && it[i][j - 1].getColor() == 0) {
				it[i][j - 1].setColor(1);
				it[i][j - 1].Update(1);
			}
		}
	}
}

void ListItem::checkItemPvC(Ball& a, int temp)
{
	if (temp == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], temp)) {
						int color = it[i][j].getColor();
						if (color >= 1) {
							checkColor(i,j);
						}
						if (color >= 2) {
							danhdau[i][j] = false;
							float temp1;
							temp1 = 4 * cos(a.AngleItem(it[i][j]));
							a.setSpeedX(temp1); //Đổi hướng banh
							temp1 = a.GetSpeedY();
							temp1 *= -1;
							a.setSpeedY(temp1);
							int temp = a.GetScore1();
							temp += 1;
							a.setScore1(temp);
							it[i][j].Delete();
							it[i][j].~Item();
						}
						else {
							color += 1;
							it[i][j].setColor(color);
							it[i][j].Update(color);
							float temp1;
							temp1 = 2 * cos(a.AngleItem(it[i][j]));
							a.setSpeedX(temp1); //Đổi hướng banh
							temp1 = a.GetSpeedY();
							temp1 *= -1;
							a.setSpeedY(temp1);
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], temp)) {
						int color = it[i][j].getColor();
						if (color >= 1) {
							checkColor(i, j);
						}
						if (color >= 2) {
							danhdau[i][j] = false;
							float temp1;
							temp1 = 4 * cos(a.AngleItem(it[i][j]));
							a.setSpeedX(temp1); //Đổi hướng banh
							temp1 = a.GetSpeedY();
							temp1 *= -1;
							a.setSpeedY(temp1);
							int temp = a.GetScore2();
							temp += 1;
							a.setScore2(temp);
							it[i][j].Delete();
							it[i][j].~Item();
						}
						else {
							color += 1;
							it[i][j].setColor(color);
							it[i][j].Update(color);
							float temp1;
							temp1 = 2 * cos(a.AngleItem(it[i][j]));
							a.setSpeedX(temp1); //Đổi hướng banh
							temp1 = a.GetSpeedY();
							temp1 *= -1;
							a.setSpeedY(temp1);
						}
					}
				}
			}
		}
	}
}

void ListItem::checkItemLevelUp(Ball& a, int temp)
{
	int n = 0;
	if (temp == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], temp)) {
						danhdau[i][j] = false;
						float temp1;
						temp1 = 6 * cos(a.AngleItem(it[i][j]));
						a.setSpeedX(temp1); //Đổi hướng banh
						temp1 = a.GetSpeedY();
						temp1 *= -1;
						a.setSpeedY(temp1);
						int temp = a.GetScore1();
						temp += 1;
						a.setScore1(temp);
						it[i][j].Delete();
						it[i][j].~Item();

					}
				}
			}
		}
		if (CheckVaCham(a, Bonus[0], temp)) {
			float temp1;
			temp1 = 6 * cos(a.AngleItem(Bonus[0]));
			a.setSpeedX(temp1); //Đổi hướng banh
			temp1 = a.GetSpeedY();
			temp1 *= -1;
			a.setSpeedY(temp1);
			int temp = a.GetScore2();
			temp += 3;
			a.setScore2(temp);
			Bonus[0].Delete();
			Bonus[0].~Item();
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], temp)) {
						danhdau[i][j] = false;
						float temp1;
						temp1 = 6 * cos(a.AngleItem(it[i][j]));
						a.setSpeedX(temp1); //Đổi hướng banh
						temp1 = a.GetSpeedY();
						temp1 *= -1;
						a.setSpeedY(temp1);
						int temp = a.GetScore2();
						temp += 1;
						a.setScore2(temp);
						it[i][j].Delete();
						it[i][j].~Item();
					}
				}
			}
		}
		if (danhdauBonus[0] == true) {
			if (CheckVaCham(a, Bonus[0], temp)) {
				danhdauBonus[0] = false;
				float temp1;
				temp1 = 6 * cos(a.AngleItem(Bonus[0]));
				a.setSpeedX(temp1); //Đổi hướng banh
				temp1 = a.GetSpeedY();
				temp1 *= -1;
				a.setSpeedY(temp1);
				int temp = a.GetScore2();
				temp += 3;
				a.setScore2(temp);
				Bonus[0].Delete();
				Bonus[0].~Item();
			}
		}
	}
}

bool a1 = true, a2 = true, a3 = true;
int b1 = 4, b2 = 8;
void ListItem::checkItemPvP(Ball& a, int map)
{
	int d, c;
	if (map == 1) {
		int tmp;
		int k = 0;
		if (a.GetScore2() == b1) a1 = true;
		if (abs(a.GetSpeedY()) >= b2) a2 = true;
		if (a.GetScore2() > b1&& a1 == true) {
			b1 += 6;
			do {
				d = rand() % 3;
				c = rand() % 7;
			} while (danhdau[d][c] == false);
			a1 = false;
			it[d][c].setColor(3);
			it[d][c].Update(3);
		}
		if (abs(a.GetSpeedY()) > b2&& a2 == true)//Nếu tốc độ bóng lơn hơn 8
		{
			b2 += 4;
			do {
				d = rand() % 3;
				c = rand() % 7;
			} while (danhdau[d][c] == false);
			a2 = false;
			it[d][c].setColor(4);
			it[d][c].Update(4);
		}
		if (abs(a.GetSpeedY()) > 12 && danhdauBonus[1] == false) a3 = true;
		if (abs(a.GetSpeedY()) > 10 && a3 == true)//Nếu tốc độ bóng lơn hơn 8
		{
			int left = 100 + rand() % 400;
			Bonus[1].DrawBonus(HEIGHT - 300, HEIGHT - 280, left, left + 50, 1);
			danhdauBonus[1] = true;
			a3 = false;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 1 || i == 3) tmp = 9;
			else tmp = 8;
			for (int j = 0; j < tmp; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], 1)) {
						if (it[i][j].getColor() != 3) {
							if (it[i][j].getColor() == 4) {
								danhdau[i][j] = false;
								float temp1;
								temp1 = 6 * cos(a.AngleItem(it[i][j]));
								a.setSpeedX(temp1); //Đổi hướng banh
								temp1 = a.GetSpeedY();
								temp1 *= -1;
								a.setSpeedY(temp1);
								int temp = a.GetScore2();
								temp += 2;
								a.setScore2(temp);
								it[i][j].Delete();
								it[i][j].~Item();
							}
							else {
								danhdau[i][j] = false;
								float temp1;
								temp1 = 6 * cos(a.AngleItem(it[i][j]));
								a.setSpeedX(temp1); //Đổi hướng banh
								temp1 = a.GetSpeedY();
								temp1 *= -1;
								a.setSpeedY(temp1);
								int temp = a.GetScore2();
								temp += 1;
								a.setScore2(temp);
								it[i][j].Delete();
								it[i][j].~Item();
							}
						}
						else {
							/*if (a.GetScore2() > 20) {
								it[i][j].setColor(0);
								it[i][j].Update(0);
							}*/
							float temp1;
							temp1 = 6 * cos(a.AngleItem(it[i][j]));
							a.setSpeedX(temp1); //Đổi hướng banh
							temp1 = a.GetSpeedY();
							temp1 *= -1;
							a.setSpeedY(temp1);
						}
					}
				}
			}
		}
		if (danhdauBonus[1] == true) {
			if (CheckVaCham(a, Bonus[1], 1)) {
				danhdauBonus[1] = false;
				if (a.GetSpeedX() < 0)
				{
					float x = a.GetSpeedX() - (a.GetSpeedX() / 2);
					a.setSpeedX(x);
				}
				else
				{
					if (a.GetSpeedX() > 0)
					{
						float x = a.GetSpeedX() - (a.GetSpeedX() / 2);
						a.setSpeedX(x);
					}
				}
				if (a.GetSpeedY() < 0)
				{
					float x = a.GetSpeedY() - (a.GetSpeedY() / 2);
					a.setSpeedY(x);
				}
				else
				{
					if (a.GetSpeedY() > 0)
					{
						float x = a.GetSpeedY() - (a.GetSpeedY() / 2);
						a.setSpeedY(x);
					}
				}
				float temp1;
				temp1 = 6 * cos(a.AngleItem(Bonus[1]));
				a.setSpeedX(temp1); //Đổi hướng banh
				temp1 = a.GetSpeedY();
				temp1 *= -1;
				a.setSpeedY(temp1);
				Bonus[1].Delete();
				Bonus[1].~Item();
			}
		}
	}
	if (map == 2) {
		int tmp = 6;
		if (abs(a.GetSpeedY()) > 12 && danhdauBonus[1] == false) a3 = true;
		if (abs(a.GetSpeedY()) > 10 && a3 == true)//Nếu tốc độ bóng lơn hơn 8
		{
			int left = 100 + rand() % 400;
			Bonus[1].DrawBonus(HEIGHT - 300, HEIGHT - 280, left, left + 50, 1);
			danhdauBonus[1] = true;
			a3 = false;
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < tmp; j++) {
				if (danhdau[i][j] != false) {
					if (CheckVaCham(a, it[i][j], 1)) {
						danhdau[i][j] = false;
						float temp1;
						temp1 = 6 * cos(a.AngleItem(it[i][j]));
						a.setSpeedX(temp1); //Đổi hướng banh
						temp1 = a.GetSpeedY();
						temp1 *= -1;
						a.setSpeedY(temp1);
						int temp = a.GetScore2();
						temp += 1;
						a.setScore2(temp);
						it[i][j].Delete();
						it[i][j].~Item();
					}
				}
			}
			tmp--;
		}
		if (danhdauBonus[1] == true) {
			if (CheckVaCham(a, Bonus[1], 1)) {
				danhdauBonus[1] = false;
				if (a.GetSpeedX() < 0)
				{
					float x = a.GetSpeedX() - (a.GetSpeedX() / 2);
					a.setSpeedX(x);
				}
				else
				{
					if (a.GetSpeedX() > 0)
					{
						float x = a.GetSpeedX() - (a.GetSpeedX() / 2);
						a.setSpeedX(x);
					}
				}
				if (a.GetSpeedY() < 0)
				{
					float x = a.GetSpeedY() - (a.GetSpeedY() / 2);
					a.setSpeedY(x);
				}
				else
				{
					if (a.GetSpeedY() > 0)
					{
						float x = a.GetSpeedY() - (a.GetSpeedY() / 2);
						a.setSpeedY(x);
					}
				}
				float temp1;
				temp1 = 6 * cos(a.AngleItem(Bonus[1]));
				a.setSpeedX(temp1); //Đổi hướng banh
				temp1 = a.GetSpeedY();
				temp1 *= -1;
				a.setSpeedY(temp1);
				Bonus[1].Delete();
				Bonus[1].~Item();
			}
		}
	}
}


