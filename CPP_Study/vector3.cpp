#include <iostream>
using namespace std;
#include <vector>

// *중요한 부분*
// 벡터는 - 중간 삽입/삭제 비효율적
//		  - 처음 삽입 삭제 비효율적
//		  - 끝 삽입 삭제 굿
//		  - 임의 접근 가능

int main()
{
	vector<int> v(10, 4);
	v.reserve(100);

	v.push_back(1);
	v.pop_back();

	vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); // 범위삭제	

	// 쭉 스캔하면서 4라는 데이터를 일괄 삭제
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 4)
		{
			it = v.erase(it);  // iterator는 erase하는 순간에 소속을 잃음 다시 지정해줘야함
		}
		else
		{
			++it;
		}
	}

	return 0;
}