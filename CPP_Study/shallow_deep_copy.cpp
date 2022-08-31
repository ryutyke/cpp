#include <iostream>
using namespace std;

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}
	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}
public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}

	Knight(const Knight& knight) : Player(knight) // 부모클래스 복사생성자도 해줘야함
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // 깊은 복사
	}

	Knight& operator=(const Knight& knight)
	{
		Player::operator=(knight); // 부모클래스 복사 대입 연산자도 해줘야함
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // 깊은 복사
		return *this;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Knight knight; // 기본 생성자
	knight._hp = 200;

	Knight knight2 = knight; // 복사 생성자
	// Knight knight2(knight);

	Knight knight3; // 기본 생성자
	knight3 = knight; // 복사 대입 연산자

	// [ 얕은 복사 Shallow Copy]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
	// 소멸자에서 delete 문제됨

	// [ 깊은 복사 Deep Copy]
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다

	// - 암시적 복사 생성자 Steps
	// 1) 부모 클래스의 복사 생성자 호출
	// 2) 멤버 클래스의 복사 생성자 호출  (Pet)
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
	// - 명시적 복사 생성자 Steps
	// 1) 부모 클래스의 기본 생성자 호출
	// 2) 멤버 클래스의 기본 생성자 호출

	// - 암시적 복사 대ㅐ입 연산자 Steps
	// 1) 부모 클래스의 복사 대입 연산자 호출
	// 2) 멤버 클래스의 복사 대입 연산자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
	// - 명시적 복사 대입 연산자 Steps
	// 1) 알아서 해주는거 없음

	return 0;
}