// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& n, int a) : name(n), age(a) {}
};

// Person 에서 파생된 Student 만들어 보세요
// 1. 학번(int id) 를 추가해 보세요
// 2. 생성자도 만들어 보세요
// 3. main 에서 Student 객체 생성해 보세요.


int main()
{
	Person p("kim", 20);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


