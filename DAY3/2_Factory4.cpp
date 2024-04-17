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
	AutoRegister(int type, Shape* (*c)())
	{
		ShapeFactory::get_instance().Register(type, c);
	}
};

//------------------------------------------------------------
// ��, ���� Ŭ������ ���Ѿ� �ϴ� ��Ģ�� ��ũ�η� �����մϴ�.
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
// QT ���¼ҽ�(GUI) �� "Q_OBJECT" ��� ��ũ�ΰ� �ֽ��ϴ�.
// => Q_OBJECT ��ũ�ΰ� ��ó�� ��ӵ� ������� �ڵ������ϴ� ���. 

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// ���� �ϽǶ� �Ʒ� ��� �Լ� ����� ������
//	factory.ShowRegisterShape(); // ���忡 ��ϵ� ��� ��ǰ(����)�� �����ִ�
								 // ��� �Լ�


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



