#include <iostream>
using namespace std;

int hp = 100;

char a; // 1����Ʈ (-128~127)
short b; // 2����Ʈ (-32768~32767)
int c; // 4����Ʈ (-21.4��~21.4��)
__int64 d; // 8����Ʈ (long long) (���� ŭ. �� ����)

unsigned short ub;

// ���� ���� => ������ ������ ��� �߿�

int main()
{
	// ���� �����÷ο�
	b = 32767;
	b = b + 1;
	cout << b << endl; // -32768

	//���� ����÷ο�
	ub = 0;
	ub = ub - 1;
	cout << ub << endl; // 65535

	// cout << "ü���� " << hp << " ���ҽ��ϴ�.";
}