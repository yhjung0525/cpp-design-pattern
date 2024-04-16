#include <iostream>
#include <mutex>

// CRTP Àû¿ë


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
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new Cursor;

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








