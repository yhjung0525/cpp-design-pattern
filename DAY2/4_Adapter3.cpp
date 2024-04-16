#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// linked list 가 이미 있는데, stack 이 필요 합니다.
// 1. stack 의 모든 기능을 직접 구현.
// 2. list 의 함수이름을 stack 처럼 보이도록 변경

// #1. 상속을 사용한 Adapter
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}