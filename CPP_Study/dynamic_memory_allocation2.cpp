#include <iostream>
using namespace std;

// new / delete
// - C++�� �߰���
// - malloc/free�� �Լ� , new/delete�� ������(operator)

// malloc/free vs new/delete
// - ��� ���Ǽ� -> new/delete ��
// - Ÿ�Կ� ������� Ư���� ũ���� �޸� ������ �Ҵ�������� -> malloc/free �¸�

// �׷��� ���� �߿��� ���̴�
// new/delete�� (����Ÿ���� Ŭ������ ���) ������/�Ҹ��ڸ� ȣ�����ش�.
// malloc/free�� ������/�Ҹ��� ȣ�� ���� ���� �ڵ�� ȣ���ϰ� �� ���� ����


class Monster
{
public:
	int _hp;
	int _x;
	int _y;
};

int main()
{
	Monster* m1 = new Monster;
	m1->_hp = 200;
	m1->_x = 2;
	m1->_y = 3;

	delete m1;

	Monster* m2 = new Monster[5];
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;

	Monster* m3 = (m2 + 1);
	m3->_hp = 300;
	m3->_x = 4;
	m3->_y = 5;


	delete[] m2;

	return 0;
}