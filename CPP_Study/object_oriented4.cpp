#include <iostream>
using namespace std;

// ������ (Polymorphism = Poly + morph) = ���� �Ȱ�����, ����� �ٸ��� ����
// - �����ε�
// - �������̵�

// ���ε�(Binding)
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε� (Dynamic Binding) : ���� ������ ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ� -> ���� �Լ� (virtual function)

// ���� ��ü�� � Ÿ������ ��� �˰� �˾Ƽ� �����Լ��� ȣ�����ذɱ�?
// - ���� �Լ� ���̺� (vftable)
// ���� �Լ��� �ִ� ��쿡 ��ü ���� �ּҰ��� vftable�� ����

// .vftable [] 4����Ʈ(32) 8����Ʈ(64)
// vftable �ȿ��� [VMove] [ ] ... �����Լ����� ����
// �����Լ� ����� vftable���� ����� �Լ� �ּҸ� ������

// ���� ���� �Լ� : ������ ���� �������̽��� �����ϴ� �뵵
// Knight Mage ���� ���� Player�� ���� ������
// �߻� Ŭ���� : ���� ���� �Լ��� 1�� �̻� ���ԵǸ� �߻� Ŭ������ ����
// - ���������� ��ü�� ���� �� ���� ��

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

	// ���� �Լ��� ������ �ϴ��� ���� �Լ��̴�.
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
	player->Move(); // ���� ���ε�
	player->VMove(); // ���� ���ε�
}

int main()
{
	Player p;
	MovePlayer(&p);
	//MovePlayer(&k); // �÷��̾�� ����? No

	Knight k;
	MovePlayer(&k); // ���� �÷��̾��? yes

	return 0;
}