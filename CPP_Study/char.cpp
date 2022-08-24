#include <iostream>
using namespace std;

// char : 알파벳 / 숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다

//ASCII (American Standard Code for Information Interchange)

// '문자'의 의미로 작은 따옴표 '' 사용
char ch = 97; // a
char ch2 = 'a' + 1 ; // b

// 국제화 시대에는 영어만으로 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드 (unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어 (똙쿩웱)

// 유니코드 표기 방식이 여러가지가 있는데 대표적으로 UTF8 UTF16
// UTF8
// - 알파벳, 숫자 1바이트 (ASKII랑 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매~~우 예외적인 고대 문자만 4바이트
// 따라서 특징에 따라 장단점이 존재

wchar_t wch = L'안'; // == wchar_t wch = 0xc548;

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키코드0 = NULL
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13 = CarriageReturn (커서 맨 앞으로)

// 문자열
// 문자들이 열을 지어서 모여 있는 것
// 정수 (1~8바이트) 고정 길이로
// 문자열은 길이가 유동적이라 끝에 NULL (0)을 통해 끝임을 알려줘야함

int main()
{
	cout << ch << endl;
	cout << ch2 << endl;
	wchar_t str3[] = L"Hello World";

	cout << wch << endl; //50504 => cout은 char 적용
	wcout.imbue(locale("kor")); // 저장되어있는 0xc548을 어떤 언어로 변환할지 알려줘야함
	wcout << wch << endl;

	char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	char str2[] = "Hello World";
;	cout << str << endl;
	cout << str2 << endl;
	wcout << str3 << endl;
}