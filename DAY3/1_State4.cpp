#include <iostream>

// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로!!
// 2. 변하는 것을 다른 클래스로!!
//	  => 변해야 하므로, 변하는 것을 인터페이스를 먼저 설계

// 아이템 여부에 따라 변해야 하는 모든 동작을 인터페이스로 먼저 설계
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// 그외에, jump, slide, fly 등.. 
};

// 이제 각 아이템에 따른 동작을 정의하는 동작 클래스를 설계 합니다.
class NoItem : public IAction
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IAction
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
// 이외에도 다양한 아이템 상태에 따라 동작 클래스를 설계 합니다.
// 동작 클래스 : 데이타를 제외한 캐릭터 클래스의 동작만 가진 클래스... 

class Charater
{
	int gold;
	int item;
	
	NoItem ni;
	SuperItem si;

	IAction* action = &ni;
public:	
	void run()    { action->run(); }
	void attack() { action->attack(); }

	void set_item()
	{
		// 아이템을 획득하면 캐릭터의 동작 전체를 변경합니다.
		// 즉, 객체의 "상태변경" 에 따라 모든 동작을 교체 합니다
		// 단, 기존의 다양한 멤버 데이타는 유지 됩니다.
		action = &si; // 결국, 대부분의 멤버 함수를 교체하는 효과!!
	}
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p->set_item();
	p->run();
	p->attack();

}


// 자판기는 거의 모든 기능이 아래의 상태에 따라 다릅니다.
// 1. 동전을 넣지 않은 상태
// 2. 동전을 넣은 상태
// 3. 음료(커피)를 만들고 있는 상태.

// 1~2개의 기능이 다른것이 아니라
// 거의 모든 기능(함수)가 다릅니다.

// 1. 자판기의 모든 동작 함수를 위 3가지 경우에 맞게 만들게 됩니다.
// => 위의 NoItem, SuperItem 처럼. 

// 2. 그리고 자판기의 상태가 변할때 마다 동작을 교체 합니다
// => 위 코드의 set_item 처럼

//==========================================
// 전략 패턴(strategy) 와 동일한거 아닌가요 ?
// => 클래스 Diagram 은 완벽히 동일합니다. 
// => 코드도 거의 동일합니다.


// 인터페이스 기반의 변하는 것을 교체하는 기술은
// 3개의 디자인 패턴이 있습니다.
// => 아래 3개의 패턴은 다이어그램이 모두 동일하고, 코드도 유사 합니다.
// 
// strategy : 객체가 사용하는 "알고리즘" 을 교체. 바둑의 다음수 예측, validation 정책

// state    : 객체에 상태에 따라 "대부분의 동작을 교체", 마치 다른 클래스를 사용하는것 같음
//			  자판기는 동전 유무에 따라 대부분의 동작이 변경
//			  게임캐릭터의 Item여부에 따라 대부분의 동작 변경

// builder  : 복잡한 객체를 만들때, 만드는 공정은 동일한데, 각 공정이 다른 경우.
