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

//------------------------------------------------------------
// 각, 도형 클래스가 지켜야 하는 규칙을 매크로로 제공합니다.
#define REGISTER(num, classname)								\
	static Shape* Create() { return new classname; }			\
	inline static AutoRegister ar{ num, &classname::Create };

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	REGISTER(1, Rect)
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }
	REGISTER(3, Triangle)
};
// QT 오픈소스(GUI) 에 "Q_OBJECT" 라는 매크로가 있습니다.
// => Q_OBJECT 매크로가 위처럼 약속된 멤버들을 자동생성하는 기능. 

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 복습 하실때 아래 멤버 함수 만들어 보세요
//	factory.ShowRegisterShape(); // 공장에 등록된 모든 제품(도형)을 보여주는
								 // 멤버 함수


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




