#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// => 문자열을 화면에 이쁘게 출력하는 클래스..
// => 예전부터 가지고 있던 클래스라고 가정.
class TextView
{
	std::string data;
	// font color, size, bold, 
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};
//========================================================

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};
//==========================================

// 클래스 어답터 : 클래스의 인터페이스 변경
// 객체   어답터 : 객체의   인터페이스 변경

class Text : public Shape, public TextView	
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// 아래 클래스가 객체 어답터
class ObjectAdapter : public Shape
{
	TextView* tview;  // 핵심 : 포인터 또는 참조를 사용한 멤버 
					  // => 외부에서 생성된 객체를 가리키겠다는 의도.
public:

};


int main()
{
	std::vector<Shape*> v;

	TextView tv("ABCD"); // TextView : 클래스
						 // tv       : 객체
						  
	// 이미 생성된 객체인 tv 를 v에 넣을수 있을까요 ?
	// 위에서 만든 Text 를 사용해서도 tv 자체를 v에 넣을수는 없습니다.
	// Text 는 "클래스 어답터" 이므로 
	// 
//	v.push_back( &tv ); // error. tv 는 Shape 로 부터 상속받지 않았다



}







