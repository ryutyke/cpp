#include <iostream>
using namespace std;

// ĳ���� (Ÿ�� ��ȯ)
// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast
// (int) => ���� C ��Ÿ��

void PrintName(char* str)
{
	cout << str << endl;
}

class Player
{
public:
	virtual ~Player() {}
};

class Knight : public Player
{
public:

};

class Archer : public Player
{
public:

};

class Dog
{

};

int main()
{
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� �������
	// 1) int <-> float
	// 2) Player* -> Knight* (�ٿ�ĳ����) << ��, �������� ���� ����

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// �θ�->�ڽ� �ڽ�->�θ�
	Player* p = new Knight(); // new Archer() ���ٸ� Knight�� Archer ���� ���� ���� -> dynamic_cast�� �ذ�
	Knight* k1 = static_cast<Knight*>(p);

	// dynamic_cast : ��� ���迡���� ���� ����ȯ
	// RTTI (RunTime Type Information) (vftable)
	// �������� Ȱ���ϴ� ���
	// - virtual �Լ��� �ϳ��� ����� vftable�� ���� �´� Ÿ������ Ȯ��
	// - ���� �߸��� Ÿ������ ĳ������ ������, nullptr ��ȯ
	Knight* k2 = dynamic_cast<Knight*>(p);
	// ����: static_cast���� ���ſ�

	// const_cast : const�� ���̰ų� ���ų�

	//PrintName("Ryu"); �ȵ�. const ���������
	//PrintName((char*)"Ryu"); ��
	PrintName(const_cast<char*>("Ryu")); // const�� ������ �׷��ٴ°� ǥ���ϱ� ����
	
	// reinterpret_cast
	// ���� �����ϰ� ������ ������ ĳ����
	// - �����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
	__int64 address = reinterpret_cast<__int64>(k2);
	Dog* dog1 = reinterpret_cast<Dog*>(k2); // ��Ӱ��� �ƴϾ �Ǳ�� ��

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	free(p);

	// ��ø� ���� ���̴� ��

	return 0;
}