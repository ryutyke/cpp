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
	// �迭�� ũ��� ������� �� (Visual studio c++ ����)
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

	int numbers[5] = {}; // ��� 0���� �ʱ�ȭ
	int numbers1[10] = { 1,2,3,4,5 }; // 1~5 �ʱ�ȭ ������ 0
	int numbers2[] = { 1,2,3,4,5,6,7,8,9 }; // ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭 �����.
	

	return 0;
}