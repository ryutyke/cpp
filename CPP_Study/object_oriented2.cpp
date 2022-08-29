#include <iostream>
using namespace std;

// 이런 거에 상속 사용
// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll

class GameObject
{
public:
	int _objectId;
};

class Player : public GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defense = 0;

		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defense = 0;

		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defense;
};

class Knight : public Player
{
public:
	Knight()
	{
		/*
		선처리 영역
		- 여기서 Player() 생성자를 호출
		*/
		
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)  //선처리 영역에서 실행될 생성자 지정
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
		후처리 영역
		- 여기서 ~Player() 소멸자를 호출
	*/

	// 오버라이딩
	void Move() { cout << "Knight Move 호출" << endl; }

public:
	int _stamina;

};

class Mage : public Player
{
public:

public:
	int _mp;
};


int main()
{
	Knight k;

	k._hp = 100;
	k._attack = 10;
	k._defense = 5;
	k._stamina = 50;

	k.Attack();
	k.Die();

	k.Move();
	//k.Player::Move(); 가능


	return 0;
}