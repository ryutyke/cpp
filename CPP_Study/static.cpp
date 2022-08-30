#include <iostream>
using namespace std;

// C++������ struct�� class�� ���� �� �� ���̴�.
// struct�� �⺻ ���� �����ڰ� public�̰�, class�� private��.
// �� �̷��� ������? C++�� C���� �Ļ��Ǿ� �����߱� ������, ȣȯ���� ��Ű�� ����.
// -> struct�� �׳� ����ü (������ ����)�� ǥ���ϴ� �뵵
// -> class�� ��ü ���� ���α׷����� Ư¡ ��Ÿ���� �뵵

// static ����, static �Լ�

class Marine
{
public:
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// Ư�� ���� ��ü�� ����
	// �����̶�� 'Ŭ����' ��ü�� ����
	static void SetAttack()
	{
		// _hp = 100; �ȵ�
		s_attack = 100;
	}


	static int s_attack;
};

// static ������ � �޸�?
// �ʱ�ȭ�ϸ� .data����
// ���ϸ� .bss����
int Marine::s_attack = 0;

class Player
{
public:
	int _id;
};

// ���� ���� ��ü
static int s_global = 1;

int Generateld()
{
	// �����ֱ�: ���α׷� ����/���� (�޸𸮿� �׻� �ö� ����)
	// ���ù���: �Լ� ����

	// ���� ���� ��ü
	static int s_id = 1;
	// �ʱ�ȭ�� �Լ� ù ��붧�� ��

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

	// ���� ���ݷ� ���׷��̵� �Ϸ�! ��� ��ü ���ݷ� �÷������
	//m1.s_attack = 7;
	//m2.s_attack = 7;
	Marine::s_attack = 7;
	Marine::SetAttack();

	// static int�� ���ø޸� �ƴϰ� .data
	static int id = 10;
	int a = id;

	return 0;
}