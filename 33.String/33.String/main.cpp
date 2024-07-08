#include <iostream>
#include <assert.h>

unsigned int GetLength(const wchar_t* pwChar)
{
	int i = 0;

	/*while (true)
	{
		wchar_t c = *(pwChar + i);
		
		if ('\0' == c)
		{
			break;
		}

		++i;
	}*/

	while ('\0' != pwChar[i])
	{
		++i;
	}

	return i;
}

size_t GetLength2(const wchar_t* pwChar)
{
	size_t len = 0;

	while (*pwChar++)
	{
		
		len++;

	}

	return len;
}



void StrCat(wchar_t* _Destination, size_t _BufferSize, const wchar_t* _Source)
{
	size_t iDestSize = GetLength(_Destination);
	size_t iSourceSize = GetLength(_Source);



	if (_BufferSize < iDestSize + iSourceSize + 1)	//NULL
	{
		assert(nullptr);
	}

	//문자열 붙이기 
	//1.목적지에 문자열의 끝을 확인(그쪽 뒤에 문자열을 붙일거니까)
	//2.소스위치문자열을 목적지 끝에 붙여준다.

	for (int i = 0; i < iSourceSize + 1; ++i)
	{
		_Destination[iDestSize + i] = _Source[i];
	}
}

char* StrCat2(char* dest, const char* src)
{
	char* result = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = '\0';

	return result;
}

int main()
{
	//c++에서는 문자열은 문자의 배열로 표현이됩니다.
	

	wchar_t stwChar[25] = L"abcdef";	//{a,b,c,d,e,f};
	

	//문자열 길이를 반환해주는 함수를 우리가 직접만들어보자
	{
		wchar_t stName[25] = L"World!gg";
		//size_t
	
		size_t Len = GetLength(stName);
		size_t Len2 = GetLength(stName);
		std::cout << Len << std::endl;

	}

	//문자열 이어붙이기
	{
		wchar_t stName[100] = L"Hellow";
		wchar_t stName2[100] = L"Word";

		/*_Inout_updates_z_(_SizeInWords) wchar_t* _Destination,
			_In_ rsize_t _SizeInWords,
			_In_z_ wchar_t const* _Source*/
	/*	wcscat_s(stName, 100, stName2);

		size_t Len = GetLength(stName);

		for (int i = 0; i < Len; ++i)
		{
			std::wcout <<  stName[i];
		}*/

		std::wcout << std::endl;
		StrCat(stName, 100, stName2);

		std::wcout << stName << std::endl;

		char cName[100] = "안녕하세요";
		char cName2[100] = " 만냥이입니다";

		StrCat2(cName, cName2);

		std::cout << cName << std::endl;
	
	}

	{
		//문자열이 둘이 같으면 0 
		// cName이 cName2보다 작은경우 음수 -1
		// cName이 cName2보다 큰경우 양수 +1
		//결론적으로 우열이 왼쪽이 높으면 양수+1  오른쪽 높으면 음수 -1
		char cName[100] = "ff";
		char cName2[100] = "fff";
		int Test = strcmp(cName, cName2);

		int a = 0;

	}

	

	return 0;
}
