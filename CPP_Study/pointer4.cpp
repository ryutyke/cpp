#include <iostream>
using namespace std;

int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int count = 0;

	while (str[count] != '\0')
		count++;
	return count;

}

char* StrCpy(char* dest, char* src)
{
	int count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';

	return dest;
}

char* StrCat(char* dest, char* src)
{
	while (*dest != '\0')
		dest++;
	StrCpy(dest, src);

	return dest;
}

int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}

	return 0;
}

void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	cout << sizeof(a) << endl; // sizeof는 메모리 사이즈 크기
	int len = StrLen(a);
	cout << len << endl;

	char b[BUF_SIZE];

	StrCpy(b, a); // 복사
	cout << b << endl;

	StrCat(a, b); // a에 b 덧붙이기
	cout << a << endl;

	int value = StrCmp(a, b); // 비교 같으면 0, 사전 순서로 a가 더 빠르면 -1, b가 더 빠르면 1
	cout << value << endl;

	ReverseStr(b);
	cout << b << endl;

	return 0;
}