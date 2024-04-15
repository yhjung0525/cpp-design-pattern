// #2. strategy ���� ����
// => ���ϴ� ���� �ٸ� Ŭ������ ����
// => �������̽��� ����ؼ� ��ü

// ��� �޸� �Ҵ�� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ ����
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

