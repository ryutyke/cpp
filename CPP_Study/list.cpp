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
// [1] -> [2] -> [3] -> [4] -> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [ _Myhead : end() ] <-> [1]

// stl list�� ���߸���Ʈ�� �Ǿ�����

int main()
{
	// list (���� ����Ʈ)
	// - list�� ���� ����
	// - �߰� ����/���� (GOOD / GOOD)
	// - ó��/�� ����/���� (GOOD / GOOD)
	// - ���� ���� (i��° ������) (BAD)

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

	//list<int>::iterator itTest = itBegin + 10; �ȵ� ��ȿ�����̶� ++ -- �� ��
	//list<int>::iterator itTest1 = --itBegin; �ȵ�
	//list<int>::iterator itTest2 = --itEnd;   ��
	//list<int>::iterator itTest3 = ++itEnd;   �ȵ�

	int* ptrBeign = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	li.erase(li.begin());
	li.pop_front();
	li.remove(10);

	// * ���� ������ ��ȿ����, �� ������ �ȵǴµ� �߰� ����/������ ������?
	// 50�� �ε����� �ִ� �����͸� �����غ���

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;
	
	li.erase(it);
	
	// erase() ����� �Լ��� �����ٴ°���
	// ��, [49] <-> [50] <-> [51] ���� [49] <-> [51]�� ��������
	// �� 50��° node�� ã�°Ŵ� ��ȿ����
	// vector�� 50��° �ε��� �ڿ� �ִ� ��� ���� ��ĭ�� ������ ���ܾ��ϴϱ� erase�� ��ȿ����

	return 0;
}