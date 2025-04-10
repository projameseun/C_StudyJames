#pragma once
#include "CObject.h"
class CBomb : public CObject	
{
public:
	CBomb();
	~CBomb();

private:
	float		m_fBombTime;
	int			m_iPower;	
	std::function<void(CBomb*)>	m_BombCallBack;		//�Լ�������

	//��ȯ��(Ŭ�����̸�::* �������̸�)(�Ű����� ���);
	//����Լ� ������ ��ü������ ��������߰�
	//void(CObject::* m_pFunc)(CBomb*);
	//CObject* m_pObj;

public:
	void SetPower(int iPower)
	{
		m_iPower = iPower;
	}

public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);
	
public:
	//std::function<void(int)> funcName1 = Func; //�Լ� ����
	//std::function<void(int)> funcName2 = [](int a) {}; // �����Լ�
	//std::function<void(int)> funcName3 = std::bind(�Լ����ּ�, ����1,����2,); //std::bind
	// placeholders�ڸ�ǥ���� _1,_2,_3...��� �Ҽ��ִµ� �� �ش��ȣ�� ������Ű�� �ʰڴٴ°���
	//���ø��� ����Ͽ� Ư�� ��ü�� ����Լ��� �ݹ����� �����ϴ� �Լ�

	//1.�ݹ� �Լ��� ȣ��� ��ü�� ������, 2.Ÿ���� �μ��� �޴¸�� �Լ�������
	//std::bind�� ��� �Լ� �����Ϳ� ��ü �����͸� �����Ͽ� ��� �Լ��� ȣ���� �� �ִ� �Լ� ��ü�� ������ ���� �ֽ��ϴ�.

//	//placeholders���� 
//	int sum(int a, int b, int c)
//	{
//		return a + b * 10 + c * 100;
//}
//	int main()
//	{

//		auto func3 = std::bind(sum, 1, std::placeholder::_2, std::placeholder::_1);
//		cout << func3(2, 3) << endl;
//	}
	template <typename T>
	void SetBomblCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		m_BombCallBack = std::bind(_pFunc, _pObj,placeholders::_1);		
	/*	m_pObj = _pObj;
		m_pFunc = static_cast<void (CObject::*)(CBomb*)>(_pFunc);*/
	}

private:
	void CreateItem(const COORD* _tpos);
};

