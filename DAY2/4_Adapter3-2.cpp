#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Policy Base Design(���� ����)�� ������ ���ô�.
// => Ŭ������ ���������� ����ϴ� ��å�� template ���ڷ� ��ü�Ҽ� �ְ� �ϴ� ������

template<typename T, typename C = std::deque<T> > class stack
{
	C c;  
public:
	constexpr void push(const T& a) { c.push_back(a); }
	constexpr void pop() { c.pop_back(); }
	constexpr T& top() { return c.back(); }
};
#include <stack> // C++ ǥ���� stack
				 // => �� �ȿ� �� stack �ڵ尡 �ֽ��ϴ�.
				 // => ���� "stack adapter" ��� �մϴ�.
int main()
{
	stack<int> s; // std::deque �� stack ó�� ����ϰڴٴ� �ǵ�
	s.push(10);

	stack<int, std::list<int>> s2;   // std::list �� stack ó�� ���
	stack<int, std::vector<int>> s3; // std::vector �� stack ó�� ���
}