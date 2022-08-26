#include <iostream>
using namespace std;

// 포인터 vs 참조
// 성능 : 동일
// 편의성 : -> 과 .  참조 승!

// 포인터는 주소를 넘겨서 원본을 넘기는 것이라는 것을 알 수 있는데
// 참조는 참조인지 복사인지 함수를 봐야 알 수 있어서 실수할 수 있음 const 사용하면 되긴 함
// pointer에 const?
// * 뒤에 const : StatInfo* const info  => info를 바꿀 수 없음 즉, 주소값을 못 바꿈
// * 앞에 const : const StatInfo* info => info에 있는 데이터를 바꿀 수 없음
// const StatInfo* const info 이것도 됨

// 초기화
// 참조는 초기화 바로 해줘야 함. 포인터는 정의 후 나중에 초기화 해줘도 됨. 포인터 nullptr

struct StatInfo
{
	int hp;
	int attack;
	int defense;
};

void EnterLoby();
void CreatePlayer(StatInfo& info);
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
	CreatePlayer(player);

	StatInfo monster;
	CreateMonster(&monster);

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;
}

void CreatePlayer(StatInfo& info) // reference는 어셈블리 상에서 pointer랑 똑같이 작동함
{
	cout << "플레이어 생성" << endl;

	info.hp = 100;
	info.attack = 10;
	info.defense = 2;
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

		cout << "플레이어 HP : " << player->hp << endl;

		if (player->hp == 0)
			return false;
	}
}