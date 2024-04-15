#include <iostream>
#include <vector>


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
				p->draw();	
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// k번째 만들었던 도형을 복제해서 새로운 도형을 생성후에 v 에 추가
			// 어떻게 해야 할까요 ??
			// k 번째 만들었던 도형은 어떤 도형일까요 ?

			// 아래 처럼 만들수도 있지만, 아래 코드는 OCP 를 만족할수 없습니다.
			// => 새로운 도형이 추가되면 아래 코드는 수정(추가)되어야 합니다.
			if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				v.push_back(new Rect( *v[k] ) );
			}
			else if (dynamic_cast<Circle*>(v[k]) != 0)
			{
				v.push_back(new Circle(*v[k]));
			}
		}
	}
}
