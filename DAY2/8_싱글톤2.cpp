#include <iostream>

// ���� �Ѱ��� ��ü�� ���� ����� �� 

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
int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








