#include <iostream>


using namespace std;

struct man
{
	char* name;
	int age;

public:
	//���� ���縦 ���� ���Կ�����
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

		//�� �޸� �Ҵ� �׵����� ����
		if (_other.name)
		{
			//c�����
			//name = (char*)malloc(30);//�����Ҵ�
			//strcpy_s(name, 30, _other.name);

			

			size_t iLength = strnlen_s(_other.name, 30);	//4�ϸ����� 

			//c++���
			name = new char[iLength + 1];
			strcpy_s(name, iLength + 1, _other.name);
		}
		else
		{
			name = nullptr;
		}

		return *this;
	}

	//default ���Կ�����
	//man& operator =(const man& _other)
	//{
	//	this->name = _other.name;
	//	this->age = _other.age;
	//	return *this;
	//}

public:
	~man()
	{
	/*	if (name != nullptr)
		{
			free(name);
			name = nullptr;
		}*/
	}

	

};

class Test
{
public:
	const char* m_c;
	int* m_pi;
public:
	Test(const char* _c) : m_c(_c)
	{

	}
	Test(int* _i) : m_pi(_i)
	{

	}

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	struct man alice;
	struct man bob;

	Test t1("�ȳ��ϼ���");

	Test t2 = t1;

	t2.m_c = "����";

	std::cout << t1.m_c << std::endl;
	std::cout << t2.m_c << std::endl;

	int a = 10;
	Test t3(&a);

	Test t4 = t3;

	*t4.m_pi = 30;

	std::cout << *t3.m_pi << std::endl;
	std::cout << *t4.m_pi << std::endl;


	alice.name = (char*)malloc(30);
	bob.name = (char*)malloc(30);

	strcpy_s(alice.name, 30, "alice");
	alice.age = 20;
	strcpy_s(bob.name, 30, "bob");
	bob.age = 23;

	//struct man temp;

	//temp = bob;	//�������縦 �ع����� bob�� ��ũ�� ������⶧���� �̸� �����س��´�
	//bob = alice;	//����

	strcpy_s(alice.name, 30, "kaka");

	std::cout << alice.name << " " << alice.age << std::endl;
	std::cout << bob.name << " " << bob.age << std::endl;

	if (alice.name != nullptr)
	{
		free(alice.name);
		alice.name = nullptr;
	}
	if (bob.name != nullptr)
	{
		free(bob.name);
		bob.name = nullptr;
	}




	//��ģ���� ��������ó�� �������� ������ ������ �������� �ƴϾ�
	//��������� ��ü�� ���ο� ���纻�� �����ؾߵǴµ�
	//strcpy_s�� ���ڿ��� �����Ҷ� �� �޸𸮸� �Ҵ����������Ƿ� ��������� �ƴϴ�


	return 0;
}