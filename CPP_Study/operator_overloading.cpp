#include <iostream>
using namespace std;


// 기타
// 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것

// - 증감 연산자 ++ --
// -- 전위형 (++a) operator++()
// -- 후위형 (a++) operator++(int)
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

	Position& operator=(const Position& arg) // 복사 대입 연산자
		// const 안붙이면 Position operator++(int) 실행한 값 복사 대입 안됨 
		// & 형식을 달라고 했는데 이는 고칠 마음이 있다는 형식이라
		// Position& 그냥 Position을 주면 안됨
		// const를 붙이면 고칠 마음이 없는 것이므로 복사 대입 됨
		// 결론: const를 붙여라
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