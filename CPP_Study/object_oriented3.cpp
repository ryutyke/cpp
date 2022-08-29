#include <iostream>
using namespace std;

// ���м�(Data Hideing) = ĸ��ȭ(Encapsulation)
// - 1) �����ϰ� �ǵ帮�� �ȵǴ� ���
// - 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// ���� �� (������ �ǵ帮�� ū�ϳ�)
// -����, ���� ���⼱

// public protected private
// - public : �������׳� ����
// - protected : ���� �ڼյ����׸� ���
// - private : class car ���ο����� ��� ����

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����
// - public : �θ���� ���� ���� �״�� (public�� public���� protected�� protected��)
// - protected : �� �ڼյ����׸� �����ٰž� (public -> protected, protected -> protected)
// - private : �������� �� ���� �ڼյ����״� �ƿ� �� �����ٰž� (public -> private, protected -> private)
// ��� ���� ������ �Ƚ��ָ� private�� ��

class Car
{
public: // (���) ���� ������
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void DisassembleCar() {} // ���� �����Ѵ�
	void RunEngine() {} //������ ������Ų��
	void ConnectCircuit() {} // ���⼱ ����

public:
	
};

class SuperCar : public Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

// 'ĸ��ȭ'
// ������ �����Ϳ� �Լ��� �������� ������� ��

class Berserker
{
public:

	int GetHp() { return _hp; }

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}
	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� (������)
private:

	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}
private:
	int _hp = 100;
};

int main()
{
	Berserker b;
	// b._hp = 20;  �̷��� ���� ���� �ع����� ����Ŀ ��� �ߵ� üũ�� �ȵ�
	// private�� �ٲٰ� ĸ��ȭ �ϱ�
	b.SetHp(20);

	return 0;
}