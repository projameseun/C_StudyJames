#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

class ConsoleDoubleBuffer
{

private:
	HANDLE m_Buffer[2];		//HANDLE�� �����쿡�� ���Ǵ� �ڵ��� ��Ÿ���� ���������̴�. �ڵ��� �����쿡�� ���Ǵ� ��ü�� �ĺ��ϴµ� ���ȴ�. �����Ϳ� ������ ������ �Ѵ�
	int m_iActiveBuffer;	//���� Ȱ��ȭ�� �����ε���
	int m_iWidth;
	int m_iHeight;
							//������ ����
						/*
							1.�޸� ���� ����
							�����͸� �Ͻ������� �����ϴ� �޸� �����̴�.
							�������� ����� �ӵ��� �����ϰ� �������� �ϰ����� �����ϸ�, ȿ������ ������ ó���� �����ϰ� �Ѵ�.
							InputOutput ,��Ʈ��ũ���,�׷��� ������ ��� ���ȴ�.
						
							2.ȭ�����
							�ܼ� ���ø����̼ǿ��� ȭ�鿡 ����� �ؽ�Ʈ�� �׷��ȵ����͸� �ӽ÷� �����ϴ� �޸𸮰����̴�.
							ȭ�鿡 ǥ�õ� ������ �����ϰ� ������۸��� ���� ȭ�� �������� ���δ�.
						*/

public:
	ConsoleDoubleBuffer(int _width, int _height) :
		m_iWidth(_width), m_iHeight(_height) ,m_iActiveBuffer(0)
	{


		//���� ����
		//CreateConsoleScreenBuffer -> win api���� �����ϴ� �Լ��ν�, ���ο� �ܼ� ȭ�� ���۸� �����ϴ� ������ �Ѵ�.
		//�� �Լ��� �ܼ������ �����Ҽ� �ִ� ��ũ�����۸� ����� �ȴ� ,�ֿܼ��� �׷��� �׸��ų� �ؽ�Ʈ����Ҷ� ���ȴ�.
		//	���ڵ鼳��----
		//	_In_ DWORD dwDesiredAccess,	���ۿ� ���� �׼��� �������� GENERIC_READ | GENERIC_WRITE �б�,���� ������ �ο�
		//	_In_ DWORD dwShareMode, ���ۿ����� ��������ε� �Ϲ������� 0�� ����Ѵ�
		//	_In_opt_ CONST SECURITY_ATTRIBUTES * lpSecurityAttributes, ���ȼӼ��� �����ϴ� ����ü�� ���� �������̴� ���� NULL�� ����Ѵ�
		//	_In_ DWORD dwFlags, ������ ������ �����ϴ��÷��� �Ϲ������� CONSOLE_TEXTMODE_BUFFER ����Ͽ� �ؽ�Ʈ ��� ���۸� �����Ѵ� 
		//	_Reserved_ LPVOID lpScreenBufferData	���۵����Ϳ� ���� ������ ���� NULL�� �����Ѵ� 
		//	��ȯ��===> ������, �Լ��� ���ο� �ܼ� ȭ�� ���ۿ� ���� �ڵ��� ��ȯ�Ѵ�
		//			   ���� ��, INVALID_HANDLE_VALUE(��ȿ���� �ʴ� �ڵ�)�� ��ȯ�ϸ�, ������ ���� �ڼ��� ������ GetLastError �Լ��� ���� ���� �� �ֽ��ϴ�.

		//	CreateConsoleScreenBuffer�Լ��� ��ȯ�� �ڵ��� ����Ͽ� �ؽ�Ʈ�� ����Ϸ��� WriteConsoleOutputCharacterA �� ����Ͽ� �ܼ� ȭ�� ���ۿ� �ؽ�Ʈ�� �����ִ�.
		

		//for (int i = 0; i < 2; ++i)
		//{
		//	m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		//	//�ܼ�ȭ�� ũ�⼳��
		//	COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
		//	SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
		//	
		//	
		//	SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);
		//	//SetConsoleScreenBufferSize�Լ��� ����Ͽ� �ܼ�ȭ�� ������ũ�⸦ �����ϸ�,�ܼ�â�� ũ��� �ڵ����� ������� �ʴ´�. ����� �ܼ� ȭ�� ������ ũ��� �ܼ�â�� ũ��� �����̴�.
		//	//�ܼ�ȭ�� ����:�ֿܼ��� ����� �ؽ�Ʈ��,�׷��� �����͸� �����ϴ� �޸� �����̴�. ������ ũ��� ȭ�鿡 ǥ�� �ɼ� �ִ� ��ü ������ ũ�⸦ ���Ѵ�.

		//	SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);	//�ܼ�â�� ũ�⸦ �����ϴ� �Լ�

		//}

		//�ڵ� ���� ����ó��
		//	1.	���� �߻� (throw): ���ܰ� �߻��ϸ� throw Ű���带 ����Ͽ� ���� ��ü�� �����ϴ�.
		//	2.	���� ó��(catch) : ���ܰ� �߻��� �Լ��� ȣ�� ���� ������ �Լ����� catch ����� ����Ͽ� ���ܸ� ó���մϴ�.
		//	3.	���� ��ó�� : ���� ���ܸ� ó���� catch ����� ������, ���α׷��� ������������ ����˴ϴ�.
		for (int i = 0; i < 2; ++i)
		{
			
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			if (m_Buffer[i] == INVALID_HANDLE_VALUE)
			{
				throw std::runtime_error("�����߽��ϴ�.");
			}
			// �տ� t�� type�� ���ڷ� �Ϲ������� ����ü�� Ŭ������ �ν��Ͻ� ��Ÿ���� ���
			COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
			if(!SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize))
			{
				int iError = GetLastError();
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("�����߽��ϴ�.");
			}
			SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
			if (!SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect))
			{
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("�����߽��ϴ�.");
			}


		}

		
	}

	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer[i]);
		}
	}

	void Clear()
	{
		//���۸� �ʱ�ȭ�Ͽ� ȭ���� �����
		DWORD	dwWritten;
		COORD	coord = {0,0};
		FillConsoleOutputCharacter(m_Buffer[m_iActiveBuffer], ' ', m_iWidth * m_iHeight, coord, &dwWritten);	//������ ���ڷ� ä��� 
		FillConsoleOutputAttribute(m_Buffer[m_iActiveBuffer], FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, m_iWidth * m_iHeight, coord, &dwWritten);	//������
	}
	
	void Draw(int x, int y, const std::string& str)
	{
		//�����ؽ�Ʈ���
		COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
		DWORD dwWritten;

		//������ �ܼ� ȭ�� ������ Ư����ġ�� �ؽ�Ʈ�� ����ϴ� �����̴� ���� ȭ�鿡 �ٷ���µǴ°��̾ƴ϶� �츮�� ���� ȭ�� ���ۿ� �ؽ�Ʈ�� �����ϴ°Ŵ�
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), coord, &dwWritten);

	}

	void PresentBufferOutPut()
	{
		//������ �ܼ�ȭ�� ���۸� Ȱ��ȭ�ϸ�,�ش� ������ ������ �ܼ�â�� ǥ���ϴ� ����. ���� �ܼ�ȭ�� ���� �� �ϳ��� �����Ͽ� ���� Ȱ��ȭ�� ���۷� ����
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);	
		m_iActiveBuffer = 1 - m_iActiveBuffer;	//, �������۸� �غ�
	}
};

int main()
{

	// �ܼ� â�� ũ�⸦ ���� (�ʺ� 120, ���� 30)
	system("mode con: cols=100 lines=50");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
	{
		std::cerr << "GetStdHandle failed with error " << GetLastError() << std::endl;
		return 0;
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		std::cerr << "GetConsoleScreenBufferInfo failed with error " << GetLastError() << std::endl;
		return 0;
	}

	int iWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int iHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	//const int iWidth = 100;
	//const int iHeight = 50;



	

	//ConsoleDoubleBuffer console(width, height);

	//while (true)
	//{
	//	//�ܼ� ���� ȭ�� ����
	//	console.Clear();
	//	

	//	//�ؽ�Ʈ ���� Ȱ��ȭ�� �������
	//	console.Draw(0, 0, "Flickering");

	//	//���۸� �ֿܼ� ǥ���ϰ� ��������Ȱ��ȭ
	//	console.Present();

	//	//std::this_threa
	//	//std::cout << "Flickering" << std::endl;
	//	//�����̴� ������ Flickering �����̶�� �Ѵ� (�����Ͱ���)
	//	//�� ������ �������ؼ��� �ܼ� ȭ�� ����2���� �̿��Ͽ� ���� ���۸��� �����ؾ� �ȴ�.

	//	  // ������ �ӵ� ���� (��: 60 FPS)
	//	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	//}

	try {
		ConsoleDoubleBuffer console(iWidth, iHeight);
		while (true)
		{
			console.Clear();
			console.Draw(0, 0, "Flickering");
			console.PresentBufferOutPut();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			
		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}