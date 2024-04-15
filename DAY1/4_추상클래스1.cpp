// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다, 단, 포인터 변수는 만들수 있다.
class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
							 // 특징 : 구현부가 없고, "=0" 으로 표기
							 
};
class Rect : public Shape
{
	// draw() 의 구현은 제공하지 않으면 Rect 도 추상(abstract)이다.
	// draw() 의 구현은 제공하면 Rect 는 추상이 아니다.(구체, concrete type)
public:
	void draw() override {}
};

int main()
{
//	Shape  s; // error
	Shape* p; // ok
	Rect  r;  // ok
}
