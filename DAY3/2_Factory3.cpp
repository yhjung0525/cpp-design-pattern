#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();
	std::map<int, CREATOR> create_map;

public:
	void Register(int type, CREATOR c)
	{
		create_map[type] = c;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second();
		}

		return p;
	}
};
// 공장에 제품을 등록하는 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*c)())
	{
		ShapeFactory::get_instance().Register(type, c);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요
AutoRegister ar(1, &Rect::Create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }
};






class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);




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




