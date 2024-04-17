#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;
std::map<int, Window*> this_map;

class Window
{
	int handle;

	Window* parent;						
	std::vector<Window*> child_vector;	

public:
	void add_child(Window* child)
	{
		child_vector.push_back(child);
		child->parent = this;

		ec_add_child(this->handle, child->handle);
	}


	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->lbutton_down_handler(); break;
		case WM_KEYDOWN: 	 self->key_down();     break;
		}
		return 0;
	}

	// 아래 코드가 "chain of responsibility" 를 적용하는 코드 입니다.
	void lbutton_down_handler()
	{
		// 1. 자신이 먼저 처리를 시도
		if (lbutton_down() == true)	// 처리한 경우
			return;					// event 핸들러 종료!

		// 2. 이벤트를 처리하지 않은 경우(또는 false 를 반환 한 경우)
		//    부모 윈도우에 전달
		if (parent != nullptr)
			parent->lbutton_down_handler();

	}

	virtual bool lbutton_down() { return false; }
	virtual bool key_down() { return false; }
};

//===========================
class MainFrame : public Window
{
public:
	bool lbutton_down() override
	{
		std::cout << "MainFrame lbutton_down\n";
		return true;
	}
};
class ImageView : public Window
{
public:
	bool lbutton_down() override
	{
		std::cout << "ImageView lbutton_down\n";
		
//		return true;	// 이벤트 처리를 종료 해달라!
		return false;	// 현재 이벤트를 부모 윈도우에도 전달해 달라.
	}
};

int main()
{
	MainFrame w;
	w.create("MainFrame");

	ImageView v;
	v.create("image view");

	w.add_child(&v);
	ec_process_message();
}

// 대부분의 GUI 라이브러리가 
// "자식윈도우에서 발생한 이벤트를 부모 윈도우에도 전달" 하는 기능을 지원 합니다.

// IOS(swift) 의 cocoa 라이브러리 : Responder chain 이라고 부릅니다.
// C#  의 WPF 라이브러리   : bubbling event 라고 합니다
// C++ MFC : Command routing
