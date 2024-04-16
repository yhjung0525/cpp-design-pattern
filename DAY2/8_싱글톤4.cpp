#include <iostream>
#include <mutex>

// RAII
// => 자원 관리는 "생성자" 와 "소멸자" 에서 해야 한다.

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
//			lock_guard<std::mutex> g(mtx);	// 생성자에서 mtx.lock()수행.
											// 소멸자에서 mtx.unlock()
											// 함수 수행중 예외등이 발생해도 소멸자호출보장
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








