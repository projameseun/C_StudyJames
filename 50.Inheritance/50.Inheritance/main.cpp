#include <iostream>

class CParent
{
private:
	int m_i;

public:
	CParent() :
		m_i(0)
	{
		std::cout << "�θ� ������ ȣ��" << std::endl;
	}

	
};

class CChild : public CParent
{
private:
	float m_f;

public:
	CChild() :
		m_f(0.f),
		CParent()
	{
		std::cout << "�ڽ� ������ ȣ�� " << std::endl;
	}
};

int main()
{
	//���
	//ĸ��ȭ
	//���
	//������
	//�߻�ȭ

	//�ڽ��� ȣ��������
	//�ʱ�ȭ�� �θ���� �Ͼ���� 
	//ȣ������� �ڽĺ��� �Ͼ�� �򰥷����� �ȵȴ�.
	//�����ϸ� ������ ȣ����� �ڽ� -> �θ�
	//������ ������� �θ� - > �ڽ�

	//�ٿ�ĳ����,��ĳ����
	//������( ���������(��������,��������)
	//�������̵�, �����Լ� 

	CParent cp;
	CChild ch;

	CParent* pCp = &ch;

	CChild ch;
	return 0;
}