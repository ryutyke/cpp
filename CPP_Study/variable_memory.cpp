#include <iostream>
using namespace std;

// 전역 변수

// [데이터 영역]
// .data (초기값 있는 경우)
int a = 2;
// .bss (초기값 없는 경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

// const int는 .rodata에 저장되는가?
// C++ 표준에서 명시하지 않음
// 컴파일러 (visual studio) 에서 정함

int main()
{
	// 함수 속 변수
	// [스택 영역]
	int c = 3;
	// { } 중괄호의 범위가 생존 범위
}