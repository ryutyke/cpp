#include <iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char** a) // == const char*& a
{
	*a = "Bye";
}

int main()
{
	int a = 0;
	SetNumber(&a);

	const char* msg = "Hello";

	SetMessage(&msg);

	cout << msg << endl;

	return 0;
}