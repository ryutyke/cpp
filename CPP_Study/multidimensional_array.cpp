#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 1, 2,3 };

	int first[5] = { 4,2,3,4,1 };
	int second[5] = { 1,1,5,2,2 };

	int apartment2D[2][5] = { {4,2,3,4,1}, { 1,1,5,2,2} };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	int apartment1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2�� �迭�� ���� ����ұ�? ��ǥ������ 2D �α׶���ũ ��
	int map[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0},
		{1,1,1,0,1},
	};

	return 0;
}