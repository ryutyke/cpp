#include<iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	RIGHT,
	DOWN,
	LEFT,
	UP,
};

void SetBoard()
{
	int dir = RIGHT;
	int col = 0;
	int row = 0;
	int num = 1;
	while (true)
	{
		board[col][row] = num;

		if (num == N * N)
			break;

		while (true)
		{
			switch (dir)
			{
			case RIGHT:
				if ((row + 1 != N) && (board[col][row + 1] == 0))
				{
					row++;
					break;
				}
				dir++;
			case DOWN:
				if ((col + 1 != N) && (board[col + 1][row] == 0))
				{
					col++;
					break;
				}
				dir++;
			case LEFT:
				if ((row - 1 != -1) && (board[col][row - 1] == 0))
				{
					row--;
					break;
				}
				dir++;
			case UP:
				if ((col - 1 != -1) && (board[col - 1][row] == 0))
				{
					col--;
					break;
				}
				dir = RIGHT;
				continue;
			}
			num++;
			break;
		}
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();

	return 0;
}