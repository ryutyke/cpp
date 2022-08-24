#include <iostream>
using namespace std;

unsigned char flag; // ��ȣ�� ���־� ��ȣ��Ʈ�� ������� ����

int main()
{
#pragma region ��Ʈ����

	// ���� �ʿ��Ѱ�? (���̴� ����)
	// ��Ʈ ������ ������ �ʿ��� ��
	// ��ǥ������ BitFlag

	// ~ bitwise not
	// ���� ������ ��� ��Ʈ�� �������, 0�� 1, 1�� 0���� �ڹٲ�

	// & bitwise and
	// �� ������ ��� ��Ʈ ���� ������� , and�� �Ѵ�

	// | bitwise or
	// or�� �Ѵ�

	// ^ bitwise xor
	// xor�� �Ѵ� ������ 0 �ٸ��� 1

	// << ��Ʈ ���� �̵�
	// n ��ŭ ���� shift
	// *2�� �� �� ����

	// >> ��Ʈ ���� �̵�
	// - ��ȣ ��Ʈ�� ������ ��� ��ȣ ��Ʈ�� ����
	// - �ƴϸ� 0
	// ���� bitflag�� ����Ҷ��� unsigned�� ���ִ°� ����

	// 0b0000 [����][����][����][���߿���]

	// ���� ���·� �����
	// flag = (1 << 3); // flag = 8�̶�� �ֱ⺸�� �ǹ� ���� �� �ǰ�, ū �� �϶��� ���ڷ� �ϱ� ����

	const int INVINCIBLE = 3;
	flag = (1 << INVINCIBLE);

	// ���� ���¸� �߰��Ѵ� (���� + ����)
	flag |= (1 << 2);

	// �������� Ȯ���ϰ� �ʹ� (�ٸ� ���´� ���� ����)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);


#pragma endregion
}