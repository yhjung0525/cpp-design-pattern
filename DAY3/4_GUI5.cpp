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

	// �Ʒ� �ڵ尡 "chain of responsibility" �� �����ϴ� �ڵ� �Դϴ�.
	void lbutton_down_handler()
	{
		// 1. �ڽ��� ���� ó���� �õ�
		if (lbutton_down() == true)	// ó���� ���
			return;					// event �ڵ鷯 ����!

		// 2. �̺�Ʈ�� ó������ ���� ���(�Ǵ� false �� ��ȯ �� ���)
		//    �θ� �����쿡 ����
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
		
//		return true;	// �̺�Ʈ ó���� ���� �ش޶�!
		return false;	// ���� �̺�Ʈ�� �θ� �����쿡�� ������ �޶�.
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

// ��κ��� GUI ���̺귯���� 
// "�ڽ������쿡�� �߻��� �̺�Ʈ�� �θ� �����쿡�� ����" �ϴ� ����� ���� �մϴ�.

// IOS(swift) �� cocoa ���̺귯�� : Responder chain �̶�� �θ��ϴ�.
// C#  �� WPF ���̺귯��   : bubbling event ��� �մϴ�
// C++ MFC : Command routing
