#include <iostream>
using namespace std;

// 캐스팅 (타입 변환)
// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast
// (int) => 옛날 C 스타일

void PrintName(char* str)
{
	cout << str << endl;
}

class Player
{
public:
	virtual ~Player() {}
};

class Knight : public Player
{
public:

};

class Archer : public Player
{
public:

};

class Dog
{

};

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해줌
	// 1) int <-> float
	// 2) Player* -> Knight* (다운캐스팅) << 단, 안정성은 보장 못함

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// 부모->자식 자식->부모
	Player* p = new Knight(); // new Archer() 였다면 Knight에 Archer 들어가는 문제 생김 -> dynamic_cast로 해결
	Knight* k1 = static_cast<Knight*>(p);

	// dynamic_cast : 상속 관계에서의 안전 형변환
	// RTTI (RunTime Type Information) (vftable)
	// 다형성을 활용하는 방식
	// - virtual 함수를 하나라도 만들면 vftable을 통해 맞는 타입인지 확인
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환
	Knight* k2 = dynamic_cast<Knight*>(p);
	// 단점: static_cast보다 무거움

	// const_cast : const를 붙이거나 떼거나

	//PrintName("Ryu"); 안됨. const 떼어줘야함
	//PrintName((char*)"Ryu"); 됨
	PrintName(const_cast<char*>("Ryu")); // const를 떼려고 그랬다는걸 표현하기 위해
	
	// reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등
	__int64 address = reinterpret_cast<__int64>(k2);
	Dog* dog1 = reinterpret_cast<Dog*>(k2); // 상속관계 아니어도 되기는 함

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	free(p);

	// 명시를 위해 쓰이는 듯

	return 0;
}