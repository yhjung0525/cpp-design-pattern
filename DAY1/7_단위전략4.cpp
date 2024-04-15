// #3. 단위 전략(policy base design)
// => 인터페이스 기반의 정책 클래스 교체가 아닌
// => 템플릿 인자로 정책 클래스 교체
// => STL 라이브러리의 설계 원리


template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	// 메모리 할당기 객체
				// 앞으로 vector 의 모든 멤버 함수에서는
				// 메모리 할당이 필요 할때 마다 ax 의 멤버 함수를 사용해야 한다.
public:
	void resize(int n)
	{
		T* p = ax.allocate(n);
		//.....
		ax.deallocate(p, n);
	}
};

template<typename T>
class MyAllocator 
{
public:
	inline T* allocate(int sz)  { return new T[sz]; }
	inline void deallocate(T* p, int sz)  { delete[] p; }
};

int main()
{
	vector<int, MyAllocator<int> > v;

	v.resize(10); 

}

