#include <iostream>
#include <mutex>

// CRTP 적용
// => Curiously Recurring Template Pattern
// => 기반 클래스에서 "파생 클래스 이름을 사용" 할수 있게 하는 패턴!!

template<typename T>
class Singleton
{
protected:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;

	static T* sinstance;		// <=== !!!
	static std::mutex mtx;
public:

	static T& get_instance()	// <=== !!!
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T;	// <=== !!!

		return *sinstance;
	}
};

template<typename T> T* Singleton<T>::sinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;


// Mouse 클래스도 힙에 만드는 싱글톤으로 하고 싶다.
class Mouse : public Singleton< Mouse  >
{

};   

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}








