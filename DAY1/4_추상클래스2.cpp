//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ????
}

// OCP 개념
// 기능 확장에는 열려 있고(Open, 클래스/모듈 등이 추가되어도)
// 코드 수정에는 닫혀있어야(Close, 기존의 코드는 수정되지 않도록)
// 만들어야 한다는 이론(Principle)

// => 개방 폐쇄의 법칙(Open Close Principle )

// SW 설계의 5개 원칙
// => SRP, OCP, LSP, ISP, DIP => 약자로 SOLID



