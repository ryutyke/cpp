#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	// �ڷᱸ�� (�����͸� �����ϴ� ����)
	// �˰��� (�����͸� ��� ����� ���ΰ�?)

	// ������

	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number��� ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;
		bool found = false;
		vector<int>::iterator itBegin = v.begin();
		vector<int>::iterator itEnd = v.end();

		for (auto it = itBegin; it != itEnd; it++)
		{
			if ((*it) == number)
				found = true;
		}
		cout << found << endl;


		auto itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}
	}


	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ���
	{
		bool found = false;
		vector<int>::iterator itBegin = v.begin();
		vector<int>::iterator itEnd = v.end();

		for (auto it = itBegin; it != itEnd; it++)
		{
			if ((*it) % 11 == 0)
				found = true;
		}
		cout << found << endl;


		auto itFind = find_if(v.begin(), v.end(), [](int n) {return (n % 11) == 0; });
		if (itFind == v.end())
		{
			cout << "��ã����" << endl;
		}
		else
		{
			cout << "ã����" << endl;
		}
	}

	// Q3) Ȧ���� ������ ������?
	{
		int count = 0;
		vector<int>::iterator itBegin = v.begin();
		vector<int>::iterator itEnd = v.end();

		for (auto it = itBegin; it != itEnd; it++)
		{
			if ((*it) % 2 == 1)
				count++;
		}
		cout << count << endl;


		int cnt = std::count_if(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		cout << cnt << endl;

		// ��� �����Ͱ� Ȧ���ΰ�?
		bool b1 = std::all_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		// Ȧ���� �����Ͱ� �ϳ��� �ִ°�?
		bool b2 = std::any_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		// ��� �����Ͱ� Ȧ���� �ƴѰ�?
		bool b3 = std::none_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڿ� 3�� ���ϱ�
	{
		vector<int>::iterator itBegin = v.begin();
		vector<int>::iterator itEnd = v.end();

		for (auto it = itBegin; it != itEnd; it++)
		{
			(*it) *= 3;
		}
		for (auto it = itBegin; it != itEnd; it++)
		{
			cout << (*it) << endl;
		}

		cout << "--------------------------------------" << endl;
		cout << "--------------------------------------" << endl;

		std::for_each(v.begin(), v.end(), [](int& n) {n *= 3; });
		std::for_each(v.begin(), v.end(), [](int n) { cout << n << endl; });
	}

	// Ȧ���� �����͸� �ϰ� ����
	{
		for (vector<int>::iterator it = v.begin(); it != v.end();)
		{
			if ((*it % 2) != 0)
				it = v.erase(it);
			else
				++it;
		}

		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		vector<int>::iterator it = std::remove_if(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		/*
		������ ���ƾ� �ϴ� �ֵ� ������ �������� �������ϴ¾ֵ� ù ��ġ(iter) ��ȯ��
		1 4 3 5 8 2 ����
		4 8 2 5 8 2 ��
		��ȯ������ 5 ��ġ �ٰ���
		�׷��� ���� 5���� ������ ������� �ϴ� ����
		*/
		v.erase(it, v.end()); // v.erase(std::remove_if(v.begin(), v.end(), [](int n), v.end())
	}

	return 0;
}