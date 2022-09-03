#include <iostream>
using namespace std;
#include <deque>
#include <vector>
// deque : double-ended queue 데크

int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태 (정렬 되지 않고)
	// vector list deque

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다
	
	// vector는 cqpacity 꽉차면 새로 더 크게 만들어서 이사
	// deque는 새로 한칸 만드는데 합쳐서 이사는 안함
	// [       ]  [        ]  [       ]
	// 그래서 capacity 없음

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// deque 는 이런 상태
	// [    3 3]
	// [1 1 1 2]
	// [2      ]
	// 1 1 1 에 2 넣고 2 또 넣으려니 공간 없어서 하나 새로 만들어서 2 넣고
	// 3 프론트 하니 공간 새로 만들어서 3 넣고
	// 3 프론트 한번 더 하니 첫 프론트때 만들어진 공간에 넣고
	
	// - deque
	// - 중간 삽입/삭제 (BAD / BAD) vector처럼 다 옮겨야 함
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (GOOD)
	
	// 임의 접근 방식
	// _Size_type _Block = _Mycont->_Getblock(_Myoff);
	// _Size_type _Off = _Myoff % _Block_size;
	// return _Mycont->_Map[_Block][_Off];
	
	return 0;
}