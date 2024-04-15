#include <iostream>
#include <vector>

// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스인 Shape 에도 있어야 한다.
// => 문법적인 요구조건이 아닌
// => 디자인적인 요구 조건.



class Shape
{
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw Shape\n"; }
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
