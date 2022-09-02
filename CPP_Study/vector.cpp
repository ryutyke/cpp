#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// STL (Standard Template Library)
	// 필요한 자료구조/알고리즘을 템플릿으로 제공하는 라이브러리
	
	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조)

	// vector (동적 배열)
	// 어떻게 유동적 사이즈?
	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// 기존에 있던 영역 int arr[100] 을 버리고 int arr[1000]을 새로 만듬
	// 1) 여유분은 얼만큼이 적당할까?
	// 2) 증설을 얼만큼 해야 할까?  => 컴파일러마다 다른데 1칸씩이 아니라 1.5배 등 여유있게 증설함. 이유는 꽉 찼을때 더 큰 새로운 놈을 만들고 복사해서 이사하는데, 이사 비용이 크기 때문
	// 3) 기존의 데이터를 어떻게 처리할까?  =?

	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7.....
	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 42 63...   -> 1.5배 컴파일러가 정하는 방식
	
	vector<int> v;
	// vector<int> v(1000, 0);  처음부터 1000으로 resize 및 0으로 초기화
	// vector<int> v2 = v;    똑같이 복사
	v.reserve(1000); // 처음부터 이사 안하기 위해서 capacity를 크게 잡고 싶으면 reserve()
	v.resize(1000);// size를 처음부터 크게 할당 -> resize()

	for (int i = 0; i < 1000; i++)
	{
		//v.push_back(100);
		v[i] = 100;
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear(); // size 0으로 포맷
	cout << v.size() << " " << v.capacity() << endl; // capacity는 자동으로 안줄어들음
	vector<int>().swap(v); // 임시벡터로 v capacity 0으로 메모리 정리 가능
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}