#include <iostream>
using namespace std;

// 은닉성(Data Hideing) = 캡슐화(Encapsulation)
// - 1) 위험하고 건드리면 안되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들/페달/문
// 몰라도 됨 (오히려 건드리면 큰일남)
// -엔진, 각종 전기선

// public protected private
// - public : 누구한테나 공개
// - protected : 나의 자손들한테만 허락
// - private : class car 내부에서만 사용 가능

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려주지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : 부모님의 유산 설계 그대로 (public은 public으로 protected는 protected로)
// - protected : 내 자손들한테만 물려줄거야 (public -> protected, protected -> protected)
// - private : 나까지만 잘 쓰고 자손들한테는 아예 안 물려줄거야 (public -> private, protected -> private)
// 상속 접근 지정자 안써주면 private로 됨

class Car
{
public: // (멤버) 접근 지정자
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void DisassembleCar() {} // 차를 분해한다
	void RunEngine() {} //엔진을 구동시킨다
	void ConnectCircuit() {} // 전기선 연결

public:
	
};

class SuperCar : public Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것

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
	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
private:

	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}
private:
	int _hp = 100;
};

int main()
{
	Berserker b;
	// b._hp = 20;  이렇게 직접 접근 해버리면 버서커 모드 발동 체크가 안됨
	// private로 바꾸고 캡슐화 하기
	b.SetHp(20);

	return 0;
}