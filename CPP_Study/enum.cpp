#include <iostream>
using namespace std;

//const int ROCK = 1;
//const int SCISSORS = 2;
//const int PAPER = 3;


// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
enum ENUM_RSP
{
	ROCK = 1,
	SCISSORS,
	PAPER,
};

// const의 경우는 경우에 따라 memory에 저장될 수도 있다.
// enum은 무조건 memory에 저장되지 않는다.
// 따라서 enum이 memory 측면에서 좋다.

// #이 붙은거 -> 전처리 지시문
// 1) 전처리 2) 컴파일 3) 링크
// #include iostream 은 iostream 파일 내용을 전처리때 여기에 복붙

// define은 전처리 때 해당 내용들을 바꿔치기
#define DEFINE_ROCK 1
#define DEFINE_SCISSORS 2
#define DEFINE_PAPER 3
// 정수만 되는게 아니다
#define DEFINE_TEST cout << "Hello World" << endl;

#define DEFINE_THREE 1+2
// define은 지양 특히 상수로 쓸때는 더욱. 디버깅 시, 마우스 갖다댔을 때 무슨 정보 나타내는지 안보이는 등

int main()
{
	DEFINE_TEST;
	int result = DEFINE_THREE * 2; // 1+2 그대로 들어가서 5 나온다
}