#include <iostream>
#include <vector>

// 11. 코드 정리 및 생각해볼 문제..

class NotImplemented {};


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex lock\n";
		draw_imp();
		std::cout << "mutex unlock\n";
	}

	// 가상함수 : 파생 클래스가 override 하지 않으면 기본 구현을 제공하겠다는 의도
	// 순수가상함수 : 파생 클래스가 반드시 override 하라고 지시하는 것

protected:
	virtual void draw_imp() = 0;
public:

	// clone 의 경우
	// 1. 순수 가상함수로 해도 되고(엄격한 규칙 사용)
	// 2. 아래 처럼 만드는 기법도 유명한 기법(기본 구현이 예외 발생)
	// => override 하지 않고, 사용도 하지 않으면 ok
	// => override 하고,     사용 하면 ok.
	// => override 하지 않고, 사용하면 예외 발생.
	
//	virtual Shape* clone() = 0;
	virtual Shape* clone() { throw NotImplemented(); }

	// 
//	virtual int get_area() const = 0; // 이렇게 해도 되고.
	virtual int get_area() const { return -1; } // 기본 구현이 실패를 나타내는 값 반환
	

};





class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }

	// 공변 반환의 규칙
	// => 가상함수 override 시에 반환 타입을 변경할수 있습니다.
	// => 단, 상속관계의 타입만 가능합니다.
	Rect* clone() override { return new Rect(*this); }
};

// Rect* p1 = new Rect;
// Rect* p2 = p1->clone();

class Circle : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw Circle\n"; }

	Circle* clone() override { return new Circle(*this); }
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 1. 새로운 도형이 추가되면 아래의 "객체생성" 부분이 변해야(추가) 합니다.
		// => 객체의 생성을 OCP를 만족하게 할수 없을까요 ?
		// => "추상 팩토리" 패턴을 사용하면 됩니다. (3일차 수업)

		// 2. "Undo/Redo" 기능을 추가하려면 어떻게 해야 할까요 ?
		// => "Command" 패턴을 사용하면 됩니다.(3일차)

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
