// 32bit ���� ( x86 )

#define USING_GUI
#include "cppmaster.h"

// �̺�Ʈ ó�� �Լ��� �ݵ�� ���ڷ� int 4���� �޾ƾ� �մϴ�.
int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	// h1 �� h2�� �ڽ�������� �����Ϸ���
	ec_add_child(h2, h1); // B �����쿡  "A�� �ڽ�" ������� ����


	// ���α׷��� ���� ���� ����, 
	// �����쿡�� �߻��ϴ� �̺�Ʈ�� ó���ϱ� ���� ȣ��
	ec_process_message(); 
}

