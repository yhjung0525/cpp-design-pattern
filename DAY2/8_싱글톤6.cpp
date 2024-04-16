#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;			
	void operator=(const Cursor&) = delete;	

public:

	// 아래 함수는 "thread-safe" 할까요 ?
	// => 안전합니다.
	// => C++11 부터 static 지역변수의 생성자 호출은
	//    표준에서 "멀티스레드 안전하다" 라고 정의 했습니다.
	// 일반적으로 "spin lock" 으로 동기화 됩니다.

	static Cursor& get_instance()
	{
		static Cursor instance;

		return instance;
	}


};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








