#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;			
	void operator=(const Cursor&) = delete;	

public:
	// 아래 함수는 "thread-safe" 할까요 ?
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








