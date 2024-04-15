#include <iostream>
#include <vector>


// 5. ������(polymophism) 
// => ������ ǥ������ ��Ȳ�� ���� �ٸ��� ����

// 6. �������� OCP �� �����ϴ� ���� ���� �ڵ��̴�.!!


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() const { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
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
				p->draw();	// ������(polymorphism)
							// => ������ ǥ������ ��Ȳ������(��ü�� ����)
							//    �ٸ��� �����ϴ� ��

			// ��ü���� ����� 3���� Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}
