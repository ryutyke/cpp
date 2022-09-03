#include <iostream>
using namespace std;
#include <deque>
#include <vector>
// deque : double-ended queue ��ũ

int main()
{
	// ������ �����̳� (Sequence Container)
	// �����Ͱ� ���� ������� �����Ǵ� ���� (���� ���� �ʰ�)
	// vector list deque

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���
	
	// vector�� cqpacity ������ ���� �� ũ�� ���� �̻�
	// deque�� ���� ��ĭ ����µ� ���ļ� �̻�� ����
	// [       ]  [        ]  [       ]
	// �׷��� capacity ����

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// deque �� �̷� ����
	// [    3 3]
	// [1 1 1 2]
	// [2      ]
	// 1 1 1 �� 2 �ְ� 2 �� �������� ���� ��� �ϳ� ���� ���� 2 �ְ�
	// 3 ����Ʈ �ϴ� ���� ���� ���� 3 �ְ�
	// 3 ����Ʈ �ѹ� �� �ϴ� ù ����Ʈ�� ������� ������ �ְ�
	
	// - deque
	// - �߰� ����/���� (BAD / BAD) vectoró�� �� �Űܾ� ��
	// - ó��/�� ����/���� (GOOD / GOOD)
	// - ���� ���� (GOOD)
	
	// ���� ���� ���
	// _Size_type _Block = _Mycont->_Getblock(_Myoff);
	// _Size_type _Off = _Myoff % _Block_size;
	// return _Mycont->_Map[_Block][_Off];
	
	return 0;
}