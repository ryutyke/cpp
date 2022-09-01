#include <iostream>
using namespace std;

class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}
private:
	int _hp = 100;
};

class Functor
{
public:

	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator()(int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}
private:
	int _value = 0;
};

int main()
{
	// 함수 객체 (Functor) : 함수처럼 동작하는 객체
	// () 연산자 오버로딩

	Functor functor;
	functor();
	bool ret = functor(3);


	//MMO게임에서 함수 객체를 사용하는 예시
	// 클라가 서버한테 시킨 일 : 나 (5, 0) 좌표로 이동시켜줘
	//MoveTask task;
	// task._playerId = 100;
	// task._posX = 5;
	// task._posY = 0;
	
	// 나중에 여유 될 때 실행
	// task();

	// => 커맨드 패턴 (Command pattern): 요청을 객체의 형태로 캡슐화하여 사용자가 보낸 요청을 나중에 이용할 수 있도록 매서드
	return 0;
}