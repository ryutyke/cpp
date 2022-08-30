#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog() {};

	// 타입 변환 생성자
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}

	// 타입 변환 연산자
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;
};

class BullDog : public Dog
{
public:
	bool _french; // 프렌치 불독인지
};

int main()
{
	// ------------- 타입 변환 유형 (비트열 재구성 여부) -------

	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789;  //2의 보수						//075bcd15
		float b = (float)a; // 부동소수점(지수 + 유효숫자)  //4ceb79a3 최대한 123456789에 비슷하게 부동소수점 방식으로 변환
		cout << b << endl;
	}

	// [2] 참조 타입 변환
	// 특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것
	// 거의 쓸일은 없지만, 포인터 타입 변환도 '참조 타입 변환'과 동일한 룰을 따름
	{
		int a = 123456789;
		float b = (float&)a;  // 2의 보수 식으로 075bcd15 그대로 저장하고 보는 관점만 부동소수점으로
		cout << b << endl; // 그래서 엉뚱한 값이 나옴
	}

	// --------------안전도 분류----------------

	// [1] 안전한 변환
	// 특징) 의미가 항상 100% 완전히 일치하는 경우
	// 같은 타입이면서 크기만 더 큰 바구니로 이동
	// 작은 바구니 -> 큰 바구니로 이동 OK (업캐스팅)
	// ex) char -> short, short -> int, int -> __int64
	{
		int a = 123456789;
		__int64 b = a;
		cout << b << endl;
	}

	//[2] 불안전한 변환
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	// 타입이 다르거나
	// 같은 타입이지만 큰 바구니 -> 작은 바구니 이동 (다운캐스팅)
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// ---------------- 프로그래머 의도에 따라 분류 -----------

	// [1] 암시적 변환
	// 특징) 이미 알려진 타입 변환 규칙에 따라서 컴파일러가 자동으로 타입 변환
	{
		int a = 123456789;
		float b = a; // 암시적
		cout << b << endl;
	}
	// [2] 명시적 변환
	{
		int a = 123456789;
		int* b = (int*)a; // 명시적 . 주소값 보낸거 아님 a 값 16진수로 보낸거임
		cout << b << endl;
	}

	// ---------------- 아무런 연관 관계가 없는 클래스 사이의 변환 ----------

	// [1] 연관없는 클래스 사이의 '값 타입' 변환
	// 특징) 일반적으로 안 됨(예외: 타입 변환 생성자, 타입 변환 연산자)

	{
		Knight knight;
		Dog dog = (Dog)knight;
		Knight knight2 = dog;
	}

	// [2] 연관없는 클래스 사이의 참조 타입 변환
	// 특징) 명시적으로는 OK
	{
		Knight knight;
		Dog& dog = (Dog&)knight;
		dog._cuteness = 12;
	}

	// ------------- 상속 관계에 있는 클래스 사이의 변환 ------------

	// [1] 상속 관계 클래스의 값 타입 변환
	// 특징) 자식->부모 ok / 부모->자식 no
	{
		//Dog dog;
		//BullDog bulldog = dog;

		BullDog bulldog;
		Dog dog = bulldog;
	}

	// [2] 상속 관계 클래스의 참조 타입 변환
	// 특징) 자식->부모 ok / 부모->자식 암시적 no 명시적 ok
	{
		//Dog dog;
		//BullDog& bulldog = (BullDog&)dog;

		BullDog bulldog;
		Dog& dog = bulldog;
	}

	// 결론)
	// [값 타입 변환] : 진짜 비트열도 바꾸고 논리적으로 말이 되게 바꾸는 변환
	// - 논리적으로 말이 된다? -> 된다  bulldog -> dog
	// - 논리적으로 말이 안된다 -> 안됨 dog -> bulldog , dog -> knight
	// [참조 타입 변환] : 비트열은 냅두고 그 클래스가 읽는 '관점'으로만 바꾸는 변환
	// - 명시적 요구하면 해주긴 하는데, 암시적으로 해주는지는 안정성 여부에 따라 해줌
	// 안전 bulldog -> dog&
	// 메모리 침범 위험이 있는 경우는 암시적으로 해주진 않음  dog -> bulldog&
	// 명시적으로 하겠다고 하면 해줌

	return 0;
}