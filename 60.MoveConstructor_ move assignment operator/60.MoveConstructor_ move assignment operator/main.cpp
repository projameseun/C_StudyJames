#include <iostream>
#include <cstring>
#include <vector>

class MyString
{
	char* p_str;		//문자열 데이터를 가리키는 포인터
	int		iLength;		//문자열 길이
	int		iCapacity;	//현재 할당된 용량

public:
	MyString();

	//문자열로 부터 생성
	MyString(const char* _str);

	//복사생성자
	MyString(const MyString& _obj);


	//이동 생성자 
	MyString(MyString&& _obj) noexcept;


	MyString(MyString& _obj, bool shallow);

	MyString createString();

	~MyString();



};

MyString::MyString()
{
	std::cout << "생성자 호출 !" << std::endl;
	iLength = 0;
	iCapacity = 0;
	p_str = nullptr;
}

MyString::MyString(const char* _str)
{
	std::cout << "생성자 호출 !" << std::endl;
	iLength = strlen(_str);
	iCapacity = iLength;
	p_str = new char[iLength];

	for (int i = 0; i != iLength; ++i)
	{
		p_str[i] = _str[i];
	}

}

// 얕은 복사 생성자 (Shallow Copy Constructor)
MyString::MyString(MyString& _obj, bool shallow)
{
	std::cout << "얕은 복사 생성자 호출 !" << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iCapacity;
	p_str = _obj.p_str; // 포인터만 복사 (메모리 공유)
}

//복사생성자
MyString::MyString(const MyString& _obj)
{
	std::cout << "복사 생성자 호출 !" << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iLength;
	p_str = new char[iLength];

	for (int i = 0; i < iLength; ++i)
	{
		p_str[i] = _obj.p_str[i];
	}

}

//이동 생성자 
MyString::MyString(MyString&& _obj) noexcept
{
	std::cout << "이동 생성자 호출 ! " << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iCapacity;
	p_str = _obj.p_str;

	//임시 객체소멸시에 메모리를 해제하지 못하게한다
	//만약에 nullptr을 넣어주지 않게되면 임시객체가 사라질때 소멸자를 불러오고 이때 
	//메모리 해제가 된다. 
	//그러면 프로그램 종료시 소유권을넘긴 data가 삭제될때 이미 삭제된 주소이기때문에 댕글링 포인터가 일어난다.
	_obj.p_str = nullptr;

}

MyString::~MyString()
{

	std::cout << "소멸자 호출 " << std::endl;
	if (p_str != nullptr)
	{
		delete[] p_str;
	}
}

//임시객체 생성되는상황
//1.함수 반환값

MyString createString() {
	MyString s("abc");
	return s; // s의 복사본(임시 객체) 또는 이동(임시 객체)이 만들어짐
}

//int main() {
//	MyString a = createString(); // 임시 객체가 a로 복사/이동됨
//}

//2함수 인자  전달 (값으로 받을떄)
//void printString(MyString s) {
//	// s는 복사 생성자로 만들어진 임시 객체
//}
//
//int main() {
//	MyString a("abc");
//	printString(a); // a의 복사본(임시 객체)이 printString에 전달됨
//}

//3.연산결과 
//MyString getSum(const MyString& a, const MyString& b) {
//	// 두 객체를 합쳐서 새로운 MyString 반환
//	MyString result("ab");
//	return result; // result의 복사본(임시 객체) 또는 이동(임시 객체)
//}
//
//int main() {
//	MyString a("a"), b("b");
//	MyString c = getSum(a, b); // 임시 객체가 c로 복사/이동됨
//}

//4.표준 컨테이너에 값 추가
//int main() {
//	MyString s("abc");
//	std::vector<MyString> vec;
//	vec.push_back(s); // s의 복사본(임시 객체)이 벡터에 들어감
//}

//5.직접 임시 객체 생성
//int main() {
//	MyString a = MyString("abc"); // 오른쪽 MyString("abc")가 임시 객체
//}

//6.연산자 오버로딩 결과

//MyString operator+(const MyString& lhs, const MyString& rhs) {
//	MyString result("ab");
//	return result; // result의 복사본(임시 객체) 또는 이동(임시 객체)
//}
//
//int main() {
//	MyString a("a"), b("b");
//	MyString c = a + b; // 임시 객체가 c로 복사/이동됨
//}


int main()
{

	/*

	*/

	//MyString s("abc");
	//std::vector<MyString> vec;
	//std::cout << "첫 번째 추가 ---" << std::endl;
	//vec.push_back(static_cast<MyString&&>(s));
	//std::cout << "두 번째 추가 ---" << std::endl;
	//vec.push_back(s);
	//std::cout << "세 번째 추가 ---" << std::endl;
	//vec.push_back(std::move(s));
	MyString s("abc");
	std::vector<MyString> vec;
	std::cout << "첫 번째 추가 ---" << std::endl;
	vec.push_back(s);
	std::cout << "두 번째 추가 ---" << std::endl;
	vec.push_back(s);
	std::cout << "세 번째 추가 ---" << std::endl;
	vec.push_back(s);





	return 0;
}