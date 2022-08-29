#include <iostream>
using namespace std;

// �̷� �ſ� ��� ���
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

		cout << "Player() �⺻ ������ ȣ��" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defense = 0;

		cout << "Player(int hp) �⺻ ������ ȣ��" << endl;
	}

	~Player()
	{
		cout << "~Player() �Ҹ��� ȣ��" << endl;
	}

	void Move() { cout << "Player Move ȣ��" << endl; }
	void Attack() { cout << "Player Attack ȣ��" << endl; }
	void Die() { cout << "Player Die ȣ��" << endl; }

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
		��ó�� ����
		- ���⼭ Player() �����ڸ� ȣ��
		*/
		
		_stamina = 100;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) : Player(100)  //��ó�� �������� ����� ������ ����
	{
		_stamina = stamina;
		cout << "Knight(int stamina) ������ ȣ��" << endl;
	}

	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}
	/*
		��ó�� ����
		- ���⼭ ~Player() �Ҹ��ڸ� ȣ��
	*/

	// �������̵�
	void Move() { cout << "Knight Move ȣ��" << endl; }

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
	//k.Player::Move(); ����


	return 0;
}