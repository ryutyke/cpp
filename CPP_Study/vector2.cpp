#include <iostream>
using namespace std;
#include <vector>


int main()
{
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	/*
	vector<int>::iterator it;
	int* ptr;
	
	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl; 
	cout << (*ptr) << endl;

	// iterator 와 pointer 차이 : iterator는 주소값 뿐만 아니라 자기가 어디에 소속되어 있는지 정보 등이 담겨있음 _Myproxy, _Mynextiter
	*/

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end(); // 끝 메모리 다음 메모리

	// vector 한정 iterator보다 [i] index 접근이 돼서 pointer가 더 편할수도
	// iterator는 vector 뿐만 아니라 다른 컨테이너들에도 공통적으로 있으므로
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // 미세하게 ++it 가 it++보다 빠름 후위연산자는 temp 메모리 사용
	{
		cout << (*it) << endl;
	}

	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	//vector<int>::const_iterator cit = v.cbegin();
	//for(vector<int>::reverse_iterator it = v.rbegin() ; it != v.rend(); i++){}

	return 0;
}