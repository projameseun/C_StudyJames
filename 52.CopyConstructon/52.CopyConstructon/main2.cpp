#include <iostream>

struct man
{
	char* name;
	int age;

public:
	//깊은 복사를 위한 대입연산자
	man& operator =(const man& _other)
	{
		if (this != &_other)
		{
			if (name)
			{
				free(name);
				name = nullptr;
			}
		}

		age = _other.age;

		//새 메모리 할당 및데이터 복사
		if (_other.name)
		{
			//c언어방식
			//name = (char*)malloc(30);//새로할당
			//strcpy_s(name, 30, _other.name);

			

			size_t iLength = strnlen_s(_other.name, 30);	//4하면터짐 

			//c++방식
			name = new char[iLength + 1];
			strcpy_s(name, iLength + 1, _other.name);
		}
		else
		{
			name = nullptr;
		}

		return *this;
	}

public:
	~man()
	{
		if (name != nullptr)
		{
			free(name);
			name = nullptr;
		}
	}

	

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	struct man alice;
	struct man bob;


	alice.name = (char*)malloc(30);
	bob.name = (char*)malloc(30);

	strcpy_s(alice.name, 30, "alice");
	alice.age = 20;
	strcpy_s(bob.name, 30, "bob");
	bob.age = 23;

	//struct man temp;

	//temp = bob;	//얕은복사를 해버리면 bob의 링크가 사라지기때문에 미리 저장해놓는다
	bob = alice;	//얕은복사
	//strcpy_s(bob.name, 30, alice.name); //깊은 복사처럼 보이지만 문자열만 복사한거고 새 메모리를 할당한건 아니라는거 
	//해당 name만 다른 메모리를 가리키게 되어 free햇을때 오류가 나지 않는것 뿐이다

	strcpy_s(alice.name, 30, "alice2");

	std::cout << alice.name << " " << alice.age << std::endl;
	std::cout << bob.name << " " << bob.age << std::endl;

	//if (alice.name != nullptr)
	//{
	//	free(alice.name);
	//	alice.name = nullptr;
	//}
	//if (bob.name != nullptr)
	//{
	//	free(bob.name);
	//	bob.name = nullptr;
	//}


	//이친구는 깊은복사처럼 보이지만 엄연히 따지면 깊은복사 아니야
	//깊은복사는 객체의 새로운 복사본을 생성해야되는데
	//strcpy_s는 문자열을 복사할때 새 메모리를 할당하지않으므로 깊은복사는 아니다


	return 0;
}