#include <iostream>
using namespace std;

// new / delete
// - C++에 추가됨
// - malloc/free는 함수 , new/delete는 연산자(operator)

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete 승
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면 -> malloc/free 승리

// 그런데 둘의 중요한 차이는
// new/delete는 (생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다.
// malloc/free는 생성자/소멸자 호출 안함 ㄷㄷ 코드로 호출하게 할 수는 있음


class Monster
{
public:
	int _hp;
	int _x;
	int _y;
};

int main()
{
	Monster* m1 = new Monster;
	m1->_hp = 200;
	m1->_x = 2;
	m1->_y = 3;

	delete m1;

	Monster* m2 = new Monster[5];
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;

	Monster* m3 = (m2 + 1);
	m3->_hp = 300;
	m3->_x = 4;
	m3->_y = 5;


	delete[] m2;

	return 0;
}