// 핵심 : protected 생성자의 의미!
// => 자신의 객체는 생성할수 없지만( 추상적인 존재 )
// => 파생 클래스의 객체는 생성할수 있도록(구체적,concrete) 하겠다는 의미.

class Animal
{
//public:		// A, B 모두 에러 아님
//private:		// A, B 모두 에러
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// A	error
	Dog    d;	// B	ok. 
}



