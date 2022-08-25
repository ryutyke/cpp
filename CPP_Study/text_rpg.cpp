#include <iostream>
using namespace std;

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct ObjectInfo
{
	int type;
	int hp;
	int attack;
	int defense;
};

ObjectInfo playerInfo;
ObjectInfo monsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0));
	EnterLobby();


	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "�κ� �����߽��ϴ�!" << endl;
		cout << "---------------------" << endl;

		// �÷��̾� ���� ����
		SelectPlayer();

		cout << "----------------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
		cout << "----------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
			return;

	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "������ ����ּ���!" << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;
		cout << "> ";

		cin >> playerInfo.type;

		if (playerInfo.type == PT_Knight)
		{
			cout << "��� ������... !" << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defense = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer)
		{
			cout << "�ü� ������... !" << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defense = 3;
			break;
		}
		else if (playerInfo.type == PT_Mage)
		{
			cout << "���� ������... !" << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defense = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "�ʵ忡 �����߽��ϴ�!" << endl;
		cout << "---------------------" << endl;

		cout << "[Player] HP: " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defense << endl;
	
		CreateRandomMonster();

		cout << "---------------------" << endl;
		cout << "(1) ���� (2) ����" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerInfo.hp == 0)
				return;
		}
		else
			continue;
	}
	
}

void CreateRandomMonster()
{
	// 1-3 random
	monsterInfo.type = 1 + (rand() % 3);

	switch (monsterInfo.type)
	{
	case MT_Slime:
		cout << "������ ������...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defense = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defense = 3;
		break;
	case MT_Skeleton:
		cout << "�ذ� ������...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defense = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerInfo.attack - monsterInfo.defense;
		if (damage < 0)
			damage = 0;

		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0)
			monsterInfo.hp = 0;

		cout << "���� ���� ü�� : " << monsterInfo.hp << endl;
		if (monsterInfo.hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			return;
		}

		damage = monsterInfo.attack - playerInfo.defense;
		if (damage < 0)
			damage = 0;

		playerInfo.hp -= damage;
		if (playerInfo.hp < 0)
			playerInfo.hp = 0;

		cout << "�÷��̾� ���� ü�� : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0)
		{
			cout << "����� ����߽��ϴ�... GAME OVER" << endl;
			return;
		}
	}
}