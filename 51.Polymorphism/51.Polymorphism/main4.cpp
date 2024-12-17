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
	//순수가상함수를 사용하는 게임예시 인터페이스의 핵심이 잇다

	
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

	//순수 가상함수에 소멸자를 넣는이유
	//순수가상함수 소멸자를 넣지않으면 자식클래스의 소멸자가 호출되지않아서 메모리 누수가 발생한다.
	//순수가상함수 소멸자를 넣음으로써 다형성을 사용할때 자식클래스의 소멸자가 올바르게 호출되기 위함이다.

	GameEngine* pGameEngine = new player();

	pGameEngine->render();
	
	delete pGameEngine;
	

	return 0;
}