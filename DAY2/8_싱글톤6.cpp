#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;			
	void operator=(const Cursor&) = delete;	

public:

	// �Ʒ� �Լ��� "thread-safe" �ұ�� ?
	// => �����մϴ�.
	// => C++11 ���� static ���������� ������ ȣ����
	//    ǥ�ؿ��� "��Ƽ������ �����ϴ�" ��� ���� �߽��ϴ�.
	// �Ϲ������� "spin lock" ���� ����ȭ �˴ϴ�.

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








