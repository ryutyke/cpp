#include <iostream>
using namespace std;

class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}
private:
	int _hp = 100;
};

class Functor
{
public:

	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator()(int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}
private:
	int _value = 0;
};

int main()
{
	// �Լ� ��ü (Functor) : �Լ�ó�� �����ϴ� ��ü
	// () ������ �����ε�

	Functor functor;
	functor();
	bool ret = functor(3);


	//MMO���ӿ��� �Լ� ��ü�� ����ϴ� ����
	// Ŭ�� �������� ��Ų �� : �� (5, 0) ��ǥ�� �̵�������
	//MoveTask task;
	// task._playerId = 100;
	// task._posX = 5;
	// task._posY = 0;
	
	// ���߿� ���� �� �� ����
	// task();

	// => Ŀ�ǵ� ���� (Command pattern): ��û�� ��ü�� ���·� ĸ��ȭ�Ͽ� ����ڰ� ���� ��û�� ���߿� �̿��� �� �ֵ��� �ż���
	return 0;
}