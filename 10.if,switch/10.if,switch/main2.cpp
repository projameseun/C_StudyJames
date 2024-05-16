#include <iostream>
#include <Windows.h>

/*
switch(변수)
{
case 값(상수):
코드
break;	break를 만나면 switch문을 나간다.
case 값(상수):
코드
break;	break를 만나면 switch문을 나간다.
...
...
...

default:	위에 case체크를 다 넘어오게 되면 들어온다. else랑 같은역할
break;


}

if랑 swtich둘은 매우 비슷하다.
어떤걸 사용해도 무방하다.
굳이 둘의 차이점을 얘기하면 속도의 차이가 있는데 큰 차이는 없다.
조건 검사가 2~3일때는 if가 빠르다 , 조건검사가 많을경우엥는 switch가 좀더 빠르다
그런데 이 빠른시간의 차이는 0.4초 정도 밖에 안된다... 성능에 문제가 생기지 않는다.


*/

namespace TYPEA
{
	enum ECar
	{
		BENZ = 1,
		AUDI,
		HYUNDAE,
		SAMSUNG = 100,
		BMW,
		PORSCHE,
	};
}

namespace TYPEB
{
	enum KCar
	{
		KIA,
		HYUNDAE,
		SAMSUNG = 100,

	};
}

//enum class (c++11)
//enumclass가 나온이유 :enum은 별도의 이름공간(namespace)가 존재하지 않는다. 
//enum을 여러개 사용하다보면 이름ㄹ이 중복되는 분명히 나오게 된다.
//enum을 정확하게 구분하기 위해서 enum class가 도입된것을 추측이된다.

enum class JOB
{
	GUNSLINGER = 1,
	BARD,
	BATTLEMASTER,
	BERSERKER,
};

enum class JOB2
{
	GUNSLINGER = 1,
	BARD,
	BATTLEMASTER,
	BERSERKER,
};



int main()
{
	int iNumber = 3;

	//switch (iNumber)
	//{
	//case BENZ:		//case의 값은 무조건 상수만 들어온다. 변수는 들어올수 없다.
	//	std::cout << "1번방 입니다" << std::endl;
	//	break;		
	//case AUDI:
	//	std::cout << "2번방 입니다" << std::endl;
//	break;
//case HYUNDAE:
//	std::cout << "3번방 입니다" << std::endl;
//case BMW:
//	std::cout << "4번방 입니다" << std::endl;
//	break;
//default:
//	std::cout << "그외방 입니다" << std::endl;
//	break;
//}


/*
enum(열거형)
숫자에 이름을 부여하는 기능이다.
연속으로 나열된 숫자에 이름을 붙여줄때 사용할수 있다.
enum 열거명
{

};
enum의 장점
숫자를 문자로 표현할수 있다. 사이트들어갈때 아이피를 사용하지 않고 dns를 사용해서 들어가는 거와 비슷하다.

enum의 문제점
별도의 이름공간(namespace)를 가지고 있지 않다는것
enum를 사용하다 보면 중복되는게 나오게 된다. 물론 사용자가 접두,접미에 타입을 붙여서 이름을 구분할수 있지만 그것은 사용자가 임의 변수이름을 잘 구분해서 저장한것이다.
*/

	int iCar = 0;

	iCar = TYPEA::AUDI;

	iCar = TYPEB::HYUNDAE;

	switch (iCar)
	{
	case TYPEA::BENZ:		//case의 값은 무조건 상수만 들어온다. 변수는 들어올수 없다.
		std::cout << "벤츠를 선택했습니다" << std::endl;
		break;
	case TYPEA::AUDI:
		std::cout << "아우디를 선택했습니다" << std::endl;
		break;
	case TYPEA::HYUNDAE:
		std::cout << "현대를 선택했습니다" << std::endl;
	case TYPEA::BMW:
		std::cout << "BMW를 선택했습니다" << std::endl;
		break;
	default:
		std::cout << "그외방 입니다" << std::endl;
		break;
	}

	system("cls");

	//로스트아크 직업고르기
	int iJob = 0;
	int iAttack = 0, iDeffence = 0, iHP = 0, iMP = 0;

	std::cout << "<=======직업을 선택해주세요 ======>" << std::endl;
	std::cout << "1.건슬링어" << std::endl;
	std::cout << "2.바드" << std::endl;
	std::cout << "3.배틀마스터" << std::endl;
	std::cout << "4.버서커" << std::endl;
	std::cin >> iJob;


	//CTRL + ENTER

	switch ((JOB)iJob)
	{
	case JOB::GUNSLINGER:
		iAttack = 70;
		iDeffence = 50;
		iHP = 500;
		iMP = 100;
		break;
	case JOB::BARD:
		iAttack = 30;
		iDeffence = 10;
		iHP = 700;
		iMP = 500;
		break;
	case JOB::BATTLEMASTER:
		iAttack = 100;
		iDeffence = 20;
		iHP = 1000;
		iMP = 10;
		break;
	case JOB::BERSERKER:
		iAttack = 1000;
		iDeffence = 500;
		iHP = 2000;
		iMP = 1;
		break;
	default:

		break;
	}

	if (iJob == (int)JOB::GUNSLINGER)
	{
		std::cout << "건슬링어 모험가님 방갑습니다" << std::endl;
		std::cout << "공격력 : " << iAttack << std::endl;
		std::cout << "방어력 : " << iDeffence << std::endl;
		std::cout << "체력 : " << iHP << std::endl;
		std::cout << "마력 : " << iMP << std::endl;
	}
	else if (iJob == (int)JOB::BARD)
	{
		std::cout << "바드 모험가님 방갑습니다" << std::endl;
		std::cout << "공격력 : " << iAttack << std::endl;
		std::cout << "방어력 : " << iDeffence << std::endl;
		std::cout << "체력 : " << iHP << std::endl;
		std::cout << "마력 : " << iMP << std::endl;
	}
	else if (iJob == (int)JOB::BATTLEMASTER)
	{
		std::cout << "배틀마스터 모험가님 방갑습니다" << std::endl;
		std::cout << "공격력 : " << iAttack << std::endl;
		std::cout << "방어력 : " << iDeffence << std::endl;
		std::cout << "체력 : " << iHP << std::endl;
		std::cout << "마력 : " << iMP << std::endl;
	}
	else if (iJob == (int)JOB::BERSERKER)
	{
		std::cout << "버서커 모험가님 방갑습니다" << std::endl;
		std::cout << "공격력 : " << iAttack << std::endl;
		std::cout << "방어력 : " << iDeffence << std::endl;
		std::cout << "체력 : " << iHP << std::endl;
		std::cout << "마력 : " << iMP << std::endl;
	}
	else
	{
		std::cout << "모험가님 직업을 선택해주세요 ㅜㅜ" << std::endl;
	}



	return 0;
}