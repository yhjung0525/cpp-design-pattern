// ��� #1. template method ���� ���
// => ���ϴ� ���� �����Լ���!!

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
	// ���ϴ� ���� �����Լ��� !!
	virtual T* allocate(int n)         { return new T[n]; }
	virtual T* deallocate(T* p, int n) { delete[] p; }
};

