#include <iostream>
using namespace std;
#include <list>

// vector : 동적 배열

class Node
{
public:
	Node*	_next;
	Node*	_prev; // 이중
	int		_data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트
// [1] -> [2] -> [3] -> [4] -> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5]
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [ _Myhead : end() ] <-> [1]

// stl list는 이중리스트로 되어있음

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제 (GOOD / GOOD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (i번째 데이터) (BAD)

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i);

	int size = li.size();
	//li.capacity() 없음

	int first = li.front();
	int last = li.back();

	//li[3] = 10; 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	//list<int>::iterator itTest = itBegin + 10; 안됨 비효율적이라 ++ -- 만 됨
	//list<int>::iterator itTest1 = --itBegin; 안됨
	//list<int>::iterator itTest2 = --itEnd;   됨
	//list<int>::iterator itTest3 = ++itEnd;   안됨

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

	// * 임의 접근은 비효율적, 즉 느려서 안되는데 중간 삽입/삭제는 빠르다?
	// 50번 인덱스에 있는 데이터를 삭제해보자

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;
	
	li.erase(it);
	
	// erase() 지우는 함수가 빠르다는거지
	// 즉, [49] <-> [50] <-> [51] 에서 [49] <-> [51]이 빠른거지
	// 그 50번째 node를 찾는거는 비효율적
	// vector는 50번째 인덱스 뒤에 있는 모든 것을 한칸씩 앞으로 땡겨야하니깐 erase가 비효율적

	return 0;
}