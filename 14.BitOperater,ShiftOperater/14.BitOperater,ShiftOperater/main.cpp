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
		��Ʈ���� �� ������ : AND(&),OR(|),NOT(~),XOR(^)
		�� �� ���� �����Ͽ� ����� ���� ������ �Ѵ�.

		110 & 52 = 
		&0110 1110
		 0011 0100
		-----------
		 0010 0100
		 36�� �ȴ�.

		 110 | 52 =
		|0110 1110
		 0011 0100
		-------------
		0111 1110
		126�� �ȴ�.

		A		B		XOR
		false	false	false
		false	true	true	
		true	false	true	
		true	true	false

		XOR�� �ΰ��� ������ false �ٸ��� true�� ���´�.

		  110 ^ 52 =
	    ^0110	1100
		 0011	0100
		 -----------
		 0101	1010

		 10 + 16 + 64 = 90 �� �ȴ�.
		 
		 NOT~ �����ڴ� 1�� 0, 0�� 1�� ����ȴ� (1�Ǻ���)
		 ~110
		 0110	1110
		 -----------
		 1001	0001

		 
		
	*/

	std::cout << "110 & 52 = " << (110 & 52) << std::endl;
	std::cout << "110 | 52 = " << (110 | 52) << std::endl;
	std::cout << "110 ^ 52 = " << (110 ^ 52) << std::endl;
	
	//����Ʈ ������  : << , >> 2������ �ִ�.
	//�� �� ���� �����Ͽ� ����� ���� ������ �ȴ�.

	unsigned int a = 3;

	a = a << 5; //2��n�� * ��� // 2��5���� 32 * 3 = 96�� ���´�. ���� ���ϱ� ��� �θ���
	
	a = 0;
	unsigned char b = 8; //2�� n�� ������ // 2��3�� 8 / 8 = 1 , ���� ������ ��� �θ���.

	b >>= 3;
	b = 0;

	/*
		�������� 2��Ʈ��ŭ �̵��϶�� ���� �տ� �ֻ��� ��Ʈ�� 2��������� �ڿ��� 0�̶�� ���ڰ� �´�.
		30 << 2 = 
		0001 1110 �� ����ڿ� 0�� 2�����̶�°Ŵ�.
		 111 1000 

		 120�̵ȴ� .

		 30 << 3=
		 0001 1110
		 1111 0000
		 240�� �ȴ�. 

		 30 << 2 ==> 2��2�� * 30 // 120
		 30 << 3 ==> 2��3�� * 30 //240

		 ���������� 2��Ʈ��ŭ �̵��϶�°� ���������� �������� ������� 
		 30 >>2 
		1111 0 
		111
		7�̵ȴ�.

		30 >> 3
		11110
		11 
		3 

		30 >> 2 ===> 2��2�� /30 �� 7�̵ȴ�
		30 >> 3 ====>2��3�� / 30 �� 3�̵ȴ�.
		 
		 */
	

		//��Ʈ������, ����Ʈ �����ڸ� �̿��ؼ� ���ӿ��� ����ϴ¹�

	int iSkill = 0;

	//iSKil			==> 00000000 00000000 00000000 00000000
	//DualBuckshot	==> 00000000 00000000 00000000 00000001
	//������ ��Ȳ���� OR | �����ڸ� �̿��ϸ� 
	//kSill			==>	00000000 00000000 00000000 00000001
	//��Ʈ 1, 2 , 4 , 8 , 16 ....2�� ����� �þ��. �̰��̿��ؼ� ��Ʈ �����ڸ� �̿��ϸ� � ���°��� �־��ٰ� ���ٰ� �Ҽ� �մ°Ŵ�.
	iSkill = iSkill | (int)GunslingerSkill::DualBuckshot;		//���� �־��ٶ�
	//iSkill |= (int)GunslingerSkill::DualBuckshot;				//�ٿ��� �Ȱ����� 

	//iSKil		   ==> 00000000 00000000 00000000 00000001
	//FocusedShot  ==> 00000000 00000000 00000000 00000010
	//������ ��Ȳ���� �� OR |�����ڸ� �̿��ϸ�
	//iSKil		   ==> 00000000 00000000 00000000 00000011
	//SKill�ΰ��� 1�̶�� ���ڸ� �־��ټ��մ� 

	iSkill |= (int)GunslingerSkill::FocusedShot;

	std::cout << "iSkill = " << std::bitset<8>(iSkill) << std::endl;

	//iSkill ^= (int)GunslingerSkill::FocusedShot;		//������ �ְ�, ������ ����
	//iSkill ^= (int)GunslingerSkill::FocusedShot;


	//Ư��  �ڸ� ��Ʈ ����
	//Skill &= ~(int)GunslingerSkill::DualBuckshot;		//����
	iSkill = iSkill & ~(int)GunslingerSkill::DualBuckshot;

	if (iSkill & (int)GunslingerSkill::DualBuckshot)
	{
		std::cout << "������ �ߵ�" << std::endl;
	}
	if (iSkill & (int)GunslingerSkill::FocusedShot)
	{
		std::cout << "��Ŀ���� �ߵ�" << std::endl;
	}


	unsigned int iPlayer = 0;

	//ĳ���Ͱ� �޸���
	iPlayer |= RUNNING;
	//ĳ���Ͱ��� �����Ѵ�
	iPlayer |= ATTACKING;

	//�÷��̾� ����Ȯ��
	if (iPlayer & ATTACKING)
	{
		std::cout << "�÷��̾� ������" << std::endl;
	}

	//ĳ���� �޸� ����
	iPlayer &= ~RUNNING;

	if (iPlayer & RUNNING)
	{
		std::cout << "�޸��� ��" << std::endl;
	}
	else if (!(iPlayer & RUNNING))
	{
		std::cout << "�����ֽ��ϴ�" << std::endl;
	}


	//���� ������
	iPlayer |= JUMPING;

	iPlayer &= ~JUMPING;
	
	if (iPlayer & JUMPING)
	{
		std::cout << "���� ���� " << std::endl;
	}
	else if (!(iPlayer & JUMPING))
	{
		std::cout << "���� �Ұ���" << std::endl;
	}
	
	

	return 0;
}