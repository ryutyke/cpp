#include <iostream>
using namespace std;

// 다형성 (Polymorphism = Poly + morph) = 겉은 똑같은데, 기능이 다르게 동작
// - 오버로딩
// - 오버라이딩

// 바인딩(Binding)
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩 (Dynamic Binding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면 -> 가상 함수 (virtual function)

// 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해준걸까?
// - 가상 함수 테이블 (vftable)
// 가상 함수가 있는 경우에 객체 시작 주소값에 vftable이 존재

// .vftable [] 4바이트(32) 8바이트(64)
// vftable 안에는 [VMove] [ ] ... 가상함수들이 있음
// 가상함수 실행시 vftable에서 사용할 함수 주소를 가져옴

// 순수 가상 함수 : 구현은 없고 인터페이스만 전달하는 용도
// Knight Mage 등을 쓰지 Player를 쓰지 않으니
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 추상 클래스로 간주
// - 직접적으로 객체를 만들 수 없게 됨

class Player
{
public:

	Player()
	{
		_hp = 100;
	}
	void Move() { cout << "Move Player" << endl; }
	virtual void VMove() { cout << "VMove Player" << endl; }
	virtual void VDie() { cout << "VDie Player" << endl; }
	// virtual void VAttack() = 0;

public:
	int _hp;
};

class Knight : public Player
{
public:

	Knight()
	{
		_stamina = 100;
	}
	void Move() { cout << "Move Knight" << endl; }

	// 가상 함수는 재정의 하더라도 가상 함수이다.
	virtual void VMove() { cout << "VMove Knight" << endl; }
	virtual void VDie() { cout << "VDie Knight" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	player->Move(); // 정적 바인딩
	player->VMove(); // 동적 바인딩
}

int main()
{
	Player p;
	MovePlayer(&p);
	//MovePlayer(&k); // 플레이어는 기사다? No

	Knight k;
	MovePlayer(&k); // 기사는 플레이어다? yes

	return 0;
}