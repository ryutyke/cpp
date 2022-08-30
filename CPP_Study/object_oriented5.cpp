#include <iostream>
using namespace std;

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++11 ����

// �ʱ�ȭ ����Ʈ
// - ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���̰� ����
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (����Ÿ��, const)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};

class Player
{
public:
	Player() {}
	Player(int id) {}
};

// Is-A (Knight Is-A Player? ���� �÷��̾�� ) OK -> ��Ӱ���
// Knight is a inventory? no
// Has-A (Knight Has-A Inventory? ���� �κ��丮�� �����ϰ� �ִ�) OK -> ���԰���

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
	{

	}


public:
	int _hp;
	Inventory _inventory;

	int& _hpRef;          // ��ó������ �ʱ�ȭ �����ָ� �ȵ� C++11������ ���൵ ��
	const int _hpConst;	  // ��ó������ �ʱ�ȭ �����ָ� �ȵ� C++11������ ���൵ ��
};


int main()
{

	return 0;
}