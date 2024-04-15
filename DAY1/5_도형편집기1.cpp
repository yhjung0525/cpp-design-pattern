#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 생각해 봅시다.

// 1. 모든 도형을 타입화 하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 묶어서 관리할수 있다.
// => 모든 도형은 공통의 특징을 가지게 된다.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
//	int x, y, w, h; 생성자로 초기화.
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
//	std::vector<Rect*> v;  // Rect 만 보관할수 있는 vector
	std::vector<Shape*> v; // 모든 도형을 보관할수 있는 vector

}

