#include <iostream>
using namespace std;

class Knight
{
public:
	// [1] �⺻ ������ (���ڰ� ����)
	Knight()
	{
		cout << "Knight() �⺻ ������ ȣ��" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] ���� ������
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] ��Ÿ ������

	// ���ڸ� 1���� �޴� ��Ÿ �����ڸ� Ÿ�� ��ȯ �����ڶ�� ��
	explicit Knight(int hp)
	{
		cout << "Knight(int) ������ ȣ��" << endl;
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
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}

	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0; //������� ���� this->_hp = 0 �� �Ȱ��� �Ǿ� ����
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

	Knight k3(k2);   // ���������
	Knight k4 = k1;	 // ���������

	Knight k5; // �⺻������
	k5 = k1;   // �� ����

	int num = 1;
	float f = (float)num; // ����� ����ȯ
	double d = num;       // �Ͻ��� ����ȯ
	
	//Knight k6;
	//k6 = 1;  // Ÿ�� ��ȯ ������ 1�� kight������ ��ȯ Knight(1);

	//HelloKnight(5); // => 5�� Knight�� �Ͻ��� ����ȯ
	// �̷��� ������ ����ų �� �ִ� ���ʿ��� �Ͻ��� Ÿ�� ��ȯ �����ڸ� ���� �ȴٸ�
	// explicit �� ����ϸ� ��

	return 0;
}