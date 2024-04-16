#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// linked list �� �̹� �ִµ�, stack �� �ʿ� �մϴ�.
// 1. stack �� ��� ����� ���� ����.
// 2. list �� �Լ��̸��� stack ó�� ���̵��� ����

// list �� �Լ��̸��� stack ó�� ���̰� ����..!!
// 
// #1. ����� ����� Adapter
// => list �� ��� ����� stack �� ��ӹް�, �ܺο� ���⵵ �ϰ� �ȴ�.
// => ���� ���� ������
// => stack �� ���� list �� �Լ��� �ܺο� �����ϸ� �ȵȴ�.
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
	s.push_front(50); // ������ ��������!!!
}