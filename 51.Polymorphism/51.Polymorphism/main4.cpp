#include <iostream>
#include <vector>
class GameEngine
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
	virtual ~GameEngine() {}
};

class player : public GameEngine
{
public:
	int* data = new (int[100]);

public:
	void render() override
	{
		std::cout << "Render Player" << std::endl;
	}

	void update() override
	{
		std::cout << "Update Player" << std::endl;
	}

	~player()
	{
		delete[] data;
		std::cout << "Player Delete" << std::endl;
	}
};

class Monster : public GameEngine
{
public:
	void render() override
	{
		std::cout << "Render Monster" << std::endl;
	}

	void update() override
	{
		std::cout << "Update Monster" << std::endl;
	}

};

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//���������Լ��� ����ϴ� ���ӿ��� �������̽��� �ٽ��� �մ�

	
	//std::vector<GameEngine*> pGameEngine;


	//pGameEngine.push_back(new player());
	//pGameEngine.push_back(new Monster());
	//

	//for (int i = 0; i < pGameEngine.size(); ++i)
	//{
	//	pGameEngine[i]->render();
	//	pGameEngine[i]->update();
	//}

	//for (int i = 0; i < pGameEngine.size(); ++i)
	//{
	//	delete pGameEngine[i];
	//	
	//}

	//���� �����Լ��� �Ҹ��ڸ� �ִ�����
	//���������Լ� �Ҹ��ڸ� ���������� �ڽ�Ŭ������ �Ҹ��ڰ� ȣ������ʾƼ� �޸� ������ �߻��Ѵ�.
	//���������Լ� �Ҹ��ڸ� �������ν� �������� ����Ҷ� �ڽ�Ŭ������ �Ҹ��ڰ� �ùٸ��� ȣ��Ǳ� �����̴�.

	GameEngine* pGameEngine = new player();

	pGameEngine->render();
	
	delete pGameEngine;
	

	return 0;
}