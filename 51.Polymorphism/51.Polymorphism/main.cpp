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
    //CParent* parentPtr = new CChild();  // �θ� Ŭ���� �����ͷ� �ڽ� Ŭ���� ��ü�� �ٷ��.
   // parentPtr->virutalFunc();  // ���� ���ε�: �ڽ��� Func() ȣ�� (���� ������ ����)
   // delete parentPtr;

    CParent cParent;
    CChild child;

   // CParent* pParent = &cParent;
   // CChild* pChild = &child;

    CParent* pParent = &child;  //������ ���� ��ĳ����
    pParent->OutPut();
    pParent = &cParent;
   //CChild* pChild = &cParent;  //������ ���� �ٿ�ĳ����

   
   // pChild->OutPut();

    CChild* pChild = (CChild*)(pParent);
   // ((CChild*)pParent)->OutPut();
   // 1.�ٿ�ĳ������ ����Ҷ��� �Ϲ������� ��ĳ�������ϰ� ����ؾ� �ȴ�.

    if (nullptr != pChild)
    {
        pChild->OutPut();
    }

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