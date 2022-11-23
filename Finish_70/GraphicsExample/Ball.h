#pragma once
#include <iostream>
#include <time.h>
#include <cmath>
#include <Windows.h>
#include <thread>
#include <iomanip>
using namespace std;
#define WIDTH 800
#define HEIGHT 600
#include "Paddle.h"
#include "Item.h"
class Ball
{
private:
	float x;
	float y;
	float speedX;
	float speedY;
	int Score1, Score2;
	int temp;
public:
	Ball(int);
	float Angle(Paddle a);
	void Draw(int);
	void Delete();
	void Update();
	void Edges(int);
	void EdgesForPvP();
	void Reset();
	void checkPaddle(Paddle);
	void checkPaddlePvC(Paddle, int&);
	int GetScore1();
	int GetScore2();
	float GetSpeedX();
	float GetSpeedY();
	float GetX();
	float GetY();
	void setSpeedX(float);
	void setSpeedY(float);
	void setX(float);
	void setY(float);
	void SetScore();
	void setScore1(int);
	void setScore2(int);
	float AngleItem(Item);
	Ball();
	~Ball();
};

