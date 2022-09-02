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

	// iterator �� pointer ���� : iterator�� �ּҰ� �Ӹ� �ƴ϶� �ڱⰡ ��� �ҼӵǾ� �ִ��� ���� ���� ������� _Myproxy, _Mynextiter
	*/

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end(); // �� �޸� ���� �޸�

	// vector ���� iterator���� [i] index ������ �ż� pointer�� �� ���Ҽ���
	// iterator�� vector �Ӹ� �ƴ϶� �ٸ� �����̳ʵ鿡�� ���������� �����Ƿ�
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // �̼��ϰ� ++it �� it++���� ���� ���������ڴ� temp �޸� ���
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