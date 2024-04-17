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

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용하게 활용될수 있습니다.
	static Shape* Create() { return new Rect; }
};

// Rect 객체를 생성하는 2가지 방법
// 1. Shape* p1 = new Rect;			// 반드시 클래스 이름을 알아야 합니다.
// 2. Shape* p2 = Rect::Create();	// 클래스 이름을 몰라도, 함수 주소만 
									// 알아도 됩니다

// C++ 에서는 "클래스이름" 을 자료구조에 보관할수 없고, 함수인자로 사용할수도 없습니다.
// => v.push_back("Rect"); => 문자열을 보관한것. 문자열 "Rect"로는 객체생성 못함.
// 
// 하지만 "함수 포인터" 는 보관할수 있습니다.       
// => v.push_back(&Rect::Create); 
// => foo( &Rect::Create);   









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)();
	std::map<int, CREATOR> create_map;

public:
	void Register(int type, CREATOR c)
	{
		create_map[type] = c;
	}

	// 아래 코드는 도형을 만들고 있지만, 클래스 이름을 사용하지 않습니다.
	// => 새로운 도형이 추가되어도, 코드 수정이 필요 없습니다.
	Shape* Create(int type)
	{
		Shape* p = nullptr;
			
		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); // ret->second 가 value 이므로 함수포인터 입니다
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품(도형)을 등록 합니다.
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




