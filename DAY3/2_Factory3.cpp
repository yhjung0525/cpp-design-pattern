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
// ���忡 ��ǰ�� ����ϴ� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*c)() )
	{
		ShapeFactory::get_instance().Register(type, c);
	}
};

// ���������� �����ڰ� ȣ��Ǵ� ������ ������ ������
// => main �Լ��� ����Ǳ� ���� �������� ������ ����.
// => ��, �Ʒ� �ڵ尡 ������ ���忡 Rect ����� �Ϸ�!!
// AutoRegister ar(1, &Rect::Create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static ��� ����Ÿ�� Ư¡�� ������ ������
	// => Rect ��ü�� ��� �޸𸮿� ����(���������� ����)
	// => ����, �Ʒ� ar�� �����ڴ� main �Լ� �������� ȣ��!!
	inline static AutoRegister ar{1, &Rect::Create };
};
// Rect::ar �� �����ڴ� ���ʿ� 1ȸ ȣ��. ��, Rect Ŭ������ ���ؼ� ���� 1ȸ ȣ��
//				// �ᱹ Ŭ���� ������.  C# ����� static ������ ����!!
// Rect rc1;	// ������ ȣ��
// Rect rc2;	// ������ ȣ��
// Rect rc3;	// ������ ȣ�� => ��, �����ڴ� ��ü �����ø��� �ѹ��� ȣ��










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




