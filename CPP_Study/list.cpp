#include <iostream>
using namespace std;
#include <list>

// vector : ���� �迭

class Node
{
public:
	Node*	_next;
	Node*	_prev; // ����
	int		_data;
};

// ���� / ���� / ����
// list : ���� ����Ʈ
// [1]   ->    [2]     ->  [3]  ->  [4]    ->    [5]
// [1]   <->    [2]     <->  [3]  <->  [4]    <->    [5]
// [1]   <->    [2]     <->  [3]  <->  [4]    <->    [5] <-> [1]

// stl list�� ���߸���Ʈ�� �Ǿ�����

int main()
{
	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i);

	int size = li.size();
	//li.capacity() ����

	int first = li.front();
	int last = li.back();

	//li[3] = 10; ����

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	li.erase(li.begin());
	li.pop_front();
	li.remove(10);


	return 0;
}