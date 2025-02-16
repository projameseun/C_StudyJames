#include <iostream>

void OutPut()
{
	std::cout << "OutPut" << std::endl;
}

void OutPut2()
{
	std::cout << "OutPut2" << std::endl;
}	

int Sum(int a, int b)
{
	return a + b;
}

void SetFunctionPointer(void (*pFunc)())
{
	pFunc();
}


int main()
{
	/*
		�Լ������� (Function Pointer)
		�Լ��� �ٸ� ������ ó�� �ּҸ� ������ �ִµ� 
		�� �Լ��� �ּҸ� ������ ������ �����ؼ� ����ϴ� �� 
		�Լ� �����Ͷ�� �Ѵ�.
		��ȯŸ�� (*������)(����Ÿ�Ե�);�� ���·� �����ȴ� .1
	*/

	int a = 100;
	int* ptr = &a;	//������

	//�Լ� ������
	void (*pFuncOutput)() = OutPut;
	int(*pFuncSum)(int, int) = Sum;	

	pFuncOutput();	
	std::cout << pFuncSum(10, 20) << std::endl;


	//pFuncOutput = Sum; �ٸ� �������Լ��� �Ұ���
	
	pFuncOutput = OutPut2;

	pFuncOutput();

	std::cout << "Sum Address : " << &pFuncSum << std::endl;
	std::cout << "pFuncOutput Address : " << &pFuncOutput << std::endl;


	std::cout << "Sum Value : " << pFuncSum << std::endl;
	std::cout << "pFuncOutput Value : " << pFuncOutput << std::endl;



	SetFunctionPointer(OutPut);


	return 0;
}