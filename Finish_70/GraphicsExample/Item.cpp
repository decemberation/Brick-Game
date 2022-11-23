#include "Item.h"

// Đây là hàm vẽ vật phẩm
void Item::DrawItem(float x, float y, float z, float t)
{
	color = 0;
	left = z;
	right = t;
	top = x;
	bottom = y;
	setcolor(RED); // Thiết lập màu sắc vật phẩm
	rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
	setfillstyle(1, 4); //Lấy kiểu tô nền
	floodfill(left + 5, bottom - 5, 4); // Tô màu vật phẩm
}

void Item::Update(int color)
{
	switch (color) {
	case 0:
		setcolor(RED); // Thiết lập màu sắc vật phẩm
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, 4); //Lấy kiểu tô nền
		floodfill(left + 5, bottom - 5, 4); // Tô màu vật phẩm
		break;
	case 1:
		setcolor(GREEN); // Thiết lập màu sắc trùng với màu nền
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, GREEN);
		floodfill(left + 5, bottom - 5, GREEN);
		break;
	case 2:
		setcolor(WHITE); // Thiết lập màu sắc trùng với màu nền
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, WHITE);
		floodfill(left + 5, bottom - 5, WHITE);
		break;
	case 3:
		setcolor(DARKGRAY); // Thiết lập màu sắc trùng với màu nền
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, DARKGRAY);
		floodfill(left + 5, bottom - 5, DARKGRAY);
		break;
	case 4:
		setcolor(YELLOW); // Thiết lập màu sắc trùng với màu nền
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, YELLOW);
		floodfill(left + 5, bottom - 5, YELLOW);
		break;
	}
}

// Đây là hàm xoá vật phâm
void Item::Delete()
{
	setcolor(BLACK); // Thiết lập màu sắc trùng với màu nền
	rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
	setfillstyle(1, BLACK);
	floodfill(left + 5, bottom - 5, BLACK);
	color = 13;
}

void Item::DeleteBonus()
{
	setcolor(BLACK); // Thiết lập màu sắc trùng với màu nền
	rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
	setfillstyle(1, BLACK);
	floodfill(left + 5, bottom - 5, BLACK);
}

//Phương thức di chuyển ván
void Item::Move(float a, float c, float d)
{
	
}

void Item::DrawBonus(float x, float y, float z, float t, int tmp)
{
	left = z;
	right = t;
	top = x;
	bottom = y;
	if (tmp == 1) {
		setcolor(BROWN); // Thiết lập màu sắc vật phẩm
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, BROWN); //Lấy kiểu tô nền
		floodfill(left + 5, bottom - 5, BROWN); // Tô màu vật phẩm
	}
	if (tmp == 2) {
		setcolor(LIGHTBLUE); // Thiết lập màu sắc vật phẩm
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, LIGHTBLUE); //Lấy kiểu tô nền
		floodfill(left + 5, bottom - 5, LIGHTBLUE); // Tô màu vật phẩm
	}
	if (tmp == 3) {
		setcolor(LIGHTGRAY); // Thiết lập màu sắc vật phẩm
		rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
		setfillstyle(1, LIGHTGRAY); //Lấy kiểu tô nền
		floodfill(left + 5, bottom - 5, LIGHTGRAY); // Tô màu vật phẩm
	}
}

void Item::MoveBonus(float a)
{
	if(x < WIDTH - 5) x += a;// thay đổi giới hạn phải của ván với bước nhảy x
}

//Phương thức lấy tung độ của điểm trên bên trái
float Item::Gettop()
{
	return top;
}

//Phương thức lấy tung độ của điểm dưới bên phải
float Item::Getbottom()
{
	return bottom;
}

//Phương thức lấy hoành độ của điểm trên bên trái
float Item::Getleft()
{
	return left;
}

//Phương thức lấy hoành độ của điểm dưới bên phải
float Item::Getright()
{
	return right;
}

// Phương thức đưa ván về vị trí ban đầu
void Item::Reset() {
	left = WIDTH / 2 - 100;
	right = WIDTH / 2 + 100;
}

void Item::setColor(int a)
{
	this->color = a;
}

int Item::getColor()
{
	return color;
}

//Phương thức khởi tạo
Item::Item(float x, float y, float z, float t)
{
	top = x; //giới hạn trên của vật phẩm = x truyền vào
	left = z; //giới hạn bên trái để ở giữa sân
	right = t; //giới hạn bên phải để ở giữa sân
	bottom = y; //giới hạn bên trên = y truyền vào
}

Item::Item()
{
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}

Item::~Item()
{
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}
