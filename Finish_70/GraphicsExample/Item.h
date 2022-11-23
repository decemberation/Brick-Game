#pragma once
#include "Paddle.h"
class Item
{
private:
	float x;
	float y;
	float left; //hoành độ góc trên bên trái ván
	float top; //tung độ góc  trên bên trái
	float right; //hoành độ góc dưới bên phải ván
	float bottom; //tung độ góc dưới bên phải ván
	int color = 0;
public:
	void DrawItem(float x, float y, float z, float t);
	void Update(int);
	void Delete();
	void DeleteBonus();
	void Move(float, float, float); //Phương thức thay đổi toạ độ của ván
	void DrawBonus(float, float, float, float, int);
	void MoveBonus(float);
	float Gettop(); // Phương thức lấy tung độ góc trên bên trái ván
	float Getbottom(); // Phương thức lấy tung độ góc dưới bên trái ván
	float Getleft();// Phương thức lấy hoành độ góc trên bên trái ván 
	float Getright();// Phương thức lấy hoành độ góc dưới bên phải ván
	void Reset();// Phương thức đưa ván về vị trí ban đầu
	void setColor(int);
	int getColor();
	Item(float x, float y, float z, float t);
	Item();
	~Item();
};

