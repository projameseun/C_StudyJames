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
		std::cout << m_Name << "님이 공격하였습니다" << std::endl;
	}

	virtual void CharacterInfo()
	{
		std::cout << "Name : " << m_Name << " HP : " << m_Hp << std::endl;
	}

	virtual void SpecialAbility() = 0;	//캐릭터들만의 고유스킬
};

class BattleMaster : public Character
{
public:
	string m_SweepingKick;	 //방천격
	string m_WindsWhisper;//바람의 속삭임 배틀마스터 고유스킬 
	
public:
	BattleMaster(const string&_name , int _hp , const string& _skill, const string& _skill2) :
		Character(_name, _hp) , m_SweepingKick(_skill) ,m_WindsWhisper (_skill2)
	{

	}

	 void Attack() override
	{
		std::cout << m_Name << "방천격 공격" << std::endl;
	}


	 void SpecialAbility() override
	{
		std::cout << m_Name << "고유스킬 : " << m_SweepingKick << std::endl;
		std::cout << m_Name << "고유스킬 : " << m_WindsWhisper << std::endl;
	}//캐릭터들만의 고유스킬

	 void SuperSKill()		//배틀마스터 초각성
	 {
		 std::cout << "배틀마스터 초각성스킬" << std::endl;
	 }
};

class Bard : public Character
{
public:
	int m_HealAmount; //바드 고유스킬
	string m_Heal;	
public:
	Bard(const string& _name, int _hp, int _healamount, const string& _heal) :
		Character(_name, _hp), m_HealAmount(_healamount), m_Heal(_heal)
	{

	}

public:
	void Attack() override
	{
		std::cout << m_Name << "평타로 공격" << std::endl;
	}


	void SpecialAbility() override
	{
		std::cout << m_Name << "고유스킬 : " << m_Heal << std::endl;

	}//캐릭터들만의 고유스킬

	void HealSkill(int _amout)
	{
		m_HealAmount += _amout;

		std::cout << "힐량이  "<<m_HealAmount <<" 증가 하였습니다" << std::endl;
		
	}
	
};

void GameEngine(std::vector<Character*>& player)
{
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->CharacterInfo();
		player[i]->Attack();

		//다운캐스팅을 사용해서 각 고유의 캐릭터만의 스킬을 구현
		//다운캐스팅이 제대로 일어나지 않았는데 터지지 않는다면 
		//심지어 nullptr이 됫는데 터지지않는다면 기본구현만 되잇어서 그렇다
		//만약에 변수를 넣게 된다면 무조건 터지게되어있다
		//그리고 자식의 고유 함수들은 가상함수가 아닌 정적바인딩이다 만약에 동적으로 만들면 무조건터진다
		if (BattleMaster* master = dynamic_cast<BattleMaster*>(player[i]))
		{
			master->SuperSKill();
		}
		else if (Bard* bard = dynamic_cast<Bard*>(player[i]))
		{
			bard->HealSkill(bard->m_HealAmount);
		}

		player[i]->SpecialAbility();		//플레이어 들만의 고유스킬

		std::cout << std::endl;
	}

}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<Character*> player;

	player.push_back(new Bard("바드", 70,100,"힐"));
	player.push_back(new BattleMaster("배틀마스터", 100,"방천격","바람의속삭임"));

	GameEngine(player);

	for (int i = 0; i < player.size(); ++i)
	{
		delete player[i];
	}

	return 0;
}