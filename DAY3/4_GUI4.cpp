#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;
std::map<int, Window*> this_map;

class Window
{
	int handle;

	Window* parent;						// 부모 윈도우는 한개 이다.
	std::vector<Window*> child_vector;	// 자식 윈도우는 여러개 이다.

public:
	void add_child(Window* child)
	{
		child_vector.push_back(child);
		child->parent = this;

		// C 함수로 실제 자식윈도우 부착
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
		case WM_LBUTTONDOWN: self->lbutton_down(); break;
		case WM_KEYDOWN:
			self->key_down();		
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
class ImageView : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "ImageView lbutton_down\n";
	}
};

int main()
{
	MainFrame w;
	w.create("MainFrame");

	ImageView v;
	v.create("image view");


	// v를 w의 자식윈도우로 부착
	w.add_child(&v);


	ec_process_message();
}

