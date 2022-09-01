#include <iostream>
using namespace std;

// 무조건 typename을 

template<typename T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % 10;
		return _data[idx];
	}

public:
	T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
	double GetRandomData()
	{
		cout << "RandomBox double" << endl;
		int idx = rand() % 10;
		return _data[idx];
	}

public:
	double _data[SIZE];
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int, 10> rb1;

	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<float, 10> rb2;

	for (int i = 0; i < 10; i++)
	{
		rb2._data[i] = i + 0.5f;
	}
	float value2 = rb2.GetRandomData();
	cout << value2 << endl;

	RandomBox<double, 10> rb3;

	for (int i = 0; i < 10; i++)
	{
		rb3._data[i] = i + 0.5;
	}
	double value3 = rb3.GetRandomData();
	cout << value3 << endl;

	return 0;
}