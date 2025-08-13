#include <iostream>
#include <cstring>
#include <vector>

class MyString
{
	char* p_str;		//���ڿ� �����͸� ����Ű�� ������
	int		iLength;		//���ڿ� ����
	int		iCapacity;	//���� �Ҵ�� �뷮

public:
	MyString();

	//���ڿ��� ���� ����
	MyString(const char* _str);

	//���������
	MyString(const MyString& _obj);


	//�̵� ������ 
	MyString(MyString&& _obj) noexcept;


	MyString(MyString& _obj, bool shallow);

	MyString createString();

	~MyString();



};

MyString::MyString()
{
	std::cout << "������ ȣ�� !" << std::endl;
	iLength = 0;
	iCapacity = 0;
	p_str = nullptr;
}

MyString::MyString(const char* _str)
{
	std::cout << "������ ȣ�� !" << std::endl;
	iLength = strlen(_str);
	iCapacity = iLength;
	p_str = new char[iLength];

	for (int i = 0; i != iLength; ++i)
	{
		p_str[i] = _str[i];
	}

}

// ���� ���� ������ (Shallow Copy Constructor)
MyString::MyString(MyString& _obj, bool shallow)
{
	std::cout << "���� ���� ������ ȣ�� !" << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iCapacity;
	p_str = _obj.p_str; // �����͸� ���� (�޸� ����)
}

//���������
MyString::MyString(const MyString& _obj)
{
	std::cout << "���� ������ ȣ�� !" << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iLength;
	p_str = new char[iLength];

	for (int i = 0; i < iLength; ++i)
	{
		p_str[i] = _obj.p_str[i];
	}

}

//�̵� ������ 
MyString::MyString(MyString&& _obj) noexcept
{
	std::cout << "�̵� ������ ȣ�� ! " << std::endl;
	iLength = _obj.iLength;
	iCapacity = _obj.iCapacity;
	p_str = _obj.p_str;

	//�ӽ� ��ü�Ҹ�ÿ� �޸𸮸� �������� ���ϰ��Ѵ�
	//���࿡ nullptr�� �־����� �ʰԵǸ� �ӽð�ü�� ������� �Ҹ��ڸ� �ҷ����� �̶� 
	//�޸� ������ �ȴ�. 
	//�׷��� ���α׷� ����� ���������ѱ� data�� �����ɶ� �̹� ������ �ּ��̱⶧���� ��۸� �����Ͱ� �Ͼ��.
	_obj.p_str = nullptr;

}

MyString::~MyString()
{

	std::cout << "�Ҹ��� ȣ�� " << std::endl;
	if (p_str != nullptr)
	{
		delete[] p_str;
	}
}

//�ӽð�ü �����Ǵ»�Ȳ
//1.�Լ� ��ȯ��

MyString createString() {
	MyString s("abc");
	return s; // s�� ���纻(�ӽ� ��ü) �Ǵ� �̵�(�ӽ� ��ü)�� �������
}

//int main() {
//	MyString a = createString(); // �ӽ� ��ü�� a�� ����/�̵���
//}

//2�Լ� ����  ���� (������ ������)
//void printString(MyString s) {
//	// s�� ���� �����ڷ� ������� �ӽ� ��ü
//}
//
//int main() {
//	MyString a("abc");
//	printString(a); // a�� ���纻(�ӽ� ��ü)�� printString�� ���޵�
//}

//3.������ 
//MyString getSum(const MyString& a, const MyString& b) {
//	// �� ��ü�� ���ļ� ���ο� MyString ��ȯ
//	MyString result("ab");
//	return result; // result�� ���纻(�ӽ� ��ü) �Ǵ� �̵�(�ӽ� ��ü)
//}
//
//int main() {
//	MyString a("a"), b("b");
//	MyString c = getSum(a, b); // �ӽ� ��ü�� c�� ����/�̵���
//}

//4.ǥ�� �����̳ʿ� �� �߰�
//int main() {
//	MyString s("abc");
//	std::vector<MyString> vec;
//	vec.push_back(s); // s�� ���纻(�ӽ� ��ü)�� ���Ϳ� ��
//}

//5.���� �ӽ� ��ü ����
//int main() {
//	MyString a = MyString("abc"); // ������ MyString("abc")�� �ӽ� ��ü
//}

//6.������ �����ε� ���

//MyString operator+(const MyString& lhs, const MyString& rhs) {
//	MyString result("ab");
//	return result; // result�� ���纻(�ӽ� ��ü) �Ǵ� �̵�(�ӽ� ��ü)
//}
//
//int main() {
//	MyString a("a"), b("b");
//	MyString c = a + b; // �ӽ� ��ü�� c�� ����/�̵���
//}


int main()
{

	/*

	*/

	//MyString s("abc");
	//std::vector<MyString> vec;
	//std::cout << "ù ��° �߰� ---" << std::endl;
	//vec.push_back(static_cast<MyString&&>(s));
	//std::cout << "�� ��° �߰� ---" << std::endl;
	//vec.push_back(s);
	//std::cout << "�� ��° �߰� ---" << std::endl;
	//vec.push_back(std::move(s));
	MyString s("abc");
	std::vector<MyString> vec;
	std::cout << "ù ��° �߰� ---" << std::endl;
	vec.push_back(s);
	std::cout << "�� ��° �߰� ---" << std::endl;
	vec.push_back(s);
	std::cout << "�� ��° �߰� ---" << std::endl;
	vec.push_back(s);





	return 0;
}