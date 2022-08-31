#pragma once

// 전방선언
// 나중에 Player라는 애가 나올거다라고만 알려주면 됨
// 차피 Player* _player는 8바이트짜리 주소바구니
class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void CreatePlayer();

private:
	Player* _player;
	Field* _field;
};

