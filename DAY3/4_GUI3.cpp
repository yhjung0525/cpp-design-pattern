#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window;

// ��ü �ּ�(this)�� �ڷ� ������ �����ϴ� ��� - ���� �θ� ���˴ϴ�. �� �˾� �μ���
std::map<int, Window*> this_map;


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		// ������ ��ȣ�� Ű������ "���� ��ü�� �ּ�(this)" �� �ڷᱸ���� ����
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		// static ��� �Լ��� this �� ���, �������Ÿ(����Լ�)�� ������ �ȵ˴ϴ�.
		// �ڷᱸ���� ������ this �� ��������  �������Ÿ(����Լ�) ���� �����մϴ�.
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
	w.create("A"); // �̼��� ������ ����, ĸ�ǹ��ڿ��� "A"

	ec_process_message();
}

