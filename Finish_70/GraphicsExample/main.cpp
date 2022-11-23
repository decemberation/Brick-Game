#include "GameManager.h"
#include <Windows.h>

// hàm dùng để ẩn cửa sổ console khi chạy chương trình
void hideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

// hàm kiểm tra xem cửa sổ console có đang mở không
bool isOpen()
{
	return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}

int main()
{
	if (isOpen() == TRUE)
		hideConsole();
	GameManager a;
	a.Menu();
	getchar();
}