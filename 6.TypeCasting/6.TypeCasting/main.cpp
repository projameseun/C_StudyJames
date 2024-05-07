#include <iostream>

int main()
{
	/*
		����ȯ(TypeCasting)
		5������ ������ �ִ�.
		c-style cast
		
		Ÿ��ĳ��Ʈ ������ ==> static_cast,const_cast,dynamic_cast,reinterpreat_cast

		c-style cast�� ���ھտ� (�ڷ���)�� ����Ѵ� 
	
	*/

	int a = 0;
	float b = 1.f;

	b = (float)a + 3.f;  //c ��Ÿ��ĳ��Ʈ ����� ����ȯ

	int c = 0;

	c = 3.5f;			//c��Ÿ��ĳ��Ʈ �Ͻ��� ����ȯ


	//static_cast
	
	int iNumber = 0;
	char cNum = 0;
	float fNumber = 0.f;

	iNumber = 25;

	cNum = static_cast<char>(iNumber); //int to char
	fNumber = static_cast<float>(cNum); //char to float

	//const_cast
	//������� �����Ҷ� ����Ѵ� �����ͳ� ����(���۷���)�� ���ؼ� �����
	const int constValue = 20;
	const int* ptr = &constValue;

	//*ptr = 30; �̰Ǿȵ� 

	int* ptr2 = const_cast<int*>(ptr);
	
	*ptr2 = 50;  //������ �̷������� ����ؼ� ptr2�� �����ϸ鼭 constValue ���� �����Ҽ��ִ�
	//������ ����غ��� constValue�� ����� ������ �� �ȳ��� ������ ������ const�� ���ȭ���Ѽ� �����Ͽ��� �̹� �������ѳ��Ƽ�

	std::cout << constValue << std::endl;
	std::cout << ptr2 << std::endl;
	std::cout << ptr<< std::endl;

	//dynamic_cast 
	
	//��Ӱ��迡 �ִ� Ŭ���� ���� ĳ������ �����ϳ� ��Ÿ��(���α׷��� ����ǰ� �ִµ���) Ÿ�� �˻縦 ���� �ʱ⶧���� �����ϴ�
	//�̷��� dynamic_cast�� ����Ѵ� 
	//���̳��� ĳ��Ʈ�� ��Ӱ��谡 �ִ°�쿡 ���ȴ�.
	//��ȯ�� �����ϸ� nullptr�� ��ȯ�Ѵ� 
	//�̰� �˷��� ��� ,��ĳ���� �ٿ�ĳ������ �����ؾ� �˼����� ���߿� ����

	//reinterpreat_cast

	//���� �ٸ� ������ �Ǵ� ���۷����� ��ȯ�ϴµ� ����Ѵ� 
	//���߿� Ÿ��ĳ��Ʈ���� �ڼ��� ���� �ϰڽ��ϴ� ���ݹ��⿡�� ���� �̼���

	//�Ͻ�������ȯ - �ڵ����� ����ȯ�� �̷�� ����.
	//���������ȯ - ����ڰ� ���� �������� Ÿ���� �����ϴ°��̴�
	//
	//�Ͻ�������ȯ�� Data �� �ս��� �߻��Ҽ� �ֱ⶧���� ������ �� ���ִ�.
	//ũ�Ⱑ ū�뼭 �����ŷ� ������ �ϰԵǸ� �������� �ս��� �ü� �֤���.�׷��� Ȯ���Ҷ��� ����ϴ� ���� ����.

	int test = 0;

	return 0;
}