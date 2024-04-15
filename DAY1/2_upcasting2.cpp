// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 #1. 동종을 저장하는 컨테이너.
	std::vector<Dog*>    v1;	// Dog 객체만 보관하는 컨테이너!
	std::vector<Animal*> v2;	// 동종(동일 기반 클래스를 사용하는 타입)
								// 을 저장하는 컨테이너
								// => 모든 동물 종류를 보관하겠다는 의도
}