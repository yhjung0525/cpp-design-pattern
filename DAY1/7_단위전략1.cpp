// STL 의 원리
template<typename T>
class vector
{
public:
	void resize(int n)
	{
		// resize 알고리즘을 구현할때는 메모리 할당 이 필요합니다.
		// 
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 

		T* p = new T[n];	// 이렇게 직접 사용하면
		delete[] p;			// 다른 메모리 할당 기법으로 교체할수 없습니다.
	}
};

