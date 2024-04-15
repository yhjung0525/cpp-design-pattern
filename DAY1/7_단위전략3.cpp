// #2. strategy 패턴 적용
// => 변하는 것을 다른 클래스로 설계
// => 인터페이스를 사용해서 교체

// 모든 메모리 할당기 정책 클래스가 지켜야 하는 규칙 설계
template<typename T>
struct IAllocator
{
	virtual T* allocate(int sz) = 0;
	virtual void deallocate(T* p, int sz) = 0;
};

template<typename T>
class vector
{
	IAllocator<T>* ax;
public:
	void set_allocator(IAllocator<T>* p) { ax = p; }
	void resize(int n)
	{
		T* p = ax->allocate(n);
		//.....
		ax->deallocate(p, n);
	}
};

