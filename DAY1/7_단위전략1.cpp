// STL �� ����
template<typename T>
class vector
{
public:
	void resize(int n)
	{
		// resize �˰����� �����Ҷ��� �޸� �Ҵ� �� �ʿ��մϴ�.
		// 
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

		T* p = new T[n];	// �̷��� ���� ����ϸ�
		delete[] p;			// �ٸ� �޸� �Ҵ� ������� ��ü�Ҽ� �����ϴ�.
	}
};

