#include <iostream>
#include <string>

//

class CItem
{
public:
	std::string m_Name;
	int iCase;

public:
	CItem(const std::string& _iteamname, int _case) :
		m_Name(_iteamname),iCase(_case)
	{

	}
	
};

class CPlayer
{
private:
	std::string m_Name;
	int iHP;
	int iMP;
	float fSpeed;
	CItem* m_Item;
	
public:
	CPlayer(const std::string& _name,int _hp,int _mp,float _speed,const std::string& _itemname, int _case) :	//Constructor
		m_Name(_name) , iHP(_hp) , iMP(_mp),fSpeed(_speed)
	{
		m_Item = new CItem(_itemname, _case);
	}
	~CPlayer()
	{
		delete m_Item;	
		std::cout << "소멸자 호출 " << std::endl;
	}

public:
	void PlayerInfo()
	{
		std::cout << "아이디 : " << m_Name << std::endl;
		std::cout << "HP : " << iHP << std::endl;
		std::cout << "MP : " << iMP << std::endl;
		std::cout << "속도 : " << fSpeed<< std::endl;
		std::cout << "아이템 : " << m_Item->m_Name<< std::endl;
		std::cout << "아이템 번호 : " << m_Item->iCase << std::endl;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CPlayer player("힐바드세여", 100, 100, 100,"집행검",1);	//캐릭터생성
	
	player.PlayerInfo();

	return 0;
}