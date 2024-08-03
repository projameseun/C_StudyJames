#include <iostream>
#include <string>
#pragma warning (disable : 4996)


void MyEndl()
{
	printf("\n");
	fflush(stdout);
}





namespace MyStd
{


	class MyOStream
	{


	public:
	

		MyOStream& operator << (int _idata)
		{
			printf("%d", _idata);
			return *this;
		}
		
		

		MyOStream& operator << (const char* _pString)
		{
			printf("%s",_pString);

			return *this;
		}



		MyOStream& operator << (const std::string& _string)
		{
			printf("%s", _string.c_str());
			return *this;
		}

		
		MyOStream& operator <<(MyOStream& (*func)(MyOStream&))
		{
			return func(*this);
		}
	
		/*MyOStream& operator << (void(*_Func)(void))
		{
			_Func();
			return *this;
		}*/

		
		
		
	};

	MyOStream& endl(MyOStream& _ptr)
	{
		std::printf("\n");
		std::fflush(stdout);
		return _ptr;
	}
	


	//입력
	class MyIStream
	{

	public:
		MyIStream& operator >> (int& _idata)
		{
			scanf_s("%d",&_idata);
			return *this;
		}

		MyIStream& operator>>(char& _cstring)
		{
			
			scanf_s("%s", &_cstring,25); 
			return *this;
		}

		MyIStream& operator>>(char* _ptr)
		{
			scanf_s("%s", _ptr,25);
			return *this;
		}

		MyIStream& operator>>(std::string& _string)
		{
			
			char buffer[1024];
			scanf_s("%s", buffer,1024);
			_string = buffer;
			return *this;
		}

		


	};
	

	MyStd::MyOStream mycout;

	MyStd::MyIStream mycin;
}





class Test
{
public:
	static void Attack()
	{

	}
};

int main()
{
	std::cout << "test" << std::endl;

	MyStd::mycout << "test" << MyStd::endl;

	

	
	int a = 0;
	int b = 300;

	char c[25];
	std::string str;

	MyStd::mycin >> c;

	MyStd::mycout << c << " " << b << " " << MyStd::endl;
	
	MyStd::mycin >> str;

	MyStd::mycout << str << " " << 500 << " " << MyStd::endl;
	
	std::printf("Hello, ");
	std::fflush(stdout); // 이 시점에서 "Hello, "를 즉시 출력합니다.

	// 다른 작업을 수행한 후
	std::printf("world!\n");

	
	return 0;
}