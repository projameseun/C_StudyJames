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
	void(CObject::* m_pFunc)(CBomb*);
	CObject* m_pObj;

public:
	void SetPower(int iPower)
	{
		m_iPower = iPower;
	}

public:
	virtual bool Init();
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
	template <typename T>
	void SetBomblCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		//m_BombCallBack = std::bind(_pFunc, _pObj, std::placeholders::_1);
		
		m_pObj = _pObj;
		m_pFunc = static_cast<void (CObject::*)(CBomb*)>(_pFunc);
	}

private:
	void CreateItem(const COORD* _tpos);
};

