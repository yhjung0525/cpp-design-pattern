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
// 도형 편집기에서 "문자열" 도 관리하고 싶다.!
// => 도형편집기에서 예전 부터 가지고 있던 "TextView" 를 사용할수 있을까 ?
// => 직접 사용할수는 없다. 인터페이스 불일치(draw() 가 필요한데, show() 제공)

// 인터페이스의 불일치를 해결해 보자.

class Text : public Shape,		// 도형편집기의 요구 조건
			 public TextView	// 기존 클래스의 모든 기능을 물려 받는다.
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 코드가 "show 라는 이름을 draw 라는 이름으로 변경" 하는 코드 입니다.
	// 인터페이스의 불일치를 해결하는 함수!!!
	void draw() override
	{
		TextView::show();
	}
};
int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw();
}







