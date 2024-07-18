#include <iostream>
/*
	��ü���� ���α׷���(OOP) : ���� �Ҷ� �ʿ��� ��ɵ��� ����� �ΰ� �ʿ��Ҷ�
	��ɵ��� �����Ͽ� ������ �����ϴ� ����� ���Ѵ�.
	������ + ����� �ϳ��� ��� ��ǰ�� ����� ��ǰ���� �����Ͽ� �ϼ���
	���α׷��� ����� ������ ����̴�
	ex)�κ��� ���鶧 ���� ������ ��ɿ� �°� ����� ����

	Ŭ����:c++���� ��ü ���� ���α׷����� �����ϱ� ���� ���Ǵ� �����̴�.
	����ü�� ������ ����� ������� ����� �Ǵµ� ����ü������ �����鸸 ��Ƶΰ�
	����� ������ Ŭ���������� �ʿ��� �Լ��鵵 ����� �ΰ� ��� �Ҽ� �ִ�.
	c++������ ����ü������ Ŭ������ �����ϰ� �Լ��� ���� ����� �ϴ� ���� �����ϴ�(c++�����Ϸ�)
	
	Ŭ������ 4�����Ӽ�
	ĸ��ȭ: �����ִ� ���� Ȥ�� ��ɵ��� �ϳ��� ���� �ִ� ����� ���Ѵ�.

	����ȭ: Ŭ������ ���� Ȥ�� ��ɵ��� �ܺο� �����ϴ� ������ �����ϴ°��� ���Ѵ�

	Ŭ������ ����: �ش� Ŭ���� ������� �Լ� ���� ���Ѵ�
	
	-public: Ŭ������ ���� Ȥ�� �ܺ� ����������� ������ ���� �Ѱ��� ���Ѵ�.
	-private: Ŭ������ ���ο����� ������ �����ϰ� �ܺο�����  ������ �Ұ���
	-protected: ��� ���� ����

	��Ӽ�,������ ==> ����� ���ԵǸ� �׶� 

	this -> �ڱ� �ڽ� �޸��̴�.

*/

class CPlayer
{
	//��� ����
public:
	char	m_StrName[25];
	int		m_iAttack;
	int		m_iDefence; 

private:
	int		m_iHP;
	int		m_iHPMax;
	int* m_pInt;

public:
	//��� �Լ�
	int GetHP()
	{
		return this->m_iHP;
		//return m_iHP;
	}

	void SetHP(int _hp)
	{
		//(*this).m_iHP = _hp;
		this->m_iHP = _hp;
	}

public:
	//�����ڿ� �Ҹ��ڴ� Ŭ������ �̸��� ������ �̸��� �Լ��̴�.
	//�� �Լ����� ��ȯ Ÿ���� ����.
	//���� ����, �Ҹ��ڸ� ��������� ���������� �⺻ �����ڿ�, �Ҹ��ڸ� ����ϰ� �ȴ�.
	//������ָ� ������� �����ڿ� �Ҹ��ڰ� ���۵ȴ�.
	//������: �� Ŭ������ �̿��ؼ� ��ü�� �����Ҷ� ȣ��Ǵ� �Լ��̴�.
	//�̷� Ư¡ ������ �� Ŭ���� �����͸� �ʱ�ȭ�ϴ� ������ �����Ҷ� ȿ�����̴�
	//�����ڴ� �����ε��� �����ϴ�.
	//�������� ���ڸ� Ȱ���ؼ� ���� �����ڸ� �����ε� �س��� ��� �ϴ°��� �����ϴ�.

	CPlayer()
	{
		std::cout << "CPlayer ������" << std::endl;
		
		m_pInt = new int;
		*m_pInt = 999;

	}

	CPlayer(const char* _name)
	{
		std::cout << "CPlayer " << _name << "������ " << std::endl;
		m_pInt = new int;
		*m_pInt = 999;
		
	}
	//������ �̴ϼ� ������
	CPlayer(const char* _name, int _attack, int _def, int hp, int mxhp, int* _pint)
		:m_StrName("james"),
		m_iAttack(_attack),
		m_iDefence(_def),
		m_iHP(hp),
		m_iHPMax(mxhp),
		m_pInt(nullptr)
	{

		
	}
	~CPlayer()
	{
		if (m_pInt != nullptr)
		{
			delete m_pInt;
			m_pInt = nullptr;
			std::cout << "CPlayer �Ҹ��� " << std::endl;
		}
		

	}
	
};

class CPoint
{
public:
	int x;
	int y;

public:
	CPoint()
	{
		x = 0;
		y = 0;
	}
	~CPoint()
	{

	}

public:
	//������ �����ε� 
	//�ڷ��� * ������ -- ������ ���� ����
	//*������ ����  -- ������
	//&����; ----������ �ּҰ� ��ȯ
	//�ڷ��� & ������; -- ���۷��� ���� ����
	const CPoint& operator + (const CPoint& pt)
	{
		CPoint result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	const CPoint& operator + (int iNumber)
	{
		CPoint result;
		result.x = x + iNumber;
		result.y = y +  iNumber;
		return result;
	}

	//���Կ����� 
	 CPoint& operator = (const CPoint& _Other)
	{
		//CPoint result;
		
		x =  _Other.x;
		y =  _Other.y;

		return *this;
	}
};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CPlayer player;
	CPlayer player2("james",10,10,100,100,nullptr);

	std::cout << player2.m_StrName << std::endl;
	std::cout << player2.m_iAttack << std::endl;
	std::cout << player2.m_iDefence << std::endl;
	std::cout << player2.GetHP() << std::endl;


	//����ü�� ���������ڸ� �Ƚ��ٶ��� �ڵ����� public
	//Ŭ������ ���������ڸ� �Ƚ��ٶ��� �ڵ����� pirvate
	//player��ü�� hp�� private�� �����߱⶧���� �����ü� ���� 
	//�̷��� get�Լ��� �̿��ϸ� �����ϴ�

	player.SetHP(1000);
	
	std::cout << "Player HP : " << player.GetHP() << std::endl;

	CPoint pt1, pt2, pt3;


	pt2.x = 100;
	pt2.y = 100;

	//�̷��� �ϸ� Ŭ�������� ���Կ����ڰ� �־ �����Ѱǵ� �������� ������ �����ε��� ����Ͽ� ��������ֵ�
	pt1 = pt2;

	pt1 = pt2 = pt3;

	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	//������ �����ε�
	//���� �������� ������ ������ �Ͽ� ����� �� �ְ� �ϴ� ��� �̴�
	//pt1�� + �Լ��� ȣ���Ѵ� . ���ڷ� pt2�� �Ѱ��ش�

	pt3 = pt1 + pt2;



	std::cout << "x : " << pt3.x << "y : " << pt3.y << std::endl;
	
	pt3 = pt1 + 50;
	
	std::cout << "x : " << pt3.x << "y : " << pt3.y << std::endl;

	//���۷���
	{
		//���� �������� ���� ���Ѵٸ�
		//���۷����� ����� ���ÿ� �ʱ�ȭ�� �ؾߵǰ� �ٸ� ������ ����ų�� ����.
		//������ �����ʹ� �ٸ� ������ ����ų�� �ִ�.

		//�����Ϸ� ����:
		//���۷����� �� �����ϰ� �������� �ݸ�, �����ʹ� �������ϰ� �����Ҽ� �־�.
		//����� ����:
		//���۷����� �����ʹ� ���������γ� �������� �и��� ���̰� �ִ�...
		int a = 100;
		int* ptr = &a;
		*ptr = 500;
		
		//���� �����ϸ� ���۷����� �ſ� ����
		//int* const ptr = &a;

		//int b = 100;
		//ptr = &b;

		int& ref = a;
		ref = 600;

		//const int* const ptr = &a;
		const int& constRef = a;
		
		//�̰Ŷ� ���
		
		//constRef = 100; �ȵȴ�
		
	}


	
	return 0;
}