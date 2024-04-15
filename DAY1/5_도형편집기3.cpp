#include <iostream>
#include <vector>

// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스인 Shape 에도 있어야 한다.
// => 문법적인 요구조건이 아닌
// => 디자인적인 요구 조건.

// 4. 파생 클래스가 override 하게되는 함수는 "반드시 가상함수"로 설계되어야 한다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 멤버 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생클래스가 override 할 이유 없습니다. non-virtual
	// => virtual로 해도 에러는 아니고, 실행시 동작에는 문제 없지만
	// => 가상함수는 오버헤드가 있습니다. 필요할때만 사용해야 합니다.
	void set_color(int c) { color = c; }

	// 아래 함수는 모든 도형이 override 하게 됩니다. virtual 이어야 합니다.
	virtual int get_area() const { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
};






class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)      v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) 
				p->draw();   
		}
	}
}
