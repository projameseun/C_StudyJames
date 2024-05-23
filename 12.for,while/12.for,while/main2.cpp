#include <iostream>


int main()
{
	/*
		while 주로 무한 루프를 돌리때 많이 사용한다.
		게임을 만들때 무한으로 돌릴때도 많이 사용한다.
		while(조건식) // 조건식이 거짓일때 나오게 된다 , break를 만나면 나가게 된다.
		{

		}


		do while : 처음 한번은 무조건 동작이되고 그후에 조건식을 체크하여 false면 빠져나간다.
		do
		{
			코드
		}whille(조건식);

	*/

	int iNumber = 0;

	//while (true)
	//{
	//	if (iNumber == 5)
	//		break;	//반복문을 나가게 된다.
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

	//공백 3 2 1 0 
	//별이 2개씩추가
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

	//i 가 0 일때와 6일때 같아야한다 
	//i 가 1 일때와 5일때 같아야한다 
	//i 가 2 일때와 4일때 같아야한다 

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
숙제 1.
이중 for문을 활용해서 아래 모양들을 출력한다.
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