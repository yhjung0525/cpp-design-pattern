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

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 활용될수 있습니다.
	static Shape* Create() { return new Rect; }
};

// Rect 객체를 생성하는 2가지 방법
// 1. Shape* p1 = new Rect;
// 2. Shape* p2 = Rect::Create();









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};






class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
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

		if (cmd > 0 && cmd < 8) 
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
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




