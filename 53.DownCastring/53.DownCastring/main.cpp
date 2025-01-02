#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character
{
protected:
	string	m_Name;
	int		m_Hp;

public:
	Character(const string& _name, int _hp) :
		m_Name(_name), m_Hp(_hp)
	{

	}

	virtual ~Character()
	{

	}

public:
	virtual void Attack()
	{
		std::cout << m_Name << "���� �����Ͽ����ϴ�" << std::endl;
	}

	virtual void CharacterInfo()
	{
		std::cout << "Name : " << m_Name << " HP : " << m_Hp << std::endl;
	}

	virtual void SpecialAbility() = 0;	//ĳ���͵鸸�� ������ų
};

class BattleMaster : public Character
{
public:
	string m_SweepingKick;	 //��õ��
	string m_WindsWhisper;//�ٶ��� �ӻ��� ��Ʋ������ ������ų 
	
public:
	BattleMaster(const string&_name , int _hp , const string& _skill, const string& _skill2) :
		Character(_name, _hp) , m_SweepingKick(_skill) ,m_WindsWhisper (_skill2)
	{

	}

	 void Attack() override
	{
		std::cout << m_Name << "��õ�� ����" << std::endl;
	}


	 void SpecialAbility() override
	{
		std::cout << m_Name << "������ų : " << m_SweepingKick << std::endl;
		std::cout << m_Name << "������ų : " << m_WindsWhisper << std::endl;
	}//ĳ���͵鸸�� ������ų

	 void SuperSKill()		//��Ʋ������ �ʰ���
	 {
		 std::cout << "��Ʋ������ �ʰ�����ų" << std::endl;
	 }
};

class Bard : public Character
{
public:
	int m_HealAmount; //�ٵ� ������ų
	string m_Heal;	
public:
	Bard(const string& _name, int _hp, int _healamount, const string& _heal) :
		Character(_name, _hp), m_HealAmount(_healamount), m_Heal(_heal)
	{

	}

public:
	void Attack() override
	{
		std::cout << m_Name << "��Ÿ�� ����" << std::endl;
	}


	void SpecialAbility() override
	{
		std::cout << m_Name << "������ų : " << m_Heal << std::endl;

	}//ĳ���͵鸸�� ������ų

	void HealSkill(int _amout)
	{
		m_HealAmount += _amout;

		std::cout << "������  "<<m_HealAmount <<" ���� �Ͽ����ϴ�" << std::endl;
		
	}
	
};

void GameEngine(std::vector<Character*>& player)
{
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->CharacterInfo();
		player[i]->Attack();

		//�ٿ�ĳ������ ����ؼ� �� ������ ĳ���͸��� ��ų�� ����
		//�ٿ�ĳ������ ����� �Ͼ�� �ʾҴµ� ������ �ʴ´ٸ� 
		//������ nullptr�� �̴µ� �������ʴ´ٸ� �⺻������ ���վ �׷���
		//���࿡ ������ �ְ� �ȴٸ� ������ �����ԵǾ��ִ�
		//�׸��� �ڽ��� ���� �Լ����� �����Լ��� �ƴ� �������ε��̴� ���࿡ �������� ����� ������������
		if (BattleMaster* master = dynamic_cast<BattleMaster*>(player[i]))
		{
			master->SuperSKill();
		}
		else if (Bard* bard = dynamic_cast<Bard*>(player[i]))
		{
			bard->HealSkill(bard->m_HealAmount);
		}

		player[i]->SpecialAbility();		//�÷��̾� �鸸�� ������ų

		std::cout << std::endl;
	}

}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<Character*> player;

	player.push_back(new Bard("�ٵ�", 70,100,"��"));
	player.push_back(new BattleMaster("��Ʋ������", 100,"��õ��","�ٶ��Ǽӻ���"));

	GameEngine(player);

	for (int i = 0; i < player.size(); ++i)
	{
		delete player[i];
	}

	return 0;
}