#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Policy Base Design(단위 전략)을 적용해 봅시다.
// => 클래스가 내부적으로 사용하는 정책을 template 인자로 교체할수 있게 하는 디자인

template<typename T, typename C = std::deque<T> > class stack
{
	C c;  
public:
	constexpr void push(const T& a) { c.push_back(a); }
	constexpr void pop() { c.pop_back(); }
	constexpr T& top() { return c.back(); }
};
#include <stack> // C++ 표준의 stack
				 // => 이 안에 위 stack 코드가 있습니다.
				 // => 흔히 "stack adapter" 라고 합니다.
int main()
{
	stack<int> s; // std::deque 를 stack 처럼 사용하겠다는 의도
	s.push(10);

	stack<int, std::list<int>> s2;   // std::list 를 stack 처럼 사용
	stack<int, std::vector<int>> s3; // std::vector 를 stack 처럼 사용
}