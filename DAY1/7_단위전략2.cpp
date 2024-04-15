// ��� #1. template method ���� ���
// => ���ϴ� ���� �����Լ���!!
// 
// �ǵ� : �޸� �Ҵ� ����� �����Ϸ��� "vector"�� �Ļ� Ŭ������ ����
//        allocate(), deallocate() �� override �ϴ� �� ��

// ���� : �޸� �Ҵ� ��å�� �����Ҽ� ����.
//        list, map, set �� �ٸ� �����̳ʵ� ��� �Ļ� Ŭ������ ����� �ǰ�
//		  ���� �ڽŵ��� �޸� �Ҵ� ��å�� �ٽ� �ۼ��ؾ� �Ѵ�.

// �����̳ʰ� "�޸� �Ҵ���å�� ����" ���� ����, �и��ϴ� ���� ����.

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

