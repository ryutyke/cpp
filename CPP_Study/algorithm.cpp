#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)

	// 가독성

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

	// Q1) number라는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
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
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}


	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
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
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}

	// Q3) 홀수인 숫자의 개수는?
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

		// 모든 데이터가 홀수인가?
		bool b1 = std::all_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		// 홀수인 데이터가 하나라도 있는가?
		bool b2 = std::any_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
		// 모든 데이터가 홀수가 아닌가?
		bool b3 = std::none_of(v.begin(), v.end(), [](int n) {return (n % 2 != 0); });
	}

	// Q4) 벡터에 들어가 있는 모든 숫자에 3을 곱하기
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

	// 홀수인 데이터를 일괄 삭제
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
		지우지 말아야 하는 애들 앞으로 가져오고 지워야하는애들 첫 위치(iter) 반환함
		1 4 3 5 8 2 에서
		4 8 2 5 8 2 됨
		반환값으로 5 위치 줄거임
		그러면 내가 5부터 끝까지 날려줘야 하는 거임
		*/
		v.erase(it, v.end()); // v.erase(std::remove_if(v.begin(), v.end(), [](int n), v.end())
	}

	return 0;
}