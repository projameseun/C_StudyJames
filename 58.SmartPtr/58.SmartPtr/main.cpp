#include <iostream>

//2.	delete를 사용해서 함수(생성자, 연산자 등) 사용 금지
class Singleton {
public:
	Singleton(const Singleton&) = delete;            // 복사 생성자 금지
	Singleton& operator=(const Singleton&) = delete; // 복사 대입 연산자 금지
};

/*
	스마트 포인터
		c++에서 메모리 관리의 안정성과 편의성을 높이기 위해 제공되는 클래스 템플릿이다.
		일반 포인터와 달리, 스마트 포인터는 객체의 소유권과 생명주기를 자동으로 관리하여, 메모리
		누수나 잘못된  접근을 방지합니다.

		스마트 포인터 대표적인 종류
		std::unique_ptr : 한 객체의 소유권을 하나의 포인터만 가짐. 복사불가,이동만 가능
		std::shared_ptr :여러 포인터가 하나의 객체를  공유. 참조 카운팅으로 객체의 생명주기 관리
		std::weak_ptr : shard_ptr와 함께 사용. 참조카운트에 영향을 주지않으며,순환 참조 방지에 사용된다.

		스마트포인터는 이외에도 리소스를 관리하는데에도 사용할수 있다
		파일,네트워크연결,뮤텍스등 리소스를 안전하게 관리하기위해서 스마트 포인터를 사용할수 있다.

		스마트 포인터는 포인터처럼 동작하지만,메모리를 직접 관리하는것이 아니라 
		RAII(Resource Acquisition Is Initialization)이라는 원칙을 사용해 메모리를 자동으로 관리한다
		RAII는 c++에서 사용되는 디자인패턴으로, 자원관리를 객체의 수명주기에 바인딩하여 안전하고 효율적인 자원 관리를 가능하게하는 기법이다.
		즉, 객체가 생성 될때 자원을 할당하고, 객체가 소멸 될때 자원을 해제 합니다.

		스마트 포인터는 내부적으로 원시포인터(raw pointer)를 보관하고 있다. 이 원시 포인터는 스마트 포인터가 가리키는 실제 메모리를 가리키게 된다.
		그러나 사용자는 직접 접근할수 없으며, 스마트 포인터가 제공하는 인터페이스를 통해서만 접근이 가능하다.

		스마트 포인터는 또한 소유권(ownership)개념을 도입하여 동일한 메모리에 대한 접근을 관리하고 있다.

		스마트 포인터를 사용하더라도 메모리 관리에 대한 주의는 필요합니다.
		메모리 누수를 방지하는데 매우 효과적이지만, 모든 메모리 관리문제를해결하지는 못한다
		예를들어 스마트포인터를 사용하더라도 순환참조와 같은 문제가 발생할수 있다.


*/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//메모리를 직접 해제 해주지 않으면 메모리 누수가 생긴다
	//int* iNumber = new int;

	//delete iNumber;

	//*iNumber = 20; 댕글링 포인터

	//직접 해제를 해주지않아도 프로그램 종료시 해제가 된다.
	std::unique_ptr<int> smart_ptr(new int(10));


	//1. delete 메모리 해제 로 쓰였을때 
	int* p = new int;
	delete p; // 동적으로 할당한 메모리 해제

	std::unique_ptr<int>ptr1(new int(10));
	std::unique_ptr<int>ptr2 = std::move(ptr1);	//직접 소유권을 이동할수있다.

	int a = 0;

	return 0;
}