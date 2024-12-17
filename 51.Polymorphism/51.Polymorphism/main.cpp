#include <iostream>

class CParent {
public:
    virtual void virutalFunc() {  // 가상 함수
        std::cout << "부모 함수" << std::endl;
    }

    void OutPut()
    {
        std::cout << "부모출력" << std::endl;
    }

};

class CChild : public CParent {
public:
    void virutalFunc() override {  // 부모의 Func를 오버라이딩
        std::cout << "자식 함수" << std::endl;
    }

    void OutPut()
    {
        std::cout << "자식출력" << std::endl;
    }

   
};


int main()
{


    CParent cParent;
    CChild child;

   CParent* pParent = &cParent;
   CChild* pChild = &child;

    //CParent* pParent = &child;  //문제가 없음 업캐스팅
    //pParent->OutPut();
    //pParent = &cParent;
  // CChild* pChild = &cParent;  //문제가 있음 다운캐스팅



    //CParent* pParent2 = nullptr;

    //pParent2 = &cParent;
    //pParent2->OutPut();

    //pParent2 = &child;
    //pParent2->OutPut();

    ////위에 와같이 실행하게되면 parent만 호출이 된다. child는 접근할수가없다 왜냐면 pPrent2 는 CParent* 이기때문에 자식의 주소를 넣어줘도 접근할수 없다.
    ////실제 진짜 다형성은 virtual함수를 사용해야 된다.
   
    //pParent2 = &cParent;
    //pParent2->virutalFunc();

    //pParent2 = &child;
    //pParent2->virutalFunc();

    

    //다운캐스팅을 할때 다이나믹 캐스팅 사용

    //가상함수 뒤에 = 0 을 붙여주면 순수가상함수라고 부른다
    //순수가상함수는 구현부분을 만들어도되고 안만들어도 된다.
    //순수가상함수는 자식클래스에서 반드시 재정의를 해야된다.
    //순수가상함수를 가지고 있는클래스를 추상클래스라고 부른다
    //추상클래스는 객체 생성이 불가능하다.
    // 만약 자식클래스에 순수가상함수가 재정의가 안되어 있으면
    // 자식클래스 또한 추상클래스가 된다.
    // 그렇기 때문에 자식클래스에서는 객체를 생성하는 클래스라면
    // 반드시 순수가상함수를 재정의 해주어야 한다.

    

	return 0;
}