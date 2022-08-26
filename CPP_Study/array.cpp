#include <iostream>
using namespace std;


struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defense = 0xCCCCCCCC;
};

int main()
{
	// 배열의 크기는 상수여야 함 (Visual studio c++ 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	StatInfo players[10];

	StatInfo* monster_0 = monsters;

	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;

	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defense = (i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defense = (i + 1);
	}

	int numbers[5] = {}; // 모두 0으로 초기화
	int numbers1[10] = { 1,2,3,4,5 }; // 1~5 초기화 나머지 0
	int numbers2[] = { 1,2,3,4,5,6,7,8,9 }; // 데이터 개수만큼의 크기에 해당하는 배열 만든다.
	

	// 포인터 vs 배열
	const char* test1 = "Hello World";
	//포인터는 "Hello World"가 저장된 .data 부분 주소를 가지고 있을 포인터만 스택에 생성 8바이트
	char test2[] = "Hello World";
	//배열은 stack에 "Hello World"를 통째로 가져옴

	return 0;
}