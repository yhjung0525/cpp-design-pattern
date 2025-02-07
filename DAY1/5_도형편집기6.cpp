#include <iostream>
#include <vector>

// 7. 리팩토링 분야의 아주 중요한 용어 입니다. 잘 생각해 보세요

// "replace conditional with polymorphism"
//  "조건문을 다형성(가상함수) 로 변경해라"
//   도형편집기5.cpp => 도형편집기6.cpp 로..   if (cmd ==8) 부분에서

// 8. 디자인 패턴이란 ?
// => 자주 사용되는 코딩 기법에 "이름을 부여" 한것
// => 23개의 기법
// => 1994년 발간된 책의 제목

// 9. prototype 디자인 패턴 
// => 견본이 되는 객체를 먼저 생성하고
// => 복사를 통해서 객체를 만드는 디자인 기법
// => clone() 가상함수.. 

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
