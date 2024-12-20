#include <iostream>
#include <string>

//

class CItem
{
public:
	std::string m_Name;
	int iCase;

public:
	CItem()
	{

	}
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
	void SetString(std::string _str)
	{
		m_Name = _str;
	}
	
public:
	CPlayer(const std::string& _name,int _hp,int _mp,float _speed,const std::string& _itemname, int _case) :	//Constructor
		m_Name(_name) , iHP(_hp) , iMP(_mp),fSpeed(_speed)
	{
		m_Item = new CItem(_itemname, _case);
	}
	////ShallowCopy
	//CPlayer(const CPlayer& _player) :
	//	m_Name(_player.m_Name), iHP(_player.iHP), iMP(_player.iMP), fSpeed(_player.fSpeed),m_Item(_player.m_Item)
	//{
	//	std::cout << "ShallowCopy Call" << std::endl;
	//}

	//ShallowCopy2
	CPlayer(const CPlayer& _player) :
		m_Name(_player.m_Name), iHP(_player.iHP), iMP(_player.iMP), fSpeed(_player.fSpeed)
	{
		//*this = _player;
		m_Item = new CItem;
		memcpy(m_Item, _player.m_Item, sizeof(CItem));
		
		std::cout << "ShallowCopy Call" << std::endl;
	}

	//DeepCopy
	CPlayer(const CPlayer& _player,bool _copy) :
		m_Name(_player.m_Name), iHP(_player.iHP), iMP(_player.iMP), fSpeed(_player.fSpeed)
	{
		if (_copy)
		{
			m_Item = new CItem(*_player.m_Item);	//포인터주소를 동적할당한다는거 
			
		}
		else
		{
			m_Item = _player.m_Item;
		}
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
	//player.PlayerInfo();
	

	//얕은복사 
	//포인터 주소만 복사해서 두객체가 동일한 공간을 참조
	CPlayer player2 = player;
	//player2.PlayerInfo();	//댕글링포인터

	//댕글링포인터 ==> 더 이상 유효하지 않은 메모리 주소를 가리키는 포인터를 말한다.
	//댕글포인터에 위험성
	//해제된 메모리를 참조하거나 수정하면, 프로그램이 비정상적으로 종료되어서 메모리 손상이 발생할수있다.
	//디버깅이 매우어렵다 댕글링 포인터 문제는 코드실행중(런타임떄) 특정 상황에서만 발생할수 있어서 찾기가 매우 어렵다.

	//깊은복사
	//포인터가 가리키는 데이터를 새로 동적할당 하여 복사 
	//CPlayer player2(player, true);
	
	//player2.SetString("홈큐피");
	//player2.PlayerInfo();
	

	return 0;
}