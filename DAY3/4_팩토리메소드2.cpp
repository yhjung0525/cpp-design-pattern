// 5_���丮�޼ҵ�
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
//--------------------------------------

// ���� Ŭ���� ���鶧
// ������ �ڵ尡 �ݺ��Ǹ� : ��� Ŭ������ ���� �����ϰ�
// ���ؾ� �ϴ� �ڵ��     : �����Լ��� ���� �Ļ� Ŭ������ override 

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit*  edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// ��ü�� �����ϱ� ���� �������̽��� �����ϰ�, ��뵵 ������,
	// � ������ ��ü������ �Ļ� Ŭ������ �����Ѵ�.
	// => template method ���ϰ� ������ ���������
	// => ���ϴ� ���� "�˰���"�� �ƴ� "��ü�� ����(Ÿ��)"�� ����.
	// => "Factory method" ��� �մϴ�.
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit() override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit() override { return new OSXEdit; }
};


int main(int argc, char** argv)
{

}







// ������ ���� 23������ "�뵵" �� ���� 3���� �з��� ������ �˴ϴ�.
// => ���� ������ ������ ����

// ��������(5����) : ��ü�� �����ϱ� ���� ����ϴ� ����
// => singleton 
// => abstract factory 
// => factory method
// => prototype 
// => builder


// ��������(7����) :
// => composite : ��ü�� ���� ������ tree �������
// => decorator : ��ü�� ������ ��� �߰�
// => adapter   : �������̽� ����ġ�� �ذ�
// => proxy     : ������ �����
// => flyweight : �Ӽ��� �����ϸ� ����.
// => bridge
// => facade


// ��������(11����) :
// => template method : ���ϴ� ���� �����Լ����ؼ� �Ļ� Ŭ������ override
// => strategy        : �˰����� ��������� ������ Ŭ�����μ����ؼ� ��ü �����ϰ�
// => command, mediator, iterator, visitor, chainof responsibility
//    state, iterpretor, memento, observer



