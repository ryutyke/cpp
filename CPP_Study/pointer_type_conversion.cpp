#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}
public:
	int _defense = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [�ּ�] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		//��������δ� ok
		// Stack [�ּ�]
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDbId = 1; // ũ���ð� ���� ����

		delete knight;
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		//Weapon* weapon = (Weapon*)item; //��������� ��
		//weapon->_damage = 10;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		Weapon* weapon = new Weapon();

		// �Ͻ������� �ȴ�
		Item* item = weapon;

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �����ؾ� �Ѵ�
	// �Ͻ������� �� ���� �׻� �����Ѱ�?
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ� �� �ƴѰ�?

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ********************** �߿�! ***********************

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;
		
		delete item; // �߿�!! ��� ���鶧�� �θ� Ŭ������ �Ҹ��ڸ� �����Լ��� ���������
		// �θ� Ŭ������ �Ҹ��ڿ��� virtual �ٿ��൵ �� �ڽ��� �����൵ �Ǳ� ��
		// �����ָ� Item�� �Ҹ��ڸ� �����
	}

	return 0;
}