// 방법 #1. template method 패턴 사용
// => 변하는 것을 가상함수로!!

template<typename T>
class vector
{
public:
	void resize(int n)
	{
		T* p = allocate(n);
		//.......
		//.......
		deallocate(p, n);
	}
	// 변하는 것을 가상함수로 !!
	virtual T* allocate(int n)         { return new T[n]; }
	virtual T* deallocate(T* p, int n) { delete[] p; }
};

