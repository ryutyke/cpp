#include <iostream>
using namespace std;

/*
����� ����

stack frame
������ ���� �ּҿ������� ���δ�

�Լ��� �� ��, �Ű����� -> ��ȯ �ּҰ� -> �������� ��
�Լ� ret �� �ش� ������������ esp�� add�ϴ� �Ͱ� pop�� ���� ����� �� ���� ��

*/

// �Լ� �����
void PrintHelloWorld();
void PrintNumber(int num);
int MultiplyBy2(int a);
int MultiplyBy(int a, int b);

int main()
{
	PrintNumber(2);
	cout << MultiplyBy2(5) << endl;
	cout << MultiplyBy(3, 5) << endl;

	return 0;
}

// �Լ� �ȿ� �Լ�, �� �Լ� �ȿ� �Լ�, �� �Լ� �ȿ� �Լ�
// �̷������� ���ٺ��� ���߿� �ߴ������� ������� ��, ���� � ��ο��� �� �Լ��� ����ϰ� �ִ��� �ľ��ϱ� �����
// ���� ���, PlayerMove() �Լ��� ȣ�����ε�, �ڵ��̵����� �Ѿ�°��� �����̵����� �Ѿ�°��� ���
// �̸� ����� �� ������ ȣ�⽺���� ���� �ľ��� �� �ִ�
// ȣ�⽺���� ��ȯ �ּҰ����� �����ش� (�� �Լ��� ���� �� ���ư��� �ϴ� �ּҰ�)
// �� �ּҰ��� � �Լ��� �ִ� �ּҰ����� ���� �ȴ�!


// �Լ� ������
void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

void PrintNumber(int num)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << num << " �Դϴ�." << endl;
}

int MultiplyBy2(int a)
{
	a = MultiplyBy(a, 3);
	return a * 2;
}

int MultiplyBy(int a, int b)
{
	PrintNumber(a);
	return a * b;
}