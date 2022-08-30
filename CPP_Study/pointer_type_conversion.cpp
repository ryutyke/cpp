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
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [주소] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		//명시적으로는 ok
		// Stack [주소]
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDbId = 1; // 크래시가 나지 않음

		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		//Weapon* weapon = (Weapon*)item; //명시적으론 됨
		//weapon->_damage = 10;

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		// 암시적으로 된다
		Item* item = weapon;

		delete weapon;
	}

	// 명시적으로 타입 변환할 때는 항상 조심해야 한다
	// 암시적으로 될 때는 항상 안전한가?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는 거 아닌가?

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

	// ********************** 중요! ***********************

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;
		
		delete item; // 중요!! 상속 만들때는 부모 클래스의 소멸자를 가상함수로 만들어주자
		// 부모 클래스의 소멸자에만 virtual 붙여줘도 됨 자식은 안해줘도 되긴 함
		// 안해주면 Item의 소멸자만 실행됨
	}

	return 0;
}