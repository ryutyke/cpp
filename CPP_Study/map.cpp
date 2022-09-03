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
	// ���� �����̳�

	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���

	// vector�� list ���� ���� �ڷᱸ�� ġ���� ����
	// ��� �ε����� ���������� ����� ��
	// -> ���ϴ� ���ǿ� �ش��ϴ� �����͸� ������ ã�� �� ����
	
	// ������ ã��, ������ �ֱ� ����

	srand(static_cast<unsigned int>(time(nullptr)));
	// <Key, Value)
	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200)); // �̹� ������ value �� �ٲ�

	// ���ӿ� 10���� �÷��̾� ����
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));

	}
	// 1�� ~ 5������ �÷��̾� ����
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;
		
		// Erase By Key
		m.erase(randomValue); // ����� 1 ��� �� ����� 0 size_t�� ��ȯ
	}
	
	// ID = 10000�� Player ã�� �ʹ�
	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		cout << "ã��" << endl;
	}
	else
	{
		cout << "��ã��" << endl;
	}

	// map ��ȸ
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = (*it);
		int key = p.first;   //it->first
		int value = p.second;//it->second

		cout << key << " " << value << endl;
	}

	// ������ �߰�, ������ ����
	map<int, int>::iterator findIt2 = m.find(10000);
	if (findIt2 != m.end())
	{
		findIt2->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// ������ �߰�, ������ ���� v2
	m[10000] = 300;
	
	// [] �������� ���ǻ���!!!
	// ������ ���� �ʴ��� (Key/Value) ������ �����Ͱ� �߰��ȴ�!
	m.clear();
	
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}
	// (Key/�⺻��0) �߰� ��

	return 0;
}