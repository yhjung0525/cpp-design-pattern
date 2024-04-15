#include <iostream>
#include <vector>

// 10. template method 패턴
// => 기반 클래스 안에 변하지 않은 전체적인 흐름을 담은 알고리즘을 제공
// => 세부 구현을 가상함수화 해서 파생클래스에서 세부 구현을제공.


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() const { return 0; }
	virtual Shape* clone() { return new Shape(*this); }


	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 코드를 찾아서
	// => 변해야 하는 것을 가상함수로 분리한다.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n";
	}

public:
	void draw() 
	{ 
		std::cout << "mutex lock\n";		
		draw_imp();
		std::cout << "mutex unlock\n";	
	}
};





class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle\n"; }

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

			v.push_back(v[k]->clone());


		}
	}
}
