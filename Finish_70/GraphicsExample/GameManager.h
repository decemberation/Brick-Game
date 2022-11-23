#pragma once
#include "Ball.h"
#include "ListItem.h"
class GameManager
{
	Ball ball1, ball2; //Đối tượng quả bóng
	Paddle b;//Ván trượt trên
	Paddle c; //Ván trượt dưới
	Paddle e; //Ván trượt trong mode nâng cao
	ListItem ITEM;
	bool win; //biến kiểm tra để kết thúc game
	int winpp = 0;
public:
	GameManager(); //Phương thức khởi tạo
	void RunPvP(int); // Mode chơi 2 người
	void RunPvC(); //Mode chơi với máy
	void RunLevelUp(); //Mode chơi nâng cao
	void InputPvP(char s);//Phương thức bắt dữ liệu từ bàn phím để di chuyển ván mode chơi 2 người
	void InputPvC(char s);//Phương thức bắt dữ liệu từ bàn phím để di chuyển ván mode chơi với máy
	void isWin(); //Phương thức kiểm tra đã có người chiến thắng hay chưa
	void winForPvP(int);
	void BangThanhTich(int);
	void SaveGame();
	void TuChoi(int &x);//Phương thức tư di chuyển ván
	void TuMove(int&);
	void drawButton(int left, int  top, int right, int bottom, int test, char s[]);//Phương thức vẽ nút trong menu
	void Reset();//Phương thức reset lại các đối tượng trong game về ban đầu
	void LevelUp();//Phương thức hiện ván thứ 3 ở giữa sân
	void Menu();//Phương thức hiện menu để vào game
};

