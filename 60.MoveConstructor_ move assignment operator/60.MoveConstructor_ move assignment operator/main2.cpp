#include <iostream>

using namespace std;

class MoveCopy {
private:
    int m_idata;
    char* m_Str;

public:
    MoveCopy()
        : m_idata(0), m_Str(nullptr) {
        cout << "�⺻ ������ ȣ��" << endl;
    }

    // ���� ������ (���� ����)
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
        cout << "���� ������ ȣ��" << endl;
    }

    // ���� ���� ������ (���� ����)
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
        cout << "���� ���� ������ ȣ��" << endl;
        return *this;
    }

    // �̵� ������
  /*  MoveCopy(MoveCopy&& other) noexcept
        : m_idata(other.m_idata), m_Str(other.m_Str) {
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "�̵� ������ ȣ��" << endl;
    }*/

    MoveCopy(MoveCopy&& other) noexcept
        : m_idata(std::move(other.m_idata)), m_Str(std::move(other.m_Str))
    {
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "�̵� ������ ȣ��" << endl;
    }


    // �̵� ���� ������
  /*  MoveCopy& operator=(MoveCopy&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_Str;
        m_idata = other.m_idata;
        m_Str = other.m_Str;
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "�̵� ���� ������ ȣ��" << endl;
        return *this;
    }*/

    // �̵� ���� ������ (move ���)
    MoveCopy& operator=(MoveCopy&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_Str;
        m_idata = std::move(other.m_idata);
        m_Str = std::move(other.m_Str);
        other.m_Str = nullptr;
        other.m_idata = 0;
        cout << "�̵� ���� ������ ȣ��" << endl;
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
        cout << "�Ҹ��� ȣ��" << endl;
    }
};

int main() {
    MoveCopy a;
    a.SetData(10);
    a.SetName("�׽�Ʈ");

    MoveCopy b(a); // ���� ������
    MoveCopy c = std::move(a); // �̵� ������
    MoveCopy d;
    d = b; // ���� ���� ������
    d = static_cast<MoveCopy&&>(c); // �̵� ���� ������

    cout << "a: " << a.GetData() << ", " << (a.GetName() ? a.GetName() : "null") << endl;
    cout << "b: " << b.GetData() << ", " << b.GetName() << endl;
    cout << "c: " << c.GetData() << ", " << (c.GetName() ? c.GetName() : "null") << endl;
    cout << "d: " << d.GetData() << ", " << d.GetName() << endl;

    return 0;
}