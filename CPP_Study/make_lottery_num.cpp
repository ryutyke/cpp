#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Sort(int* numbers, int count)
{
	int least;
	for (int i = 0; i < count - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < count; j++)
		{
			if ( *(numbers + j) < * (numbers + least))
				least = j;
		}
		if(least != i)
			Swap(*(numbers + least), *(numbers + i));
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));
	int random_number;
	bool overlap;
	for (int i = 0; i < 6; i++)
	{
		while (true)
		{
			overlap = false;
			random_number = rand() % 45 + 1;
			for (int j = 0; j < 6; j++)
			{
				if (numbers[j] == random_number)
					overlap = true;
			}
			if (!overlap)
			{
				numbers[i] = random_number;
				break;
			}
		}
	}
}

int main()
{
	int numbers[6];

	ChooseLotto(numbers);

	Sort(numbers, sizeof(numbers) / sizeof(int));

	for (int num : numbers)
		cout << num << endl;

	return 0;
}