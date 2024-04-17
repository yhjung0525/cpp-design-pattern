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
//-----------------

// ������ ���� 23�� �������� "Factory" ��� ������ �����ϴ�
// => "Abstract Factory" ��� ������ �ֽ��ϴ�.
// => ��ǰ�� ���� ����� ���� �������̽��� ����������, � ������ ��ǰ������
//    �Ļ� Ŭ�������� �����Ѵ�.
class IFactory 
{
public:
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
	virtual ~IFactory() {}
};

//  style ���� �� ��Ʈ���� ����� ����
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};


int main(int argc, char** argv)
{
	IFactory* factory;
	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// ��Ʈ���� �ʿ��ϸ� ������ ����ؼ� ����
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











