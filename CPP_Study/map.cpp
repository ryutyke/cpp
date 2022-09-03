#include <iostream>
using namespace std;
#include <map>

class Player
{
public:
	Player() : _playerId(0) {}
	Player(int playerId) : _playerId(playerId) {}
public:
	int _playerId;
};

int main()
{
	// 연관 컨테이너

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	// vector나 list 같은 선형 자료구조 치명적 단점
	// 모든 인덱스를 순차적으로 들려야 함
	// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다
	
	// 데이터 찾기, 데이터 넣기 빠름

	srand(static_cast<unsigned int>(time(nullptr)));
	// <Key, Value)
	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200)); // 이미 있으면 value 안 바꿈

	// 게임에 10만명 플레이어 입장
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));

	}
	// 1명 ~ 5만명의 플레이어 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;
		
		// Erase By Key
		m.erase(randomValue); // 지우면 1 없어서 못 지우면 0 size_t로 반환
	}
	
	// ID = 10000인 Player 찾고 싶다
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "못찾음" << endl;
	}

	// map 순회
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		int key = p.first;   //it->first
		int value = p.second;//it->second

		cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정
	map<int, int>::iterator findIt2 = m.find(10000);
	if (findIt2 != m.end())
	{
		findIt2->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// 없으면 추가, 있으면 수정 v2
	m[10000] = 300;
	
	// [] 연산자의 주의사항!!!
	// 대입을 하지 않더라도 (Key/Value) 형태의 데이터가 추가된다!
	m.clear();
	
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	// (Key/기본값0) 추가 됨

	return 0;
}