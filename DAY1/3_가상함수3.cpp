// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 1. 기반 클래스 가상함수를 override 할때 
	// => "virtual" 은 있어도 되고 없어도 됩니다.
	// => 표기하지 않아도 자동으로 virtual 
//	virtual void foo() {}

	// 2. 가상함수 override 시에 실수(오타)가 있어도
	// => 컴파일 에러가 아니라!
	// => 새로운 가상함수를 만든 것으로 컴파일러가 생각합니다.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// 3. 2번때문에 버그가 아주 많았습니다.
	// => 그래서, C++11 에서 "override" 키워드 추가
	// => 오타 등의 실수가 있으면 컴파일 에러 발생
	// => override 를 붙이는 경우는 "virtual" 이 없어도 가독성이 나쁘지 않습니다.!
	void fooo()      override {}
	void goo(double) override {}

};


int main()
{
}





