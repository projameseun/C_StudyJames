#include <iostream>

class CParent {
public:
    virtual void virutalFunc() {  // ���� �Լ�
        std::cout << "�θ� �Լ�" << std::endl;
    }

    void OutPut()
    {
        std::cout << "�θ����" << std::endl;
    }

};

class CChild : public CParent {
public:
    void virutalFunc() override {  // �θ��� Func�� �������̵�
        std::cout << "�ڽ� �Լ�" << std::endl;
    }

    void OutPut()
    {
        std::cout << "�ڽ����" << std::endl;
    }

   
};


int main()
{


    CParent cParent;
    CChild child;

   CParent* pParent = &cParent;
   CChild* pChild = &child;

    //CParent* pParent = &child;  //������ ���� ��ĳ����
    //pParent->OutPut();
    //pParent = &cParent;
  // CChild* pChild = &cParent;  //������ ���� �ٿ�ĳ����



    //CParent* pParent2 = nullptr;

    //pParent2 = &cParent;
    //pParent2->OutPut();

    //pParent2 = &child;
    //pParent2->OutPut();

    ////���� �Ͱ��� �����ϰԵǸ� parent�� ȣ���� �ȴ�. child�� �����Ҽ������� �ֳĸ� pPrent2 �� CParent* �̱⶧���� �ڽ��� �ּҸ� �־��൵ �����Ҽ� ����.
    ////���� ��¥ �������� virtual�Լ��� ����ؾ� �ȴ�.
   
    //pParent2 = &cParent;
    //pParent2->virutalFunc();

    //pParent2 = &child;
    //pParent2->virutalFunc();

    

    //�ٿ�ĳ������ �Ҷ� ���̳��� ĳ���� ���

    //�����Լ� �ڿ� = 0 �� �ٿ��ָ� ���������Լ���� �θ���
    //���������Լ��� �����κ��� �����ǰ� �ȸ��� �ȴ�.
    //���������Լ��� �ڽ�Ŭ�������� �ݵ�� �����Ǹ� �ؾߵȴ�.
    //���������Լ��� ������ �ִ�Ŭ������ �߻�Ŭ������� �θ���
    //�߻�Ŭ������ ��ü ������ �Ұ����ϴ�.
    // ���� �ڽ�Ŭ������ ���������Լ��� �����ǰ� �ȵǾ� ������
    // �ڽ�Ŭ���� ���� �߻�Ŭ������ �ȴ�.
    // �׷��� ������ �ڽ�Ŭ���������� ��ü�� �����ϴ� Ŭ�������
    // �ݵ�� ���������Լ��� ������ ���־�� �Ѵ�.

    

	return 0;
}