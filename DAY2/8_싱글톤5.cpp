#include <iostream>
#include <mutex>

// CRTP ����
// => Curiously Recurring Template Pattern
// => ��� Ŭ�������� "�Ļ� Ŭ���� �̸��� ���" �Ҽ� �ְ� �ϴ� ����!!

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


// Mouse Ŭ������ ���� ����� �̱������� �ϰ� �ʹ�.
class Mouse : public Singleton< Mouse  >
{

};   

int main()
{
	Mouse& c1 = Mouse::get_instance();
	Mouse& c2 = Mouse::get_instance();

}








