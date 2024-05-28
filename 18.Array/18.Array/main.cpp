#include <iostream>
#include <time.h>
#include <algorithm>


bool iCompare(int a, int b)
{
	return a < b; //오름차순
	//return a > b; 내림차순
}

int main()
{
	/*
		배열:같은 자료형의 변수 여러개를 한번에 선얼할수 있는 해주는 기능이다.
		배열의 특징 메모리가 연속적으로 잡혀있다.

		변수타입 배열면[갯수] 갯수는 상수만 가능하다.
		의 형태로 구성된다. 

		배열을 쓰는이유
		연속적 메모리를 만들때 똑같은 데이터를 그룹으로 묶어서 표현할때 배열 문법을 사용한다.
		
		
	*/
	
	//학생프로그램을만든다
	int iStudent[100];
	//위처럼 만들게 되면 학생 100명을 저장할수 있는 메모리가 생성된것이다.
	//400byte까지 생기게 되는것이다.
	//각 요소에 접근하기 위해서 사용하는 것이 인덱스이다.
	//인덱스는 0 ~~ 개수 -1 까지이다.

	//배열 초기화
	int iNum[10] = {}; // 모두 0 으로 초기화 한다
	//int iNum[10] = { 0, };
	//int iNum[10] = { 0,0,0,0,0,0,0,0,0,0 };

	int iNum2[] = { 1,299,300,500,20,10 };	//6개를 초기화 한다.

	int iArray[10] = { 1,2,3 };
	//위처럼 초기화를 하게 되면 0, 1, 2 번 인덱스에 1,2,3값이 들어가게 되고 나머지는 0 으로 초기화 된다.

	iArray[0] = 20;
	iArray[5] = 100;

	//배열 원소 갯수 = sizeof(배열명) / sizeof(자료형);
	size_t iSize = 0; //typedef unsigned int 

	std::cout << "iArray : " << sizeof(iArray) << std::endl; //4byte * 10 = 40

	iSize = sizeof(iArray) / sizeof(int); //배열의 갯수를 구한간다
	
	std::cout << "Size = " << iSize << std::endl;

	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << "iAraay[";
		std::cout << i << "]" << iArray[i] << std::endl;
	}
	
	float fArray[100] = { 0.f };

	std::cout << "fArray : " << sizeof(fArray) << std::endl;

	//문자열 배열 
	char data[6] = { 'H','A','P','P','Y'};		//문자열의 끝은 NULL ,0으로 표기한다 이래아 컴파일러가 이배열에 저장된 정보를 문자열이라는것을 알수 있다.
	char data2[6] = "Happy";

	char data3[25] = "안녕하세요"; //한글은 2바이트 영어는 1바이트 

	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	
	system("cls");

	//로또 프로그램
	//1~45사이의 숫자중 랜던함 6개의 숫자를 가져온다
	//값이 중복되면 안된다.
	//오름차순, 내림차순

	int iLotto[45] = {};

	iSize = sizeof(iLotto) / sizeof(int);

	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));

	//Shffule
	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 5000; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}
	
	iTemp = 0;
	//직접 내림 오름차순 구현
	//내림 큰숫자부터 쭉내려가는거고 , 오름은 작은숫자부터 올라간다

	//STL(Standdard 라이브러리)
	
	//오른차순 내림차순으로 정렬해주는거다
	// sort(array.begin(), array.end(), compare);c
	//std::sort(iLotto, iLotto+ 6); //2번째는 마지막주소를 가리키는거다 우린여섯개만 뽑을거니가 6을넣음거임 
	std::sort(iLotto, iLotto +6, iCompare); //compare에 값을 넣지않은경우 일반적으로 오름차순을한다

	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			if (iLotto[i] > iLotto[j])
			{
				iTemp = iLotto[i];
				iLotto[i] = iLotto[j];
				iLotto[j] = iTemp;
			}
		
		}
	}*/

	for (int i = 0; i < 6; ++i)
	{
		std::cout << iLotto[i] << std::endl;
	}

	return 0;
}