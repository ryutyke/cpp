#include <iostream>
using namespace std;

//const int ROCK = 1;
//const int SCISSORS = 2;
//const int PAPER = 3;


// ���ڸ� ���� ���ϸ� ù ���� 0���� ����
// �� ���� ������ ���� �� + 1
enum ENUM_RSP
{
	ROCK = 1,
	SCISSORS,
	PAPER,
};

// const�� ���� ��쿡 ���� memory�� ����� ���� �ִ�.
// enum�� ������ memory�� ������� �ʴ´�.
// ���� enum�� memory ���鿡�� ����.

// #�� ������ -> ��ó�� ���ù�
// 1) ��ó�� 2) ������ 3) ��ũ
// #include iostream �� iostream ���� ������ ��ó���� ���⿡ ����

// define�� ��ó�� �� �ش� ������� �ٲ�ġ��
#define DEFINE_ROCK 1
#define DEFINE_SCISSORS 2
#define DEFINE_PAPER 3
// ������ �Ǵ°� �ƴϴ�
#define DEFINE_TEST cout << "Hello World" << endl;

#define DEFINE_THREE 1+2
// define�� ���� Ư�� ����� ������ ����. ����� ��, ���콺 ���ٴ��� �� ���� ���� ��Ÿ������ �Ⱥ��̴� ��

int main()
{
	DEFINE_TEST;
	int result = DEFINE_THREE * 2; // 1+2 �״�� ���� 5 ���´�
}