#include <iostream>
#include <set>
#include <string>
#include <map>

#include "CBST.h"

using std::string;
using std::wstring;
using std::endl;

enum class Gender
{
    MAN = 1,
    WOMAN = 2,

};

class CStdInfo
{
public:
    wstring              m_stName;
    unsigned char        m_Age;
    unsigned char        m_Gender;



public:
    CStdInfo() :
        m_stName{},
        m_Age(0),
        m_Gender(0)
    {

    }

    CStdInfo(const wstring& _pName, unsigned char _age, unsigned char _gender) :
        m_stName(_pName),
        m_Age(_age),
        m_Gender(_gender)
    {
        //wcscpy_s(m_stName, 25, _pName);
    }

};

class MyClass
{

};



int main()
{

    ////지역설정
   _wsetlocale(LC_ALL, L"korean");
   
    //map부터...

   //std::set<int> setInt;

   //setInt.insert(100);
   //setInt.insert(50);
   //setInt.insert(150);

    
   
    //std::map<const wchar_t, CStdInfo> mapData;

    //CStdInfo info(L"박만냥", 20, (char)Gender::MAN);
    //CStdInfo info2(L"권효진", 25, (char)Gender::WOMAN);


    //mapData.insert(std::make_pair(L"박만냥", info));
    //mapData.insert(std::make_pair(L"권효진", info2));

    //std::map<const wchar_t, CStdInfo>::iterator mapiter;

    //wchar_t stName[25] = L"권효진";    //주소가 아예다른거고

    //const wchar_t* pStr = L"박만냥";    //주소가 같아서 ...

    //mapiter = mapData.find(pStr);

    ////지역설정
    //_wsetlocale(LC_ALL, L"korean");


    //if (mapiter == mapData.end())
    //{
    //    std::wcout << L"아무도 찾지 못했습니다" << std::endl;
    //}
    //else
    //{
    //    std::wcout << L"이름 : " << mapiter->second.m_stName << std::endl;
    //    std::wcout << L"나이 : " << mapiter->second.m_Age << std::endl;
    //    std::wcout << L"성별 : ";
    //    if ((char)Gender::MAN == mapiter->second.m_Gender)
    //    {
    //        std::wcout << L"남자" << std::endl;
    //    }
    //    else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
    //    {
    //        std::wcout << L"여자" << std::endl;
    //    }

    //    else
    //    {
    //        std::wcout << L"아무것도 찾지 못했습니다." << std::endl;
    //    }

    //}

    //위같은 경우는 문자열을 찾아서 찾아냈다고 볼수없다.
    //주소값을 비교해서 나온것이다. 주소의 값을 찾은거다.
    //우리가 원하는 문자열을 찾아서 가져올려고하면 string함수를 사용해야 된다.

    system("cls");
    
#pragma region MapBasic
    {
        std::map<wstring, CStdInfo> mapData;

        CStdInfo info(L"김우람", 20, (char)Gender::MAN);
        CStdInfo info2(L"김나현", 25, (char)Gender::WOMAN);

        mapData.insert(std::make_pair(L"김우람", info));
        mapData.insert(std::make_pair(L"김나현", info2));

        wstring stTest;

        stTest = L"김나현";

        std::map<wstring, CStdInfo>::iterator mapiter;

        mapiter = mapData.find(L"김우람");

        
     
        if (mapiter == mapData.end())
        {
            std::wcout << L"아무도 찾지 못했습니다" << std::endl;
        }
        else
        {
            std::wcout << L"이름 : " << mapiter->second.m_stName << std::endl;
            std::wcout << L"나이 : " << mapiter->second.m_Age << std::endl;
            std::wcout << L"성별 : ";
            if ((char)Gender::MAN == mapiter->second.m_Gender)
            {
                std::wcout << L"남자" << std::endl;
            }
            else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
            {
                std::wcout << L"여자" << std::endl;
            }

            else
            {
                std::wcout << L"아무것도 찾지 못했습니다." << std::endl;
            }

        }



    }

    {

        wstring str1;
        wstring str2;

        str1 = L"test";
        str2 = L"testabcdefg";

        str1 = L"ffffffff";

        str1 += L"abc";

        str1[1] = L'k';

        if (str1 == str2)
        {
            std::cout << "문자열이 서로 같습니다" << std::endl;
        }
        else
        {
            std::cout << "문자열이 서로 다릅니다" << std::endl;
        }


    }
#pragma endregion


    CBST<int, int> BstInt;

    

    
    BstInt.insert(MySTD::make_pair(100,0));         //                              150
    
    BstInt.insert(MySTD::make_pair(50, 0));        //                    50                  200

    BstInt.insert(MySTD::make_pair(70, 0));        //                 25      70               300
    
    BstInt.insert(MySTD::make_pair(25, 0));         //                     65     80

    BstInt.insert(MySTD::make_pair(80, 0));

    BstInt.insert(MySTD::make_pair(65, 0));
    
    BstInt.insert(MySTD::make_pair(200, 0));
    BstInt.insert(MySTD::make_pair(150, 0));
    
    BstInt.insert(MySTD::make_pair(300, 0));

    CBST<int, int>::iterator iter = BstInt.begin();

    iter = BstInt.find(100);
    iter = BstInt.erase(iter);
  
    ++iter;

 
   /* std::cout << (*iter).first << std::endl;

    for (iter = BstInt.begin(); iter != BstInt.end(); ++iter)
    {
        std::cout << iter->first << std::endl;
    }*/
    
    //삭제...
    //1. 삭제할 노드가 단말 노드(leafNode)의 경우
    //2. 삭제할 노드가 자식노드를 한개 가진경우(자식이 부모로 연결해준다)
    //3. 삭제할 노드가 2개의 자식을 가진경우

  
    

    return 0;
}