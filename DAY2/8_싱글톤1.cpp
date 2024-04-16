// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//		   ��𿡼��� �����ϰ� ���� �����Ѱ�

// => �ᱹ "��������" �� ����!!
// => �׷���, ���������� �Լ��� �������� �������� ���� �ʽ��ϴ�.
// => �׷���, "�̱���" ���Ͽ� ���� ���ǵ� ���� �ֽ��ϴ�.

class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. ���� �����ڿ� ���Կ����ڸ� ����
	Cursor(const Cursor&) = delete;			// ��������ڸ� �����ϸ�
	void operator=(const Cursor&) = delete;	// ���ʻ� ���� �����ڵ� ����


	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
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

//	Cursor c3 = c1; // ���� �����ڸ� ����� ��ü ����
}








