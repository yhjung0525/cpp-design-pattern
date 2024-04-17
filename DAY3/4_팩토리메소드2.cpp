// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
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

// 여러 클래스 만들때
// 동일한 코드가 반복되면 : 기반 클래스를 만들어서 제공하고
// 변해야 하는 코드는     : 가상함수로 만들어서 파생 클래스가 override 

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
	// 객체를 생성하기 위한 인터페이스를 제공하고, 사용도 하지만,
	// 어떤 종류의 객체인지는 파생 클래스가 결정한다.
	// => template method 패턴과 동일한 모양이지만
	// => 변하는 것이 "알고리즘"이 아닌 "객체의 종류(타입)"을 결정.
	// => "Factory method" 라고 합니다.
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








