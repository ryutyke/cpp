#include <iostream>
using namespace std;
#include <vector>

// *�߿��� �κ�*
// ���ʹ� - �߰� ����/���� ��ȿ����
//		  - ó�� ���� ���� ��ȿ����
//		  - �� ���� ���� ��
//		  - ���� ���� ����

int main()
{
	vector<int> v(10, 4);
	v.reserve(100);

	v.push_back(1);
	v.pop_back();

	vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); // ��������	

	// �� ��ĵ�ϸ鼭 4��� �����͸� �ϰ� ����
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 4)
		{
			it = v.erase(it);  // iterator�� erase�ϴ� ������ �Ҽ��� ���� �ٽ� �����������
		}
		else
		{
			++it;
		}
	}

	return 0;
}