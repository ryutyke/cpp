#include <iostream>
using namespace std;

void IncreaseHp(int hp)
{
	int finalHp = hp + 1;
}

// 하나의 stack frame [매개변수][RET][지역변수]

// IncreaseHp 실행 시
// [매개변수][RET][지역변수(hp=1)]  [매개변수(hp=1)][RET][지역변수(finalHp=2)]
// IncreaseHp 끝나면
// [매개변수][RET][지역변수(hp=1)]

int main()
{
	int hp = 1;

	IncreaseHp(hp);

	return 0;
}