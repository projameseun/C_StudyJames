#include <iostream>


int main()
{
	/*
		while �ַ� ���� ������ ������ ���� ����Ѵ�.
		������ ���鶧 �������� �������� ���� ����Ѵ�.
		while(���ǽ�) // ���ǽ��� �����϶� ������ �ȴ� , break�� ������ ������ �ȴ�.
		{

		}


		do while : ó�� �ѹ��� ������ �����̵ǰ� ���Ŀ� ���ǽ��� üũ�Ͽ� false�� ����������.
		do
		{
			�ڵ�
		}whille(���ǽ�);

	*/

	int iNumber = 0;

	//while (true)
	//{
	//	if (iNumber == 5)
	//		break;	//�ݺ����� ������ �ȴ�.
	//	
	//	std::cout << "iNumber = " << iNumber << std::endl;

	//	iNumber++;

	//	

	//}

	iNumber = -1;

	/*do
	{
		std::cout << iNumber << std::endl;
		iNumber++;

	} while (iNumber == 0);*/



	/*
	*
	**
	***
	****
	*****

	*/

	system("cls");

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
	*****
	****
	***
	**
	*
	*/
	for (int i = 4; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
		*
	   **
	  ***
	 ****
	*****
	*/

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 4; j > i; --j)
		{
			std::cout << " ";
		}
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
	*****
	 ****
	  ***
	   **
		*
	*/

	for (int i = 4; i >= 0; --i)
	{
		for (int j = 4; j > i; --j)
		{
			std::cout << " ";
		}

		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;


	/*
	   *
	  ***
	 *****
	*******
	*/

	//���� 3 2 1 0 
	//���� 2�����߰�
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j > i; --j)
		{
			std::cout << " ";
		}

		for (int j = 0; j < i * 2 + 1; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
		   *
		  ***
		 *****
		*******
		 *****
		  ***
		   *

	*/

	//i �� 0 �϶��� 6�϶� ���ƾ��Ѵ� 
	//i �� 1 �϶��� 5�϶� ���ƾ��Ѵ� 
	//i �� 2 �϶��� 4�϶� ���ƾ��Ѵ� 

	int iStar = 0;



	for (int i = 0; i < 7; ++i)
	{
		if (i > 3)
		{
			iStar = 6 - i;
		}
		else
		{
			iStar = i;
		}

		for (int j = 3; j > iStar; --j)
		{
			std::cout << " ";
		}

		for (int j = 0; j < iStar * 2 + 1; ++j)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	return 0;
}

/*
���� 1.
���� for���� Ȱ���ؼ� �Ʒ� ������ ����Ѵ�.
1-1.
*
**
***
****
*****

1-2.
*****
****
***
**
*

1-3.
	*
   **
  ***
 ****
*****

1-4.
*****
 ****
  ***
   **
	*

1-5.
   *
  ***
 *****
*******

1-6.
   *
  ***
 *****
*******
 *****
  ***
   *
*/