#include <iostream>

struct man
{
	char* name;
	int age;

};

int main()
{
	struct man alice;
	struct man bob;


	alice.name = (char*)malloc(30);
	bob.name = (char*)malloc(30);

	strcpy_s(alice.name, 30, "alice");
	alice.age = 20;
	strcpy_s(bob.name, 30, "bob");
	bob.age = 23;

	//bob = alice;	//얕은복사
	strcpy_s(bob.name, 30, alice.name); //깊은 복사처럼 보이지만 문자열만 복사한거고 새 메모리를 할당한건 아니라는거 
	//해당 name만 다른 메모리를 가리키게 되어 free햇을때 오류가 나지 않는것 뿐이다

	strcpy_s(alice.name, 30, "alice2");

	std::cout << alice.name << " " << alice.age << std::endl;
	std::cout << bob.name << " " << bob.age << std::endl;

	free(alice.name);
	free(bob.name);

	//이친구는 깊은복사처럼 보이지만 엄연히 따지면 깊은복사 아니야
	//깊은복사는 객체의 새로운 복사본을 생성해야되는데
	//strcpy_s는 문자열을 복사할때 새 메모리를 할당하지않으므로 깊은복사는 아니다


	return 0;
}