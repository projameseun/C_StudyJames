#include <iostream>

using namespace std;

class MoveCopy
{
private:
	int m_idata;
	char* m_str;

public:
	MoveCopy() : m_idata(0), m_str(nullptr)
	{
		cout << "기본 생성자 호출" << endl;
	}

	//복사 생성자(깊은복사)
	MoveCopy(const MoveCopy& other) :m_idata(other.m_idata), m_str(other.m_str)
	{
		if (other.m_str)
		{
			size_t len = strlen(other.m_str) + 1;
			m_str = new char[len];
			strcpy_s(m_str, len, other.m_str);
		}
		else
		{
			m_str = nullptr;
		}

		std::cout << "깊은 복사 생성자 호출 " << std::endl;


	}

	//복사 대입연산자 (깊은복사)
	MoveCopy& operator=(const MoveCopy& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] m_str;

		//아래 if else 예외처리 상황
	/*	•문자열이 있는 경우 : 안전하게 메모리를 새로 할당하고 복사
		•문자열이 없는 경우 : 불필요한 메모리 할당 없이 포인터를 nullptr로 설정
		→ 프로그램이 불필요한 메모리 접근 / 해제를 하지 않도록 방지*/

		if (other.m_str)
		{
			size_t len = strlen(other.m_str) + 1;
			m_str = new char[len];
			strcpy_s(m_str, len, other.m_str);
		}
		else
		{
			m_str = nullptr;
		}

		std::cout << "깊은복사 대입 연산자 호출 " << std::endl;
		return *this;

	}

	// 이동 생성자
/*  MoveCopy(MoveCopy&& other) noexcept
	  : m_idata(other.m_idata), m_str(other.m_str) {
	  other.m_str = nullptr;
	  other.m_idata = 0;
	  cout << "이동 생성자 호출" << endl;
  }*/

	MoveCopy(MoveCopy&& other) noexcept
		: m_idata(std::move(other.m_idata)), m_str(std::move(other.m_str))
	{
		// 임시 객체소멸시에 메모리를 해제하지 못하게한다
		other.m_str = nullptr;
		other.m_idata = 0;
		cout << "이동 생성자 호출" << endl;
	}


	// 이동 대입 연산자
  /*  MoveCopy& operator=(MoveCopy&& other) noexcept {
		if (this == &other) return *this;
		delete[] m_str;
		m_idata = other.m_idata;
		m_str = other.m_str;
		other.m_Str = nullptr;
		other.m_idata = 0;
		cout << "이동 대입 연산자 호출" << endl;
		return *this;
	}*/


	// 이동 대입 연산자 (move 사용)
	MoveCopy& operator=(MoveCopy&& other) noexcept
	{
		if (this == &other)
			return *this;
		delete[] m_str;
		m_idata = std::move(other.m_idata);
		//m_idata = static_cast<int&&>(other.m_idata);똑같은말
		m_str = std::move(other.m_str);
		// m_Str = static_cast<char*&&>(other.m_Str);똑같은말
		other.m_str = nullptr;
		other.m_idata = 0;
		cout << "이동 대입 연산자 호출" << endl;
		return *this;

	}

	void SetData(int data) {
		m_idata = data;
	}

	void SetName(const char* name) {
		delete[] m_str;
		size_t len = strlen(name) + 1;
		m_str = new char[len];
		strcpy_s(m_str, len, name);
	}

	int GetData() const {
		return m_idata;
	}

	const char* GetName() const {
		return m_str;
	}

	~MoveCopy() {
		delete[] m_str;
		cout << "소멸자 호출" << endl;
	}
};

int main()
{
	MoveCopy a;
	a.SetData(10);
	a.SetName("테스트");

	MoveCopy b(a); // 복사 생성자
	MoveCopy c = std::move(a); // 이동 생성자
	MoveCopy d;
	d = b; // 복사 대입 연산자
	d = static_cast<MoveCopy&&>(c); // 이동 대입 연산자

	cout << "a: " << a.GetData() << ", " << (a.GetName() ? a.GetName() : "null") << endl;
	cout << "b: " << b.GetData() << ", " << b.GetName() << endl;
	cout << "c: " << c.GetData() << ", " << (c.GetName() ? c.GetName() : "null") << endl;
	cout << "d: " << d.GetData() << ", " << d.GetName() << endl;

	return 0;
}