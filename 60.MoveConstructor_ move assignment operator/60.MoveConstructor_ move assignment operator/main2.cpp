#include <iostream>

using namespace std;

class MoveCopy {
private:
    int m_idata;
    char* m_Str;

public:
    MoveCopy()
        : m_idata(0), m_Str(nullptr) {
        cout << "기본 생성자 호출" << endl;
    }

    // 복사 생성자 (깊은 복사)
    MoveCopy(const MoveCopy& other)
        : m_idata(other.m_idata) {
        if (other.m_Str) {
            size_t len = strlen(other.m_Str) + 1;
            m_Str = new char[len];
            strcpy_s(m_Str, len, other.m_Str);
        }
        else {
            m_Str = nullptr;
        }
        cout << "복사 생성자 호출" << endl;
    }

    // 복사 대입 연산자 (깊은 복사)
    MoveCopy& operator=(const MoveCopy& other) {
        if (this == &other) return *this;
        m_idata = other.m_idata;
        delete[] m_Str;
        if (other.m_Str) {
            size_t len = strlen(other.m_Str) + 1;
            m_Str = new char[len];
            strcpy_s(m_Str, len, other.m_Str);
        }
        else {
            m_Str = nullptr;
        }
        cout << "복사 대입 연산자 호출" << endl;
        return *this;
    }

    // 이동 생성자
  /*  MoveCopy(MoveCopy&& other) noexcept
        : m_idata(other.m_idata), m_Str(other.m_Str) {
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "이동 생성자 호출" << endl;
    }*/

    MoveCopy(MoveCopy&& other) noexcept
        : m_idata(std::move(other.m_idata)), m_Str(std::move(other.m_Str))
    {
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "이동 생성자 호출" << endl;
    }


    // 이동 대입 연산자
  /*  MoveCopy& operator=(MoveCopy&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_Str;
        m_idata = other.m_idata;
        m_Str = other.m_Str;
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "이동 대입 연산자 호출" << endl;
        return *this;
    }*/

    // 이동 대입 연산자 (move 사용)
    MoveCopy& operator=(MoveCopy&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_Str;
        m_idata = std::move(other.m_idata);
        m_Str = std::move(other.m_Str);
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "이동 대입 연산자 호출" << endl;
        return *this;
    }
    void SetData(int data) {
        m_idata = data;
    }

    void SetName(const char* name) {
        delete[] m_Str;
        size_t len = strlen(name) + 1;
        m_Str = new char[len];
        strcpy_s(m_Str, len, name);
    }

    int GetData() const {
        return m_idata;
    }

    const char* GetName() const {
        return m_Str;
    }

    ~MoveCopy() {
        delete[] m_Str;
        cout << "소멸자 호출" << endl;
    }
};

int main() {
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