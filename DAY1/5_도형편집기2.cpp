#include <iostream>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}
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
			for (auto p : v) // Shape* p 인데
				p->draw();   // Shape 안에는 draw()가 없다.
		}
	}
}
// 왜 이코드가 에러 일까요 ?
// => p->draw() 에서 p 는 Shape* 인데, Shape 안에는 draw 가 없다.
// 
// 해결책은 뭘까요 ?? 
// 1. Shape* 인 p 를 Rect* 또는 Circle* 로 캐스팅 해서 사용하자. ==> 절대 이렇게 하지마세요
// ==> 이렇게 하려면 p 가 어떤 도형을 가리키는지 조사 필요(dynamic_cast)
// ==> if 문 사용. 
// ==> OCP 만족할수 없다.
// 
// 2. Shape 안에도 draw() 를 만들자. ==> 답..
