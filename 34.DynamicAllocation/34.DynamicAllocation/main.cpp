#include <iostream>

struct Student
{
	std::string stName;
	int iScore;
};




int main()
{
	/*
		동적할당(Dymaic Allocation)은 메모리를 런타임에서 결정나고
		동적으로 할당,해제 하는것을 말합니다.또한 프로그램 실행 중에
		메모리를 할당하고 해제 할 수 있어서 더 유연한 메모리 관리를 가능하게 한다.
		사람들이 c++을 잘하면 인정해주는게 이부분에서 나온거라고 어느정도 볼수 있다 왜냐 메모리를 내가 직접 관리한다.
		
		c- malloc(), calloc() ,relloc() 과 같은 함수를 사용해서 할당하고
		free()로 해제한다.
		
		c++ new할당하고 
		delete해제 한다.

		동적할당은 주로 배열,구조체,객체(클래스)등의 데이터 구조를 다룰때 유용하게  사용됩니다.
		
		동적할당을 하고 메모리를 해제 하지 않게 되면 메모리 누스(memory leak)가 생기는데 이를 꼭 방지를 해줘야 된다.
		메모리를 할당하게 되면 무조건 메모리를 해제 해줘야 된다.
		만약에 메모리를 해제 해주지 않게 되면 누수가 발생하여 시스템의 메모리 사용량이 계속해서 증가하게 되고,
		결국 시스템 성능 저하를 시킬수 있게 된다.

		메모리릭을 체크하는 함수
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	*/
		
	//malloc() 
	/*
		표준라이브러리<stdlib.h> 헤더 파일에 정의 되어 있습니다.
		malloc 함수는 힙(heap) 영역에서 메모리 블록을 할당하고, 해당 메모리 블록의 포인터를 반환 합니다.
		
		단계
		1.요청된 메모리 크기에 대한 공간을 할당하기 위해서 운영체제에 요청을 보냅니다.
		2.운영체제는 사용 가능한 힙 영역에서 요청된 메모리 크기에 해당하는 블록을 찾아 할당합니다.
		3.할당된 메모리 블록의 주소를 반환하고, 해당 주소를 사용하여 동적으로 할당된 메모리에 접근 할수 있습니다.

		malloc함수에서 사용 가능한 힙영역에 충분한 메모리가 없는경우 malloc()함수는 nullptr를 반환합니다.
		이는 메모리 할당을 실패하는 경우를 말한다.

		
		
		
		


	*/

	//메모리릭을 체크하는 함수
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int* ptr = (int*)malloc(sizeof(int));
	////위코드에서 메모리 할당을 실패할수 있기 때문에
	////위와 같이 예외처리를 해주면 된다.

	//if (ptr == NULL)
	//{
	//	//메모리 할당실패
	//}
	//else
	//{
	//	//할당성공
	//}

	//int* ptr = new int;
	//
	//if (ptr = nullptr)
	//{
	//	
	//}
	//else
	//{

	//}

	

	int* ptr = (int*)malloc(sizeof(int));

	*ptr = 200;

	std::cout << "ptr = " << *(ptr) << std::endl;
	
	//강제 형변환을 사용하는방법
	*((int*)ptr) = 3.f;

	std::cout << "ptr = " << *(ptr) << std::endl;

	//메모리 해제
	if (nullptr != ptr)
	{
		free(ptr);
	}

	{
		int* ptr = new int;

		*ptr = 300;

		std::cout << "ptr = " << *(ptr) << std::endl;

		if (nullptr != ptr)
		{
			delete ptr;
		}
		

	}

	//동적할당에 간단 예시..
	int iNum = 0;

	std::cout << "학생수 입력해주세요 : ";
	std::cin >> iNum;

	//할당
	Student* st = new Student[iNum];

	if (iNum <= 0 || iNum <= 10)
	{
		//학생정보
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << (i + 1) << "학생 이름 입력 ";
			std::cin >> st[i].stName;
			std::cout << (i + 1) << "점수 입력 ";
			std::cin >> st[i].iScore;
		}


		float fAvg = 0.f;
		int iTotal = 0;
		for (int i = 0; i < iNum; ++i)
		{
			iTotal += st[i].iScore;
		}

		fAvg = iTotal / iNum;

		std::cout << "평균 점수 : " << fAvg << std::endl;

		std::cout << "학생 정보  " << std::endl;
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << "이름 : " << st[i].stName << "점수 : " << st[i].iScore << std::endl;
		}
	}


	
	delete[] st;

	


	return 0;
}