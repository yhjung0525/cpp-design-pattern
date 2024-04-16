#include <iostream>
#include <string>

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class Picture : public IDraw
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
	}

	void draw() { std::cout << "draw " << url << std::endl; }
};

//===================================================

// 기능 추가 클래스들은 공통의 특징이 있습니다.
// 이경우 기반 클래스로 설계하는 것이 좋습니다.
class Decorator : public IDraw
{
	int x, y; // 추가그림의 위치
	IDraw* pic;
public:
	Decorator(IDraw* p) : pic(p), x(0), y(0) {}

	void draw() { pic->draw(); }
};

class DrawFrame : public Decorator
{
public:
	DrawFrame(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "===================\n";
		Decorator::draw();
		std::cout << "===================\n";
	}
};

class DrawFlower : public Decorator
{
public:
	DrawFlower(IDraw* p) : Decorator(p) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&\n";
		Decorator::draw();
		std::cout << "&&&&&&&&&&&&&&&&&&&\n";
	}
};
int main()
{
	Picture pic("www.naver.com/a.png");

	DrawFrame frame(&pic);
	frame.draw();

	DrawFlower flower(&frame);
	flower.draw();
}

// Composite 와 Decorator 는 결국 재귀적인 특징이 있습니다.
// => 재귀적인 포함을 위해서 공통의 기반 클래스 설계
// => 차이점이 뭔가요 ?

// 의도에 따라 패턴의 이름이 다릅니다. 항상 "의도(intent)" 가 핵심

// composite : 재귀적 포함을 사용한 "복합객체 만들기", 즉 객체의 포함관계
// decorator : 재귀적 포함을 사용해서 "객체에 기능 추가"

// 즉, class Diagram 이 유사하지만 "의도가 완전히 다릅니다."