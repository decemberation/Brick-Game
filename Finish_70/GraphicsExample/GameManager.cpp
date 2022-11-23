#include "GameManager.h"

//Phương thức khởi tạo
GameManager::GameManager()
{
	Paddle pad(10, 20);//khởi tạo ván trên với top = 10 và bottom = 20
	Paddle d(HEIGHT - 30, HEIGHT - 20);//Khởi tạo ván dưới với top = chiều cao cửa số - 30 và bottom = chiều cao cửa số - 20
	Paddle f(HEIGHT / 2 - 5, HEIGHT / 2 + 5);//Khởi tạo ván ở giữa sân
	b = pad;
	c = d;
	e = f;
	win = false;//khởi tạo biến win = false để game tiếp tục
}

//Phương thức lấy dữ liệu từ bàn phím mode 2 người chơi
void GameManager::InputPvP(char s)
{
	int left = WIDTH + 20;
	int right = WIDTH + 135;
	int top = 30;
	int bottom = HEIGHT - 530;
	if (s == 'a' || s == 'A')//Dữ liệu nhập vào là a
	{
		b.Move(-30); //Di chuyển ván trên sang trái 10 pixel
	}
	else
	{
		if (s == 'd' || s == 'D')//Dữ liệu nhập vào là d
		{
			b.Move(30);//Di chuyển ván trên sang phải 10 pixel
		}
	}
	if (s == 'j' || s == 'J')//Dữ liệu nhập vào là j
	{
		c.Move(-30);//Di chuyển ván dưới sang trái 10 pixel
	}
	else
	{
		if (s == 'l' || s == 'L')//Dữ liệu nhập vào là l
		{
			c.Move(30);//Di chuyển ván dưới sang phải 10 pixel
		}
	}
	if (s == 'p' || s == 'P') {
		setcolor(15);//Set màu chữ thành đỏ
		settextstyle(0, 0, 13);//Set kiểu chữ
		outtextxy(left + 80, top + 50, "Press any key");//hiện chuỗi s lên nút
		outtextxy(left + 80, top + 80, "to resume");//hiện chuỗi s lên nút
		getch();
	}
}

//Phương thức lấy dữ liệu từ bàn phím mode chơi với máy
void GameManager::InputPvC(char s)
{
	int left = WIDTH + 20;
	int right = WIDTH + 135;
	int top = 30;
	int bottom = HEIGHT - 530;
	if (s == 'j' || s == 'J')//Dữ liệu nhập vào là j
	{
		c.Move(-30);//Di chuyển ván dưới sang trái 10 pixel
	}
	else
	{
		if (s == 'l' || s == 'L')//Dữ liệu nhập vào là 'l'
		{
			c.Move(30);//Di chuyển ván dưới sang phải 10 pixel
		}
	}
	if (s == 'p' || s == 'P') {
		setcolor(15);//Set màu chữ thành đỏ
		settextstyle(0, 0, 13);//Set kiểu chữ
		outtextxy(left + 80, top + 50, "Press any key");//hiện chuỗi s lên nút
		outtextxy(left + 80, top + 80, "to resume");//hiện chuỗi s lên nút
		getch();
	}
}

//Phương thức kiểm tra đã có người chiến thắng hay chưa
void GameManager::isWin()
{
	if (ball1.GetY() < 5) {
		settextstyle(0, 0, 15);//Set kiểu chữ
		setcolor(9);//Set màu chữ thành xanh
		settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
		outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Player 2 WINS");//Xuât chuỗi ra màn hình ở giữa cửa sổ
		delay(3000);//Dừng Game trong 3 giây
		win = true;//Set biến win = true để game kết thúc
	}
	if (ball2.GetY() > HEIGHT - 5) {
		settextstyle(0, 0, 15);//Set kiểu chữ
		setcolor(9);//Set màu chữ thành xanh
		settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
		outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Player 1 WINS");//Xuât chuỗi ra màn hình ở giữa cửa sổ
		delay(3000);//Dừng Game trong 3 giây
		win = true;//Set biến win = true để game kết thúc
	}
	if (ITEM.WinPvP() == true) {
		if (ball1.GetScore1() + ball2.GetScore1() > ball1.GetScore2() + ball2.GetScore2()) {
			settextstyle(0, 0, 15);//Set kiểu chữ
			setcolor(9);//Set màu chữ thành xanh
			settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Player 1 WINS");//Xuât chuỗi ra màn hình ở giữa cửa sổ
			delay(3000);//Dừng Game trong 3 giây
			win = true;//Set biến win = true để game kết thúc
		}
		if (ball1.GetScore1() + ball2.GetScore1() < ball1.GetScore2() + ball2.GetScore2()) {
			settextstyle(0, 0, 15);//Set kiểu chữ
			setcolor(9);//Set màu chữ thành xanh
			settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Player 2 WINS");//Xuât chuỗi ra màn hình ở giữa cửa sổ
			delay(3000);//Dừng Game trong 3 giây
			win = true;//Set biến win = true để game kết thúc
		}
	}
}

void GameManager::winForPvP(int map)
{
	if (map == 1) {
		char a[10];
		if (ball2.GetY() > HEIGHT - 5) {
			settextstyle(0, 0, 15);//Set kiểu chữ
			setcolor(9);//Set màu chữ thành xanh
			settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "GAME OVER");//Xuât chuỗi ra màn hình ở giữa cửa sổ
			delay(2000);//Dừng Game trong 2 giây
			win = false;
			winpp = 1;
		}
		else {
			if (ITEM.WinPvP() == true) {
				settextstyle(0, 0, 15);//Set kiểu chữ
				setcolor(9);//Set màu chữ thành xanh
				settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
				outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "VICTORY");//Xuât chuỗi ra màn hình ở giữa cửa sổ
				delay(2000);//Dừng Game trong 2 giây
				win = true;
				winpp = 1;
			}
		}
	}
	if (map == 2) {
		char a[10];
		if (ball2.GetY() > HEIGHT - 5) {
			settextstyle(0, 0, 15);//Set kiểu chữ
			setcolor(9);//Set màu chữ thành xanh
			settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "GAME OVER");//Xuât chuỗi ra màn hình ở giữa cửa sổ
			delay(2000);//Dừng Game trong 2 giây
			win = true;
			winpp = 2;
		}
		else {
			if (ITEM.WinPvP() == true) {
				settextstyle(0, 0, 15);//Set kiểu chữ
				setcolor(9);//Set màu chữ thành xanh
				settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
				outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "VICTORY");//Xuât chuỗi ra màn hình ở giữa cửa sổ
				delay(2000);//Dừng Game trong 2 giây
				win = true;
				winpp = 2;
			}
		}
	}
}

void GameManager::BangThanhTich(int temp)
{
	if (temp == 1) {
		char score2[100];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(9); //Khởi tạo màu xanh
		rectangle(WIDTH - 600, HEIGHT - 500, WIDTH - 100, HEIGHT - 100); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, 3); //Lấy kiểu tô nền
		floodfill(WIDTH - 500 , HEIGHT - 200 , 9); //Tô nền hình chữ nhật
		settextstyle(0, 0, 13);//Set kiểu chữ
		setcolor(9);//Set màu chữ thành xanh
		settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
		outtextxy(WIDTH / 2 + 50, HEIGHT / 4 - 17, " ~*~ LEADERBOARD ~*~");//Xuât chuỗi ra màn hình ở giữa cửa sổ
		sprintf(score2, "Player 2 : %d", ball2.GetScore2());
		outtextxy(WIDTH / 2 + 50, HEIGHT / 4 + 16 * 3, score2);//Hiện điểm người chơi 2 ra màn hình
		delay(5000);//Dừng Game trong 5 giây
	}
	if (temp == 2) {
		char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(9); //Khởi tạo màu xanh
		rectangle(WIDTH - 600, HEIGHT - 500, WIDTH - 100, HEIGHT - 100); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, 3); //Lấy kiểu tô nền
		floodfill(WIDTH - 500, HEIGHT - 200, 9); //Tô nền hình chữ nhật
		settextstyle(0, 0, 13);//Set kiểu chữ
		setcolor(9);//Set màu chữ thành xanh
		settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
		outtextxy(WIDTH / 2 + 50, HEIGHT / 4 - 17, " ~*~ LEADERBOARD ~*~");//Xuât chuỗi ra màn hình ở giữa cửa sổ
		sprintf(score1, "Player 1 : %d", ball1.GetScore1() + ball2.GetScore1());
		outtextxy(WIDTH / 2 + 50, HEIGHT / 4 + 17, score1);////Hiện điểm người chơi 1 ra màn hình
		sprintf(score2, "Player 2 : %d", ball2.GetScore2() + ball1.GetScore2());
		outtextxy(WIDTH / 2 + 50, HEIGHT / 4 + 17 * 3, score2);//Hiện điểm người chơi 2 ra màn hình
		delay(5000);//Dừng Game trong 5 giây
	}
}

void GameManager::SaveGame()
{
	int x, y;
	int left = WIDTH + 20;
	int right = WIDTH + 150;
	int top = 30;
	int bottom = HEIGHT - 530;
	setcolor(14);//Set màu vàng
	rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
	setcolor(15);//Set màu chữ thành đỏ
	settextstyle(0, 0, 13);//Set kiểu chữ
	moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
	settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
	outtextxy(left + 70, top + 10, "P = PAUSE");//hiện chuỗi s lên nút
	if (ismouseclick(WM_MOUSEMOVE)) {//Có sự kiện di chuyển chuột
		getmouseclick(WM_MOUSEMOVE, x, y);//lấy vị trí con trỏ chuột nơi diễn ra sự kiện
		if (x >= left && x <= right && y >= top && y <= bottom) {//vị trí nằm trong nút 1 thì vẽ lại nút 1 với màu khác
			setcolor(4);//Set màu vàng
			rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
			setcolor(14);//Set màu chữ thành đỏ
			settextstyle(0, 0, 13);//Set kiểu chữ
			moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
			settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
			outtextxy(left + 70, top + 10, "P = PAUSE");//hiện chuỗi s lên nút
		}
	}
}

//Phương thức tư di chuyển ván
void GameManager::TuChoi(int &x)
{
	if (ball1.GetX()-10 < b.Getleft()) {//Nếu vị trí của bóng nằm ngoài giới hạn trái của ván tự động
		b.Move(-x);//Di chuyển sang trái
	}
	else if (ball1.GetX()+10>b.Getright()) {//Nếu vị trí của bóng nằm ngoài giới hạn phải của ván tự động
		b.Move(x);//Di chuyển sang phải
	}
}

//Mode Chơi nâng cao
void GameManager::RunLevelUp()
{
	Ball a2(0);
	ball1 = a2;
	Ball a1(1);
	ball2 = a1;
	int tmp1 = 0, tmp2 = 1;
	char s;//biến giữ giá trị tư bàn phím
	//initwindow(WIDTH + 200, HEIGHT);
	ball1.Draw(2);//hiện bóng
	ball2.Draw(0);
	b.Draw(1);//hiện ván trên
	c.Draw(2);//hiện ván dưới
	ITEM.DrawItemPvC();
	SaveGame();
	while (!win)//chưa có người thắng
	{
		int x = 10;//Bước nhảy của ván tự động
		int t1 = ball1.GetScore1();//Lấy điểm của người chơi 1
		int t2 = ball2.GetScore2();//Lấy điểm của người chơi 2
		char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(6);//Set màu thành vàng
		line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới
		line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
		line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
		b.Delete();//Xoá ván tự dộng ở vị trí cũ
		TuChoi(x);//Cập nhật vị trí mới của ván tự động
		b.Draw(1);//Vẽ ván tự động
		if (kbhit())//Có dữ liệu từ bàn phím
		{
			s = getch();//Nhận phím
			c.Delete();//Xoá ván người chơi ở vị trí cũ
			InputPvC(s);//Cập nhật vị trí mới cho ván
			c.Draw(2);//Vẽ lại ván người chơi
		}
		ball1.checkPaddlePvC(b,tmp1);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		ball1.checkPaddlePvC(c,tmp1);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		ball2.checkPaddlePvC(b,tmp2);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		ball2.checkPaddlePvC(c,tmp2);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		ITEM.checkItemLevelUp(ball1, tmp1);
		ITEM.checkItemLevelUp(ball2, tmp2);
		ITEM.CheckBonus(ball2, 1);
		//ball1.checkPaddle(e);
		//LevelUp();//Nếu tốc độ bóng = 8 hiện ván giữa sân ra
		delay(25);//Dừng chương trình trong 25ms
		ball1.Delete();//Xoá bóng ở vị trí hiện tại
		ball1.Update();//Cập nhật vị trí mới cho bóng
		ball1.Edges(1);//Kiểm tra bóng có chạm biên không
		//if (t1 != ball1.GetScore1() || t2 != ball1.GetScore2())//Nếu điểm hiện tại thay đổi so với ban đầu
		//{
		//	e.Delete();//Xoá ván giữa sân
		//}
		ball2.Delete();//Xoá bóng ở vị trí hiện tại
		ball2.Update();//Cập nhật vị trí mới cho bóng
		ball2.Edges(2);
		setcolor(6);//Set màu thành vàng
		settextstyle(0, 0, 30);//Set kiểu chữ
		sprintf(score1, "%d", ball1.GetScore1() + ball2.GetScore1());
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);////Hiện điểm người chơi 1 ra màn hình
		settextstyle(0, 0, 30);//Set kiểu chữ
		sprintf(score2, "%d", ball2.GetScore2() + ball1.GetScore2());
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
		isWin();//Kiểm tra xem có người chơi nào chiến thắng chưa
		ball1.Draw(2);//Vẽ lại bóng
		ball2.Draw(0);
	}
	BangThanhTich(2);
	cin.clear();
}

//Mode chơi với máy
void GameManager::RunPvC()
{
	Ball a2(0);
	ball1 = a2;
	Ball a1(1);
	ball2 = a1;
	int tmp1 = 1, tmp2 = 2;
	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	ball1.Draw(2);//hiện bóng
	ball2.Draw(0);
	b.Draw(1);//hiện ván trên
	c.Draw(2);//hiện ván dưới
	ITEM.DrawItemPvC();
	while (!win)//chưa có người thắng
	{
		int x = 10;//Bước nhảy của ván tự động
		char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(6);//Set màu thành vàng
		line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới
		line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
		line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
		b.Delete();//Xoá ván tự dộng ở vị trí cũ
		TuChoi(x);//Cập nhật vị trí mới của ván tự động
		b.Draw(1);//Vẽ ván tự động
		if (kbhit())//Có dữ liệu từ bàn phím
		{
			s = getch();//Nhận phím
			c.Delete();//Xoá ván người chơi ở vị trí cũ
			InputPvC(s);//Cập nhật vị trí mới cho ván
			c.Draw(2);//Vẽ lại ván người chơi
		}
		ball1.checkPaddlePvC(b, tmp1);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		ball1.checkPaddlePvC(c, tmp1);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		ball2.checkPaddlePvC(b, tmp2);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		ball2.checkPaddlePvC(c, tmp2);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		ITEM.checkItemPvC(ball1, tmp1);
		ITEM.checkItemPvC(ball2, tmp2);
		delay(25);//Dừng chương trình trong 25ms
		ball1.Delete();//Xoá bóng ở vị trí hiện tại
		ball1.Update();//Cập nhật vị trí mới cho bóng
		ball1.Edges(1);//Kiểm tra bóng có chạm biên không
		ball2.Delete();//Xoá bóng ở vị trí hiện tại
		ball2.Update();//Cập nhật vị trí mới cho bóng
		ball2.Edges(2);//Kiểm tra bóng có chạm biên không
		setcolor(6);//Set màu thành vàng
		settextstyle(0, 0, 30);//Set kiểu chữ
		sprintf(score1, "%d", ball1.GetScore1() + ball2.GetScore1());
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);////Hiện điểm người chơi 1 ra màn hình
		settextstyle(0, 0, 30);//Set kiểu chữ
		sprintf(score2, "%d", ball2.GetScore2() + ball1.GetScore2());
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
		isWin();//Kiểm tra xem có người chơi nào chiến thắng chưa
		ball1.Draw(2);//Vẽ lại bóng
		ball2.Draw(0);
	}
	BangThanhTich(2);
	cin.clear();
}

void GameManager::RunPvP(int map)
{
	Ball a1(1);
	ball2 = a1;
	if (map == 1) {
		char s;
		//initwindow(WIDTH + 200, HEIGHT);
		ball2.Draw(0);
		c.Draw(0);//hiện ván dưới
		ITEM.DrawItemPvP(2);
		SaveGame();
		while (winpp == 0)//chưa có người thắng
		{
			//int x = 10;
			char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
			char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
			setcolor(6);//Set màu thành vàng
			line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
			line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới 
			line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
			line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
			if (kbhit())//Có dữ liệu từ bàn phím
			{
				s = getch();//Nhận phím
				c.Delete();//Xoá ván người chơi 2 ở vị trí cũ
				InputPvP(s);//Cập nhật vị trí mới cho ván
				c.Draw(0);//Vẽ ván người chơi 1
			}
			ball2.checkPaddle(c);
			ITEM.checkItemPvP(ball2, 2);
			delay(25);//Dừng chương trình trong 25ms
			ball2.Delete();//Xoá bóng ở vị trí hiện tại
			ball2.Update();//Cập nhật vị trí mới cho bóng
			ball2.EdgesForPvP();//Kiểm tra bóng có chạm biên không
			setcolor(6);//Set màu thành vàng
			sprintf(score2, "%d", ball2.GetScore2());
			outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
			winForPvP(1);//Kiểm tra xem có người chơi nào chiến thắng chưa
			ball2.Draw(0);
		}
		BangThanhTich(1);
		cin.clear();
	}
	if (map == 2) {
		char s;
		//initwindow(WIDTH + 200, HEIGHT);
		ball2.Draw(0);
		c.Draw(0);//hiện ván dưới
		ITEM.DrawItemPvP(1);
		SaveGame();
		while (winpp == 1)//chưa có người thắng
		{
			//int x = 10;
			char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
			char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
			setcolor(6);//Set màu thành vàng
			line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
			line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới 
			line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
			line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
			if (kbhit())//Có dữ liệu từ bàn phím
			{
				s = getch();//Nhận phím
				c.Delete();//Xoá ván người chơi 2 ở vị trí cũ
				InputPvP(s);//Cập nhật vị trí mới cho ván
				c.Draw(0);//Vẽ ván người chơi 1
			}
			ball2.checkPaddle(c);
			ITEM.checkItemPvP(ball2, 1);
			delay(25);//Dừng chương trình trong 25ms
			ball2.Delete();//Xoá bóng ở vị trí hiện tại
			ball2.Update();//Cập nhật vị trí mới cho bóng
			ball2.EdgesForPvP();//Kiểm tra bóng có chạm biên không
			setcolor(6);//Set màu thành vàng
			sprintf(score2, "%d", ball2.GetScore2());
			outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
			winForPvP(2);//Kiểm tra xem có người chơi nào chiến thắng chưa
			ball2.Draw(0);
		}
		BangThanhTich(1);
		cin.clear();
	}
}

//Phương thức vẽ nút lựa chọn trong Menu
void GameManager::drawButton(int left,int  top, int right, int bottom, int test, char s[]) {
	if (test == 1) {//con trỏ chuột đang ở trên nút 
		setcolor(15);//Set màu đỏ
		rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
		setcolor(14);//Set màu chữ thành vàng
		settextstyle(0, 0, 13);//Set kiểu chữ
		moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
		settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
		outtextxy(left + 150, top + 15, s);//hiện chuỗi s lên nút
	}
	else {
		setcolor(14);//Set màu vàng
		rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
		setcolor(15);//Set màu chữ thành đỏ
		settextstyle(0, 0, 13);//Set kiểu chữ
		moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
		settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
		outtextxy(left + 150, top + 15, s);//hiện chuỗi s lên nút
	}
}

//Phương thức hiện Menu để vào game
void GameManager::Menu() 
{
	int left = 1000/ 2 - 150;//giới hạn bên trái nút
	int right =  1000 / 2 + 150;//giới hạn bên phải nút
	int top = 100;//giới hạn bên trên nút đầu tiên
	int bottom = 150;//giới hạn bên dưới nút đầu tiên
	int x, y;//vị trí con trỏ chuột
	int quit = 0;//biến kiểm tra để dừng trò chương trình
	initwindow(WIDTH + 200, HEIGHT);//Hiện cửa số BGI
	settextstyle(10, 0, 5);
	outtextxy(left + 30, top - 60, "BRICK GAME");
	drawButton(left, top, right, bottom, 0, "Solo");//Vẽ nút đầu tiên
	drawButton(left, top + 100, right, bottom + 100, 0,"Player vs AI");//Vẽ nút 2
	drawButton(left, top + 200, right, bottom + 200, 0,"Hard Mode");//Vẽ nút 3
	drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");//Vẽ nút 4
	while (!quit) {//nếu quit vẫn = 0
		if (ismouseclick(WM_MOUSEMOVE)) {//Có sự kiện di chuyển chuột
			getmouseclick(WM_MOUSEMOVE, x, y);//lấy vị trí con trỏ chuột nơi diễn ra sự kiện
			if (x >= left && x <= right && y >= top && y <= bottom) {//vị trí nằm trong nút 1 thì vẽ lại nút 1 với màu khác
				drawButton(left, top, right, bottom, 1, "Solo");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs AI");
				drawButton(left, top + 200, right, bottom + 200, 0, "Hard Mode");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {//vị trí nằm trong nút 2 thì vẽ lại nút 2 với màu khác
				drawButton(left, top, right, bottom, 0, "Solo");
				drawButton(left, top + 100, right, bottom + 100, 1, "Player vs AI");
				drawButton(left, top + 200, right, bottom + 200, 0, "Hard Mode");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {//vị trí nằm trong nút 3 thì vẽ lại nút 3 với màu khác
				drawButton(left, top, right, bottom, 0, "Solo");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs AI");
				drawButton(left, top + 200, right, bottom + 200, 1, "Hard Mode");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300)//vị trí nằm trong nút 4 thì vẽ lại nút 4 với màu khác
			{
				drawButton(left, top, right, bottom, 0, "Solo");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs AI");
				drawButton(left, top + 200, right, bottom + 200, 0, "Hard Mode");
				drawButton(left, top + 300, right, bottom + 300, 1, "Quit Game");
			}
			else { 
				drawButton(left, top, right, bottom, 0, "Solo");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs AI");
				drawButton(left, top + 200, right, bottom + 200, 0, "Hard Mode");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {//Nếu có nháy chuột trái
			getmouseclick(WM_LBUTTONDOWN, x, y);//lấy vị trí con trỏ tại nơi nháy chuột
			if (x >= left && x <= right && y >= top && y <= bottom) {//Vị trí thuộc nút 1
				winpp = 0;
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				if(winpp == 0) RunPvP(1);//Vào mode chơi với người
				if (win) {
					cleardevice();//Xoá những gì đang có trên màn hình 
					Reset();//Khởi tạo lại tất cả đối tượng
					RunPvP(2); //Vào mode chơi với người man 2
				}
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {//Vị trí thuộc nút 2
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				RunPvC();//Vào mode chơi với máy
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {//Vị trí thuộc nút 3
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				RunLevelUp();//Vào mode chơi với máy
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300) {//Vị trí thuộc nút 4
				exit(0);
				//Thoat khỏi chương trình
			}
			cleardevice();//Xoá những gì đang có trên màn hình
		}
	}
}

//Phuong thức Reset các đối tượng trong game về ban đầu
void GameManager::Reset()
{
	win = false;//khỏi tạo biến win về 0
	ball1.SetScore();//Reset lại điểm
	ball2.SetScore();
	b.Reset();//Reset lại ván trên
	c.Reset();//Reset lại ván dưới
}

//Phương thức hiện ván thứ 3 ơr giữa sân
void GameManager::LevelUp()
{
	if (abs(ball1.GetSpeedY()) > 8)//Nếu tốc độ bóng lơn hơn 8
	{
		e.Draw(0);//Hiện ván
		ball1.checkPaddle(e);//Kiểm tra bóng có chạm vào ván không
	}
}