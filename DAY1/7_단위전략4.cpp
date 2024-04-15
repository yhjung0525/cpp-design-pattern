// #3. ���� ����(policy base design)
// => �������̽� ����� ��å Ŭ���� ��ü�� �ƴ�
// => ���ø� ���ڷ� ��å Ŭ���� ��ü
// => STL ���̺귯���� ���� ����


template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	Alloc ax;	// �޸� �Ҵ�� ��ü
				// ������ vector �� ��� ��� �Լ�������
				// �޸� �Ҵ��� �ʿ� �Ҷ� ���� ax �� ��� �Լ��� ����ؾ� �Ѵ�.
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

