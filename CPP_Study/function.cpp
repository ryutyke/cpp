#include <iostream>
using namespace std;

void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}

void PrintNumber(int num)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << num << " �Դϴ�." << endl;
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