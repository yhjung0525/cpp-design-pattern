#define USING_GUI
#include "cppmaster.h"




// C 기반 함수들을 객체지향 라이브러리로 설계해 봅시다.
class Window
{
	int handle;
public:

	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
	}

	// 핵심 1. 아래 함수가 static 멤버 함수 이어야 하는 이유를 알아야 합니다.
	// => callback 함수(다른함수 인자로 전달되는 함수)는 대부분 규칙(인자 갯수)이 정해져 있습니다.
	// => ec_make_window 의 1번째 인자로 전달되려면 반드시 인자가 4개 있어야 합니다.
	// => 아래 함수가 static 이 아니면 인자로 this가 추가되게 됩니다.

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
		}
		return 0;
	}
};



int main()
{
	Window w;
	w.create("A"); // 이순간 윈도우 생성, 캡션문자열은 "A"

	ec_process_message();
}

