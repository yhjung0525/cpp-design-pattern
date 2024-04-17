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
	AutoRegister(int type, Shape* (*c)() )
	{
		ShapeFactory::get_instance().Register(type, c);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요
// => main 함수가 실행되기 전에 전역변수 생성자 실행.
// => 즉, 아래 코드가 있으면 공장에 Rect 등록이 완료!!
// AutoRegister ar(1, &Rect::Create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해 보세요
	// => Rect 객체가 없어도 메모리에 존재(전역변수와 유사)
	// => 따라서, 아래 ar의 생성자는 main 함수 실행전에 호출!!
	inline static AutoRegister ar{1, &Rect::Create };
};
// Rect::ar 의 생성자는 최초에 1회 호출. 즉, Rect 클래스에 대해서 최초 1회 호출
//				// 결국 클래스 생성자.  C# 언어의 static 생성자 역할!!
// Rect rc1;	// 생성자 호출
// Rect rc2;	// 생성자 호출
// Rect rc3;	// 생성자 호출 => 즉, 생성자는 객체 생성시마다 한번씩 호출










class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	inline static AutoRegister ar{ 2, &Circle::Create };
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




