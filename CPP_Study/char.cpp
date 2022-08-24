#include <iostream>
using namespace std;

// char : ���ĺ� / ���� ���ڸ� ��Ÿ����
// wchar_t : �����ڵ� ���ڸ� ��Ÿ����

//ASCII (American Standard Code for Information Interchange)

// '����'�� �ǹ̷� ���� ����ǥ '' ���
char ch = 97; // a
char ch2 = 'a' + 1 ; // b

// ����ȭ �ô뿡�� ������� ���� �� �� ����
// �� ���� ��� ���ڿ� ���� ���� �ڵ带 �ο��� ���� �����ڵ� (unicode)
// ����) �����ڵ忡�� ���� ���� ��ȣ�� �����ϴ°� �ѱ���/�߱��� (�V�Z�y)

// �����ڵ� ǥ�� ����� ���������� �ִµ� ��ǥ������ UTF8 UTF16
// UTF8
// - ���ĺ�, ���� 1����Ʈ (ASKII�� ������ ��ȣ)
// - ���� ������ ���ڴ� 2����Ʈ
// - �ѱ�, ���� �� 3����Ʈ
// UTF16
// - ���ĺ�, ����, �ѱ�, ���� �� ���� ��κ� ���� 2����Ʈ
// - ��~~�� �������� ��� ���ڸ� 4����Ʈ
// ���� Ư¡�� ���� ������� ����

wchar_t wch = L'��'; // == wchar_t wch = 0xc548;

// Escape Sequence
// ǥ���ϱ� �ָ��� �ֵ��� ǥ��
// \0 = �ƽ�Ű�ڵ�0 = NULL
// \t = �ƽ�Ű�ڵ�9 = Tab
// \n = �ƽ�Ű�ڵ�10 = LineFeed (���� �Ʒ���)
// \r = �ƽ�Ű�ڵ�13 = CarriageReturn (Ŀ�� �� ������)

// ���ڿ�
// ���ڵ��� ���� ��� �� �ִ� ��
// ���� (1~8����Ʈ) ���� ���̷�
// ���ڿ��� ���̰� �������̶� ���� NULL (0)�� ���� ������ �˷������

int main()
{
	cout << ch << endl;
	cout << ch2 << endl;
	wchar_t str3[] = L"Hello World";

	cout << wch << endl; //50504 => cout�� char ����
	wcout.imbue(locale("kor")); // ����Ǿ��ִ� 0xc548�� � ���� ��ȯ���� �˷������
	wcout << wch << endl;

	char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	char str2[] = "Hello World";
;	cout << str << endl;
	cout << str2 << endl;
	wcout << str3 << endl;
}