#include <iostream>

int main()
{
	//const�� ����̴�.
	
	volatile const int iNum = 100;

	//const��� Ű���尡 �پ��ٰ� �츮�� ���ϴ� ��¥ ����� �ƴϴ�
	//�߿��Ѱ� ���������� �����ְ� �ִ� ���̴�.
	
	//100 = 300;
	//iNum = 500;

	int a = 100;
	int b = a + 100; 

	//a + 100 = 300;

	int* ptr = nullptr;

	ptr = (int*)&iNum;

	*ptr = 50;

	std::cout << "iNum = " << iNum << std::endl;

	//���� ���� ���� ����ȯ�� �Ͽ��� �ְ� �Ǹ� 50�� ���ðŶ�� �����ϴµ� 100�� ���´�.
	//������ �����Ϸ� ���忡���� const iNum�� ������ ���Ŵ�.
	//�𽺾������� ���� 50�� ���� Ȯ�̱����� �����ϴ�.
	//�ٵ� cpu�� ������ �Ҷ� �������� �޸𸮰� �����ϴµ� �ӽð��� �����ϰ� �ִ�.
	//����� �����Ϸ� ���忡���� �ٲ��� �ʴ� ���̱� ������ �������� �޸𸮿��� �̰��ϰ� �ٷ� ���� �Ȱ��̴�.

	/*
		cpu�ȿ� �������ʹ� ��Ȯ�� ��⸦ �غ��� �޸𸮰� �ƴϴ�.
		�ӽ� �����͸� �����ϴ� �����ε� ���� �ֹ߼����� �����͸� �����ϴ� �����̴�.
		�� ���п� cpu�ȿ��� �����ϸ� ������ ���� ó���Ҽ��ִ�.

		cpu�� �ӽõ����͸� �����ϴ°��� �������Ͱ� �ִ�
		cpu�� �޷θ��� �����Ҷ� ������°� �����Ѵ�.
		�� ������ �޸𸮰� ũ�� Ŭ���� ���������� �����ϰ� �ǰ�
		�޸𸮴� Ư���� ��ϵ� ������� �����ϱ� ���ؼ� �ֱ������� ���θ� �ٽ� ��ߵȴ�.
		�׷��� �ٽ� ���� �۾��� �ð��� �� �Ҹ��ϰ� �ȴ�.
		�������ʹ� cpu�� �ſ� �����
		�� �ݵ����͵��� ����Ʋ ���ؼ� cpu�� ���� �ȴ�. �Ӹ������� �׷������� �� ������ ���� ���ۿ� ���°� �翬�ϴ�.
		
	*/


	return 0;
}