#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	Rect* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	Circle* Clone() override { return new Circle(*this); }
};



class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> create_map;

public:
	void Register(int type, Shape* c)
	{
		create_map[type] = c;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second->Clone(); // 등록된 견본의 복사본 생성
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	// 아래 코드는 결국 factory 에  "1. 객체   2. 클래스" 를 등록하는 코드입니다.
	// => 정확히는 "함수 포인터" 등록이지만, 의미상으로는 "클래스등록" 입니다.
	// => 객체를 생성하기 위해서 함수 포인터를 등록하므로
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// 클래스 말고, 자주사용되는 객체를 등록해 봅시다.
	// => 견본이 되는 객체를 생성해서, 공장에 등록후에
	// => 견본의 복사본을 통해서 객체 생성(prototype 패턴)
	Rect* redRect = new Rect; // 빨간색, 크기가 10인 사각형이라고 가정
	Rect* blueRect = new Rect; 
	Circle* redCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);




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




