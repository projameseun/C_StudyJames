#pragma once

//���� -> �ɼ� - > ȯ�� ->Ű���忡 ���� ���� ���ϴ� ����Ű����� �ִ�

//Alt + Enter ����Ű ������ ���Ǹ���� �ٷ� ����

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

//LINK ->��ũ�ܰ迡�� ������ �߻��ߴ�
//c -> �����Ͽ��� ������ �߻��ߴ�

//�ܺκ���
//�ܺκ����� �������ϰ� ��� �����̵� ������ ���ǰ� �Ǿ� �־�� �ǰ� ������� �̵� ���Ǹ� �Ҽ� �ִ�. ���� �ּҸ� �Ѱ����� �����Ѵ�
extern int g_exNum;