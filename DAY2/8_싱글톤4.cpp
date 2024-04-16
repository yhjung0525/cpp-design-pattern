#include <iostream>
#include <mutex>

// RAII
// => �ڿ� ������ "������" �� "�Ҹ���" ���� �ؾ� �Ѵ�.

template<typename T>
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard( )            { mtx.unlock(); }
};




class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:

	static Cursor& get_instance()
	{
		{
			std::lock_guard<std::mutex> g(mtx);
//			lock_guard<std::mutex> g(mtx);	// �����ڿ��� mtx.lock()����.
											// �Ҹ��ڿ��� mtx.unlock()
											// �Լ� ������ ���ܵ��� �߻��ص� �Ҹ���ȣ�⺸��
//		mtx.lock();

			if (sinstance == nullptr)
				sinstance = new Cursor;

			//		mtx.unlock();
		}

		return *sinstance;
	}
};

Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

}








