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

	Knight(const Knight& knight) : Player(knight) // �θ�Ŭ���� ��������ڵ� �������
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
		Player::operator=(knight); // �θ�Ŭ���� ���� ���� �����ڵ� �������
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // ���� ����
		return *this;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Knight knight; // �⺻ ������
	knight._hp = 200;

	Knight knight2 = knight; // ���� ������
	// Knight knight2(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [ ���� ���� Shallow Copy]
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �Ҹ��ڿ��� delete ������

	// [ ���� ���� Deep Copy]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�

	// - �Ͻ��� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��  (Pet)
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// - ����� ���� ������ Steps
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ��

	// - �Ͻ��� ���� ����� ������ Steps
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// - ����� ���� ���� ������ Steps
	// 1) �˾Ƽ� ���ִ°� ����

	return 0;
}