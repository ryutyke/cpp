#include <iostream>
using namespace std;

class Knight
{
public:
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};

// typedef
// [선언 문법] 앞에다가 typedef를 붙이는 것
typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];
typedef int(*PFUNC)(int, int); // int *PFUNC(int, int) => int(*PFUNC)(int, int)

typedef int(Knight::* PMEMFUNC)(int, int); // 멤버 함수 포인터

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int main()
{
	PFUNC fn;
	fn = &Test;
	fn(2, 3);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp;
	Knight k1;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}