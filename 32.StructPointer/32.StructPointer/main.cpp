#include <iostream>


//구조체 와 포인터 
typedef struct Player
{
	int iHP;	//멤버 변수 
	int iMP;
	float fAttack;
	int iDeffence;
	float fSpeed;
	
public:
	void Init()
	{
		iHP = 100;
		iMP = 100;
		fAttack = 10.f;
		iDeffence = 50;
		fSpeed = 10.f;
	}

	void Attack()
	{
		std::cout << "Player Attack !" << std::endl;
	}

	void Die()
	{
		std::cout << "Player DIE" << std::endl;
		iHP = 0;
	}

	void Run()
	{
		std::cout << "Player Running " << std::endl;
	}

	void PlayerInfo(int hp, int mp)
	{
		std::cout << "Player " << std::endl;
		std::cout << "HP : " << hp << std::endl;
		std::cout << "MP : " << mp << std::endl;
		std::cout << "Attack : "  << fAttack<<std::endl;
		std::cout <<  "Deffece : " << iDeffence << std::endl;
		std::cout <<  "Speed " << fSpeed << std::endl;
		
	}

	int GetHP()
	{
		return iHP;
	}

	int GetMP()
	{
		return iMP;
	}
	

	void SetHP(int hp)
	{
		iHP = hp;
	}

	void SetMP(int mp)
	{
		iMP= mp;
	}


}MYPLAYER;



int main()
{

	MYPLAYER Player = {};

	Player.Init();
	Player.Attack();

	MYPLAYER* pPlayer = &Player;

	//(pPlayer)->iHP 같은말
	std::cout << pPlayer->iHP << std::endl;

	Player.PlayerInfo(Player.GetHP(),Player.GetMP());

	pPlayer->SetHP(300);

	std::cout << std::endl;
	std::cout << std::endl;

	Player.PlayerInfo(Player.GetHP(), Player.GetMP());
	
	std::cout << (*pPlayer).GetHP() << std::endl;
	std::cout << (*pPlayer).GetMP() << std::endl;

	return 0;
}