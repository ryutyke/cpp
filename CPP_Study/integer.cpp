#include <iostream>
using namespace std;

int hp = 100;

char a; // 1바이트 (-128~127)
short b; // 2바이트 (-32768~32767)
int c; // 4바이트 (-21.4억~21.4억)
__int64 d; // 8바이트 (long long) (많이 큼. 경 단위)

unsigned short ub;

// 게임 제작 => 적절한 데이터 사용 중요

int main()
{
	// 정수 오버플로우
	b = 32767;
	b = b + 1;
	cout << b << endl; // -32768

	//정수 언더플로우
	ub = 0;
	ub = ub - 1;
	cout << ub << endl; // 65535

	// cout << "체력이 " << hp << " 남았습니다.";
}