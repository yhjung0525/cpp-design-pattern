#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형을 만드는 팩토리
// => 공장을 통해서만 도형 객체를 생성한다면..
// => 새로운 도형이 추가되어도 공장만 수정되면 됩니다.
// => 코드 수정을 최소화 할수 있습니다.

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 아래 코드는 새로운 도형이 추가되어도 수정될 필요가 없습니다.
		if (cmd > 0 && cmd < 8) // 1 ~ 7 번을 도형의 번호로 예약
		{
			Shape* p = factory.Create(cmd);

			if (p != nullpr)
				v.push_back(p);
		}		

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




