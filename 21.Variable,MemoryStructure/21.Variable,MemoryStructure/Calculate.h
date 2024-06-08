#pragma once

//도구 -> 옵션 - > 환경 ->키보드에 들어가면 내가 원하느 단축키만들수 있다

//Alt + Enter 단축키 누르면 정의만들기 바로 가능

static int g_StaticNum = 0;

int Add(int a, int b);
int Minus(int a, int b);
int Multi(int a, int b);
int Module(int a, int b);
int Divide(int a, int b);

void CalFun();
void StaticAdress();
void ExAddress();
void ExFunc();

//LINK ->링크단계에서 오류가 발생했다
//c -> 컴파일에서 오류가 발생했다

//외부변수
//외부변수는 선언을하고 어느 파일이든 무조건 정의가 되어 있어야 되고 어느파일 이든 정의를 할수 있다. 또한 주소를 한가지로 공유한다
extern int g_exNum;