// #2. strategy ���� ����
// => ���ϴ� ���� �ٸ� Ŭ������ ����
// => �������̽��� ����ؼ� ��ü

// ���� : �ϳ��� allocator �� ��� �����̳ʰ� ��� ����
// ���� : allocate, deallocate �Լ��� �����Լ� �̴�. ������.


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

template<typename T>
class MyAllocator : public IAllocator<T>
{
public:
	T* allocate(int sz) override { return new T[sz]; }
	void deallocate(T* p, int sz) override { delete[] p; }
};

int main()
{
	vector<int> v;

	MyAllocator ax;
	v.set_allocator(&ax);

	v.resize(10); //ax �� ����ؼ� �޸� �Ҵ� 

}

