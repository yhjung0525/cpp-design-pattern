#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 생각해 봅시다.

// 1. 모든 도형을 타입화 하면 편리하다.

class Rect
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

int main()
{
	std::vector<Rect*> v;

}

