#include <iostream>
#include <bitset>

enum class GunslingerSkill
{
	DualBuckshot = 0x1,		//1
	FocusedShot = 0x2,		//2
	LastRequest = 0x4,		//4
	Peacekeeper = 0x8,		//8

	PerfectZone = 0x10,		//16
	Sharpshooter = 0x20,	//32
	//Sharpshooter = 0x40,	//64
	// ......   = 0x80  // 128
};

const unsigned int IDLE = 1;
const unsigned int RUNNING = 2;
const unsigned int JUMPING = 4;
const unsigned int ATTACKING = 8;



int main()
{
	/*
		비트단위 논리 연산자 : AND(&),OR(|),NOT(~),XOR(^)
		값 대 값을 연산하여 결과로 값이 나오게 한다.

		110 & 52 = 
		&0110 1110
		 0011 0100
		-----------
		 0010 0100
		 36이 된다.

		 110 | 52 =
		|0110 1110
		 0011 0100
		-------------
		0111 1110
		126이 된다.

		A		B		XOR
		false	false	false
		false	true	true	
		true	false	true	
		true	true	false

		XOR는 두개가 같으면 false 다르면 true가 나온다.

		  110 ^ 52 =
	    ^0110	1100
		 0011	0100
		 -----------
		 0101	1010

		 10 + 16 + 64 = 90 이 된다.
		 
		 NOT~ 연산자는 1은 0, 0은 1로 변경된다 (1의보수)
		 ~110
		 0110	1110
		 -----------
		 1001	0001

		 
		
	*/

	std::cout << "110 & 52 = " << (110 & 52) << std::endl;
	std::cout << "110 | 52 = " << (110 | 52) << std::endl;
	std::cout << "110 ^ 52 = " << (110 ^ 52) << std::endl;
	
	//쉬프트 연산자  : << , >> 2가지가 있다.
	//값 대 값을 연산하여 결과로 값이 나오게 된다.

	unsigned int a = 3;

	a = a << 5; //2의n승 * 배수 // 2의5승은 32 * 3 = 96이 나온다. 빠른 곱하기 라고도 부른다
	
	a = 0;
	unsigned char b = 8; //2의 n승 나누기 // 2의3승 8 / 8 = 1 , 빠른 나누기 라고도 부른다.

	b >>= 3;
	b = 0;

	/*
		왼쪽으로 2비트만큼 이동하라는 것은 앞에 최상위 비트가 2개사라지고 뒤에는 0이라는 숫자가 온다.
		30 << 2 = 
		0001 1110 위 연산뒤에 0을 2개붙이라는거다.
		 111 1000 

		 120이된다 .

		 30 << 3=
		 0001 1110
		 1111 0000
		 240이 된다. 

		 30 << 2 ==> 2의2승 * 30 // 120
		 30 << 3 ==> 2의3승 * 30 //240

		 오른쪽으로 2비트만큼 이동하라는건 오른쪽으로 갈때마다 사라진다 
		 30 >>2 
		1111 0 
		111
		7이된다.

		30 >> 3
		11110
		11 
		3 

		30 >> 2 ===> 2의2승 /30 은 7이된다
		30 >> 3 ====>2의3승 / 30 은 3이된다.
		 
		 */
	

		//비트연산자, 쉬프트 연산자를 이용해서 게임에서 사용하는법

	int iSkill = 0;

	//iSKil			==> 00000000 00000000 00000000 00000000
	//DualBuckshot	==> 00000000 00000000 00000000 00000001
	//요위에 상황에서 OR | 연산자를 이용하면 
	//kSill			==>	00000000 00000000 00000000 00000001
	//비트 1, 2 , 4 , 8 , 16 ....2의 배수로 늘어난다. 이걸이용해서 비트 연산자를 이용하면 어떤 상태값을 넣었다가 뺏다가 할수 잇는거다.
	iSkill = iSkill | (int)GunslingerSkill::DualBuckshot;		//값을 넣어줄때
	//iSkill |= (int)GunslingerSkill::DualBuckshot;				//줄여서 똑같은말 

	//iSKil		   ==> 00000000 00000000 00000000 00000001
	//FocusedShot  ==> 00000000 00000000 00000000 00000010
	//요위에 상황에서 또 OR |연사자를 이용하면
	//iSKil		   ==> 00000000 00000000 00000000 00000011
	//SKill두곳에 1이라는 숫자를 넣어줄수잇다 

	iSkill |= (int)GunslingerSkill::FocusedShot;

	std::cout << "iSkill = " << std::bitset<8>(iSkill) << std::endl;

	//iSkill ^= (int)GunslingerSkill::FocusedShot;		//없으면 넣고, 있으면 뺀다
	//iSkill ^= (int)GunslingerSkill::FocusedShot;


	//특정  자리 비트 제거
	//Skill &= ~(int)GunslingerSkill::DualBuckshot;		//뺀다
	iSkill = iSkill & ~(int)GunslingerSkill::DualBuckshot;

	if (iSkill & (int)GunslingerSkill::DualBuckshot)
	{
		std::cout << "듀얼벅샷 발동" << std::endl;
	}
	if (iSkill & (int)GunslingerSkill::FocusedShot)
	{
		std::cout << "포커스샷 발동" << std::endl;
	}


	unsigned int iPlayer = 0;

	//캐릭터가 달린다
	iPlayer |= RUNNING;
	//캐릭터가ㅑ 공격한다
	iPlayer |= ATTACKING;

	//플레이어 상태확인
	if (iPlayer & ATTACKING)
	{
		std::cout << "플레이어 공격중" << std::endl;
	}

	//캐릭터 달리 해제
	iPlayer &= ~RUNNING;

	if (iPlayer & RUNNING)
	{
		std::cout << "달리기 중" << std::endl;
	}
	else if (!(iPlayer & RUNNING))
	{
		std::cout << "멈춰있습니다" << std::endl;
	}


	//점프 했을때
	iPlayer |= JUMPING;

	iPlayer &= ~JUMPING;
	
	if (iPlayer & JUMPING)
	{
		std::cout << "점프 가능 " << std::endl;
	}
	else if (!(iPlayer & JUMPING))
	{
		std::cout << "점프 불가능" << std::endl;
	}
	
	

	return 0;
}