//1_추상클래스2.cpp
#include <iostream>

// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는 것
// => 교체 불가능한, 경직된 디자인


// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시, 
//    규칙을 담은 인터페이스(추상클래스)를 이용해서 사용하는 것.
// => 교체 가능한, 유연한 디자인

// 인터페이스 : 규칙(순수가상함수) 만 가지고 있는것
// 추상클래스 : 규칙(순수가상함수) + 다른 멤버도 가진 경우. 

// java, C# 은 "interface" , "abstract" 라는 키워드 존재
// C++은 모두 "추상클래스 문법" 으로 만 작성. 


//=================================================================
// 카메라 제작자 와 카메라 사용자가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 표현하지 말고
// 규칙 : "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현합니다.

// 인터페이스 만들때, "class" 를 사용해도 아무 문제 없지만
// "struct" 로 하는 경우가 많습니다.(public 한줄을 표기할 필요 없으므로)

#define interface struct

//interface ICamera
struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스는 결국 기반 클래스 입니다.
							// 반드시 소멸자를 가상함수로 해야 합니다.
};





// 이제 카메라 사용자는 "규칙" 대로만 사용해야 합니다.
// 실제 카메라가 없어도, 규칙 만 알고 코드를 작성할수 있습니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// 모든 카메라 제작자는 "규칙"을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // ok.. 나중에 추가된 클래스라도
						// People 코드 수정없이 사용가능

}



