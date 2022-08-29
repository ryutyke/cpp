#include <iostream>
using namespace std;

class Knight
{
public:
	// [1] 기본 생성자 (인자가 없음)
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사 생성자
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] 기타 생성자

	// 인자를 1개만 받는 기타 생성자를 타입 변환 생성자라고 함
	explicit Knight(int hp)
	{
		cout << "Knight(int) 생성자 호출" << endl;
		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}

	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0; //어셈블리어 뜯어보면 this->_hp = 0 와 똑같이 되어 있음
		cout << "Die" << endl;
	}

public:
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(const Knight& k)
{
	cout << "Hello Knight" << endl;
}

int main()
{
	Knight k1;
	
	Knight k2(80);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	Knight k3(k2);   // 복사생성자
	Knight k4 = k1;	 // 복사생성자

	Knight k5; // 기본생성자
	k5 = k1;   // 후 복사

	int num = 1;
	float f = (float)num; // 명시적 형변환
	double d = num;       // 암시적 형변환
	
	//Knight k6;
	//k6 = 1;  // 타입 변환 생성자 1을 kight형으로 변환 Knight(1);

	//HelloKnight(5); // => 5를 Knight로 암시적 형변환
	// 이러한 문제를 일으킬 수 있는 불필요한 암시적 타입 변환 생성자를 쓰기 싫다면
	// explicit 을 사용하면 됨

	return 0;
}