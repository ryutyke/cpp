#include <iostream>
using namespace std;

int main()
{
	int arr2[2][2] = { {1,2}, {3,4} };

	// int가 2개 있는 배열의 포인터
	int(*p2)[2] = arr2;
	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;

	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	return 0;
}