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

	//bob = alice;	//��������
	strcpy_s(bob.name, 30, alice.name); //���� ����ó�� �������� ���ڿ��� �����ѰŰ� �� �޸𸮸� �Ҵ��Ѱ� �ƴ϶�°� 
	//�ش� name�� �ٸ� �޸𸮸� ����Ű�� �Ǿ� free������ ������ ���� �ʴ°� ���̴�

	strcpy_s(alice.name, 30, "alice2");

	std::cout << alice.name << " " << alice.age << std::endl;
	std::cout << bob.name << " " << bob.age << std::endl;

	free(alice.name);
	free(bob.name);

	//��ģ���� ��������ó�� �������� ������ ������ �������� �ƴϾ�
	//��������� ��ü�� ���ο� ���纻�� �����ؾߵǴµ�
	//strcpy_s�� ���ڿ��� �����Ҷ� �� �޸𸮸� �Ҵ����������Ƿ� ��������� �ƴϴ�


	return 0;
}