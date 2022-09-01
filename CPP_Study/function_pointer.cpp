#include <iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;
	int _rarity;
	int _ownerId;
};

Item* FindItemByItemId(Item items[], int itemCount, int itemId)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (item->_itemId == itemId)
			return item;
	}
	return nullptr;
}

typedef bool(ITEM_SELECTOR)(Item* item);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item))
			return item;
	}
	return nullptr;
}

bool IsRareItem(Item* item)
{
	return item->_rarity >= 2;
}

int main()
{
	int a = 10;
	typedef int DATA;
	DATA* pointer = &a;

	// �Լ� ������
	typedef int(FUNC_TYPE)(int a, int b);
	// ��� c++ : using FUNC_TYPE = int(int a, int b);

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	FUNC_TYPE* fn;
	fn = &Add; // fn = Add

	int result = fn(1, 2);
	cout << result << endl;

	result = (*fn)(3, 4); // �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ� 
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 2;
	Item* rareItem = FindItem(items, 10, IsRareItem);

	return 0;
}