// 방법 #1. template method 패턴 사용
// => 변하는 것을 가상함수로!!
// 
// 의도 : 메모리 할당 방식을 변경하려면 "vector"의 파생 클래스를 만들어서
//        allocate(), deallocate() 를 override 하는 것 는

// 단점 : 메모리 할당 정책을 재사용할수 없다.
//        list, map, set 등 다른 컨테이너도 모두 파생 클래스를 만들게 되고
//		  각각 자신들의 메모리 할당 정책을 다시 작성해야 한다.

// 컨테이너가 "메모리 할당정책을 소유" 하지 말고, 분리하는 것이 좋다.

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

