#include <iostream>
using namespace std;

// ���� ����

// [������ ����]
// .data (�ʱⰪ �ִ� ���)
int a = 2;
// .bss (�ʱⰪ ���� ���)
int b;
// .rodata (�б� ���� ������)
const char* msg = "Hello World";

// const int�� .rodata�� ����Ǵ°�?
// C++ ǥ�ؿ��� ������� ����
// �����Ϸ� (visual studio) ���� ����

int main()
{
	// �Լ� �� ����
	// [���� ����]
	int c = 3;
	// { } �߰�ȣ�� ������ ���� ����
}