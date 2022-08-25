#include <iostream>
using namespace std;

/*
어셈블리 뜯어보면

stack frame
스택은 높은 주소에서부터 쌓인다

함수가 들어갈 때, 매개변수 -> 반환 주소값 -> 지역변수 들어감
함수 ret 후 해당 스택프레임은 esp에 add하는 것과 pop을 통해 사용할 수 없게 됨

*/


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
	return a * 2;
}

int MultyplyBy(int a, int b)
{
	return a * b;
}

int main()
{
	PrintNumber(2);
	cout << MultiplyBy2(5) << endl;
	cout << MultyplyBy(3, 5) << endl;

	return 0;
}