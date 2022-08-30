#include <iostream>
using namespace std;


// ��Ÿ
// ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��

// - ���� ������ ++ --
// -- ������ (++a) operator++()
// -- ������ (a++) operator++(int)
class Position
{
public:
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}
	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		return *this;
	}

	Position& operator=(const Position& arg) // ���� ���� ������
		// const �Ⱥ��̸� Position operator++(int) ������ �� ���� ���� �ȵ� 
		// & ������ �޶�� �ߴµ� �̴� ��ĥ ������ �ִٴ� �����̶�
		// Position& �׳� Position�� �ָ� �ȵ�
		// const�� ���̸� ��ĥ ������ ���� ���̹Ƿ� ���� ���� ��
		// ���: const�� �ٿ���
	{
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	Position() : _x(0), _y(0) {}
	Position(int x, int y) : _x(x), _y(y) {}

	int _x;
	int _y;
};

Position operator+(int a, const Position & b)
{
	Position ret;

	ret._x = a + b._x;
	ret._y = a + b._y;

	return ret;
}

int main()
{
	int a = 1;
	int b = 2;

	int c = a + 3.0f;

	Position pos;
	Position pos2(1, 1);
	
	Position pos3 = pos + pos2;
	Position pos4 = 1 + pos3;

	bool isSame = (pos3 == pos4);

	Position pos5;
	pos3 = (pos5 = 5);

	return 0;
}