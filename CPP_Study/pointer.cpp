#include <iostream>
using namespace std;

int main()
{
	int number = 1;

	// 포인터는 4바이트(32비트), 8바이트(64비트)
	int* ptr = &number;

	int value1 = *ptr;
	*ptr = 2;

	// 포인터 연산

	// 1) 주소 연산자 (&)
	
	// 2) 산술 연산자 (+ -)
	ptr += 1; // 실제 주소값은 1바이트가 아닌 4바이트가 증가함. 다음 바구니로 이동하라라는 뜻으로, 해당 포인터 타입의 크기만큼 이동한다


	// 3) 간접 연산자 (*)
	// 4) 간접 멤버 연산자 (->)

	return 0;
}