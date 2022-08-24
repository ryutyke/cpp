#include <iostream>
using namespace std;

unsigned char flag; // 부호를 없애야 부호비트가 따라오지 않음

int main()
{
#pragma region 비트연산

	// 언제 필요한가? (많이는 없음)
	// 비트 단위의 조작이 필요할 때
	// 대표적으로 BitFlag

	// ~ bitwise not
	// 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로 뒤바꿈

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로 , and를 한다

	// | bitwise or
	// or을 한다

	// ^ bitwise xor
	// xor을 한다 같으면 0 다르면 1

	// << 비트 좌측 이동
	// n 만큼 좌측 shift
	// *2를 할 때 쓰임

	// >> 비트 우측 이동
	// - 부호 비트가 존재할 경우 부호 비트를 따라감
	// - 아니면 0
	// 따라서 bitflag로 사용할때는 unsigned로 해주는게 좋음

	// 0b0000 [무적][변이][스턴][공중에뜸]

	// 무적 상태로 만든다
	// flag = (1 << 3); // flag = 8이라고 넣기보다 의미 전달 잘 되고, 큰 수 일때는 숫자로 하기 힘듬

	const int INVINCIBLE = 3;
	flag = (1 << INVINCIBLE);

	// 변이 상태를 추가한다 (무적 + 변이)
	flag |= (1 << 2);

	// 무적인지 확인하고 싶다 (다른 상태는 관심 없음)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);


#pragma endregion
}