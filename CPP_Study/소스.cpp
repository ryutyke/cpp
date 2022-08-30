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

class Knight
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

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
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


	return 0;
}