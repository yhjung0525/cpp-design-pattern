// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   어디에서나 동일하게 접근 가능한것

// => 결국 "전역변수" 와 동일!!
// => 그런데, 전역변수는 함수간 의존성이 많아져서 좋지 않습니다.
// => 그래서, "싱글톤" 패턴에 대한 비판도 많이 있습니다.

class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자를 제거
	Cursor(const Cursor&) = delete;			// 복사생성자를 삭제하면
	void operator=(const Cursor&) = delete;	// 관례상 대입 연산자도 삭제


	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
//	Cursor c1, c2;
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

//	Cursor c3 = c1; // 복사 생성자를 사용한 객체 생성
}








