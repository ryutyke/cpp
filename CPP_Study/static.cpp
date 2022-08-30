#include <iostream>
using namespace std;

// C++에서는 struct나 class나 종이 한 장 차이다.
// struct는 기본 접근 지정자가 public이고, class는 private다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징 나타내는 용도

// static 변수, static 함수

class Marine
{
public:
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static void SetAttack()
	{
		// _hp = 100; 안됨
		s_attack = 100;
	}


	static int s_attack;
};

// static 변수는 어떤 메모리?
// 초기화하면 .data영역
// 안하면 .bss영역
int Marine::s_attack = 0;

class Player
{
public:
	int _id;
};

// 정적 전역 객체
static int s_global = 1;

int Generateld()
{
	// 생명주기: 프로그램 시작/종료 (메모리에 항상 올라가 있음)
	// 가시범위: 함수 내부

	// 정적 지역 객체
	static int s_id = 1;
	// 초기화는 함수 첫 사용때만 됨

	return s_id++;
}

int main()
{
	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);

	Marine::s_attack = 6;
	//m1.s_attack = 6;

	Marine m2;
	m2._hp = 40;
	m2.TakeDamage(5);

	//m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료! 모든 객체 공격력 올려줘야함
	//m1.s_attack = 7;
	//m2.s_attack = 7;
	Marine::s_attack = 7;
	Marine::SetAttack();

	// static int는 스택메모리 아니고 .data
	static int id = 10;
	int a = id;

	return 0;
}