#define USING_GUI
#include "cppmaster.h"




// C ��� �Լ����� ��ü���� ���̺귯���� ������ ���ô�.
class Window
{
	int handle;
public:

	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
	}

	// �ٽ� 1. �Ʒ� �Լ��� static ��� �Լ� �̾�� �ϴ� ������ �˾ƾ� �մϴ�.
	// => callback �Լ�(�ٸ��Լ� ���ڷ� ���޵Ǵ� �Լ�)�� ��κ� ��Ģ(���� ����)�� ������ �ֽ��ϴ�.
	// => ec_make_window �� 1��° ���ڷ� ���޵Ƿ��� �ݵ�� ���ڰ� 4�� �־�� �մϴ�.
	// => �Ʒ� �Լ��� static �� �ƴϸ� ���ڷ� this�� �߰��ǰ� �˴ϴ�.

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
	w.create("A"); // �̼��� ������ ����, ĸ�ǹ��ڿ��� "A"

	ec_process_message();
}

