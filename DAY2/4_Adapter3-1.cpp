#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 포함을 사용한 Adapter
// => list 자체의 기능을 외부에 노출하지는 않겠다는 의도

template<typename T> class stack 
{
//	std::list<T>* c; // 이렇게 포인터나 참조 라면, 외부에 있는 객체를 가리킨다는 의미
					 // 따라서, 객체 어답터
	std::list<T> c;  // 이렇게 하면 stack 생성시, list 도 같이 생성됨.
					 // 즉, stack 이 list 를 소유. 따라서 클래스 어답터.
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()		      { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
}