#include <iostream>
#include "helper.h"

/*
class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;			
	void operator=(const Cursor&) = delete;	
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
*/

class Cursor
{
	MAKE_SINGLETON(Cursor) // helper.h 에 있는 매크로
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








