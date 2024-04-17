#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window;

// 객체 주소(this)를 자료 구조로 관리하는 기법 - 아주 널리 사용됩니다. 꼭 알아 두세요
std::map<int, Window*> this_map;


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		// 윈도우 번호를 키값으로 "현재 객체의 주소(this)" 를 자료구조에 보관
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		// static 멤버 함수는 this 가 없어서, 멤버데이타(멤버함수)에 접근이 안됩니다.
		// 자료구조에 보관된 this 를 꺼내오면  멤버데이타(멤버함수) 접근 가능합니다.
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->lbutton_down(); break;
		case WM_KEYDOWN:     
			self->key_down();		// this->key_down()
			break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};
//===========================
class MainFrame : public Window
{
public:
	void lbutton_down() override 
	{
		std::cout << "MainFrame lbutton_down\n";
	}
};

int main()
{
	MainFrame w;
	w.create("A"); // 이순간 윈도우 생성, 캡션문자열은 "A"

	ec_process_message();
}

