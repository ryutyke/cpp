#include <iostream>
using namespace std;

void IncreaseHp(int hp)
{
	int finalHp = hp + 1;
}

// �ϳ��� stack frame [�Ű�����][RET][��������]

// IncreaseHp ���� ��
// [�Ű�����][RET][��������(hp=1)]  [�Ű�����(hp=1)][RET][��������(finalHp=2)]
// IncreaseHp ������
// [�Ű�����][RET][��������(hp=1)]

int main()
{
	int hp = 1;

	IncreaseHp(hp);

	return 0;
}