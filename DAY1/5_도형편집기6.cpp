#include <iostream>
#include <vector>

// 7. 리팩토링 분야의 아주 중요한 용어 입니다. 잘 생각해 보세요

// "replace conditional with polymorphism"
//  


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() const { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 활용됩니다.
	virtual Shape* clone() { return new Shape(*this); }
};





class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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

			v.push_back(v[k]->clone()); // 다형성 활용!!!
										// k 번째 도형이 어떤 도형인지 알필요없다.
										// 새로운 도형이 추가되어도
										// 이 코드는 수정되지 않는다.!!!
										// OCP 를 만족하는 좋은 코드!!

		}
	}
}
