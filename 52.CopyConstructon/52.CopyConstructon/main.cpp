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
			m_Item = new CItem(*_player.m_Item);	//�������ּҸ� �����Ҵ��Ѵٴ°� 
			
		}
		else
		{
			m_Item = _player.m_Item;
		}
	}
	~CPlayer()
	{
		delete m_Item;	
		std::cout << "�Ҹ��� ȣ�� " << std::endl;
	}

public:
	void PlayerInfo()
	{
		std::cout << "���̵� : " << m_Name << std::endl;
		std::cout << "HP : " << iHP << std::endl;
		std::cout << "MP : " << iMP << std::endl;
		std::cout << "�ӵ� : " << fSpeed<< std::endl;
		std::cout << "������ : " << m_Item->m_Name<< std::endl;
		std::cout << "������ ��ȣ : " << m_Item->iCase << std::endl;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CPlayer player("���ٵ弼��", 100, 100, 100,"�����",1);	//ĳ���ͻ���
	//player.PlayerInfo();
	

	//�������� 
	//������ �ּҸ� �����ؼ� �ΰ�ü�� ������ ������ ����
	CPlayer player2 = player;
	//player2.PlayerInfo();	//��۸�������

	//��۸������� ==> �� �̻� ��ȿ���� ���� �޸� �ּҸ� ����Ű�� �����͸� ���Ѵ�.
	//��������Ϳ� ���輺
	//������ �޸𸮸� �����ϰų� �����ϸ�, ���α׷��� ������������ ����Ǿ �޸� �ջ��� �߻��Ҽ��ִ�.
	//������� �ſ��ƴ� ��۸� ������ ������ �ڵ������(��Ÿ�Ӌ�) Ư�� ��Ȳ������ �߻��Ҽ� �־ ã�Ⱑ �ſ� ��ƴ�.

	//��������
	//�����Ͱ� ����Ű�� �����͸� ���� �����Ҵ� �Ͽ� ���� 
	//CPlayer player2(player, true);
	
	//player2.SetString("Ȩť��");
	//player2.PlayerInfo();
	

	return 0;
}