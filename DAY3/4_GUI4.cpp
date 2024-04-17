#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;
std::map<int, Window*> this_map;

class Window
{
	int handle;

	Window* parent;						// �θ� ������� �Ѱ� �̴�.
	std::vector<Window*> child_vector;	// �ڽ� ������� ������ �̴�.

public:
	void add_child(Window* child)
	{
		child_vector.push_back(child);
		child->parent = this;

		// C �Լ��� ���� �ڽ������� ����
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


	// v�� w�� �ڽ�������� ����
	w.add_child(&v);


	ec_process_message();
}

