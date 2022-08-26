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
//�÷��̾� �¸��� true �й� false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLoby();

	return 0;
}

void EnterLoby()
{
	cout << "�κ� �����߽��ϴ�" << endl;

	StatInfo player;
	player = CreatePlayer(); //�̷��� �ϸ� ����� ���� player �ܿ� StatInfo �ϳ� ���� createplayer���� ����� �־��ְ� �� �� player�� �Ű���

	StatInfo monster;
	CreateMonster(&monster); //�������� ����

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "�¸�!" << endl;
	else
		cout << "�й�!" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "�÷��̾� ����" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defense = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;

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

		cout << "���� HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defense;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "�÷��̾� HP : " << monster->hp << endl;

		if (player->hp == 0)
			return false;
	}
}