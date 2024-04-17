// 3_�߻����丮 - 147
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

int main(int argc, char** argv)
{
	IButton* btn;

	if (strcmp(argv[1], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// �׷���, ���α׷����� ��ư(�Ǵ� �ٸ� GUI)�� �Ѱ��� ����� �ɱ� ?
	// => ���鶧 ���� ���� ���� if ���� ����Ѵٸ� ?
	// => �� ��Ÿ�� ���� GUI ������ �����ϴ� ����(Factory)�� �ʿ��ϴ�.
}








