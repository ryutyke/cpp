#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defense;
};

void EnterLoby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
//플레이어 승리시 true 패배 false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLoby();

	return 0;
}

void EnterLoby()
{
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player = CreatePlayer(); //이렇게 하면 어셈블리 뜯어보면 player 외에 StatInfo 하나 만들어서 createplayer에서 만든거 넣어주고 그 후 player에 옮겨줌

	StatInfo monster;
	CreateMonster(&monster); //포인터의 장점

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defense = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defense = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defense;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defense;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 HP : " << monster->hp << endl;

		if (player->hp == 0)
			return false;
	}
}