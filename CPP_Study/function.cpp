#include <iostream>
using namespace std;

/*
어셈블리 뜯어보면

stack frame
스택은 높은 주소에서부터 쌓인다

함수가 들어갈 때, 매개변수 -> 반환 주소값 -> 지역변수 들어감
함수 ret 후 해당 스택프레임은 esp에 add하는 것과 pop을 통해 사용할 수 없게 됨

*/

// 함수 선언부
void PrintHelloWorld();
void PrintNumber(int num);
int MultiplyBy2(int a);
int MultiplyBy(int a, int b);

int main()
{
	PrintNumber(2);
	cout << MultiplyBy2(5) << endl;
	cout << MultiplyBy(3, 5) << endl;

	return 0;
}

// 함수 안에 함수, 그 함수 안에 함수, 그 함수 안에 함수
// 이런식으로 가다보면 나중에 중단점까지 디버깅할 때, 내가 어떤 경로에서 이 함수를 사용하고 있는지 파악하기 힘들다
// 예를 들어, PlayerMove() 함수를 호출중인데, 자동이동에서 넘어온건지 수동이동에서 넘어온건지 등등
// 이를 디버깅 시 나오는 호출스택을 통해 파악할 수 있다
// 호출스택은 반환 주소값들을 보여준다 (이 함수가 끝난 후 돌아가야 하는 주소값)
// 그 주소값이 어떤 함수에 있는 주소값인지 보면 된다!


// 함수 구현부
void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

void PrintNumber(int num)
{
	cout << "넘겨주신 숫자는 " << num << " 입니다." << endl;
}

int MultiplyBy2(int a)
{
	a = MultiplyBy(a, 3);
	return a * 2;
}

int MultiplyBy(int a, int b)
{
	PrintNumber(a);
	return a * b;
}