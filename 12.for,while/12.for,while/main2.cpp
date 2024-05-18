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