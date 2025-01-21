#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
class ConsoleDoubleBuffer
{

private:


	HANDLE m_Buffer[2];
	int m_iActiveBuffer;	//���� Ȱ��ȭ�� �����ε���
	int m_iWidth;
	int m_iHeight;


public:
	ConsoleDoubleBuffer(int _width, int _height) :
		m_iWidth(_width), m_iHeight(_height) ,m_iActiveBuffer(0)
	{


		//���� ����
		//CreateConsoleScreenBuffer -> win api���� �����ϴ� �Լ��ν�, ���ο� �ܼ� ȭ�� ���۸� �����ϴ� ������ �Ѵ�.
		//�� �Լ��� �ܼ������ �����Ҽ� �ִ� ��ũ�����۸� ����� �ȴ� ,�ֿܼ��� �׷��� �׸��ų� �ؽ�Ʈ����Ҷ� ���ȴ�.
		//CreateConsoleScreenBuffer(
		//	_In_ DWORD dwDesiredAccess,	���ۿ� ���� �׼��� �������� GENERIC_READ | GENERIC_WRITE �б�,���� ������ �ο�
		//	_In_ DWORD dwShareMode, ���ۿ����� ��������ε� �Ϲ������� 0�� ����Ѵ�
		//	_In_opt_ CONST SECURITY_ATTRIBUTES * lpSecurityAttributes, ���ȼӼ��� �����ϴ� ����ü�� ���� �������̴� ���� NULL�� ����Ѵ�
		//	_In_ DWORD dwFlags, ������ ������ �����ϴ��÷��� �Ϲ������� CONSOLE_TEXTMODE_BUFFER ����Ͽ� �ؽ�Ʈ ��� ���۸� �����Ѵ� 
		//	_Reserved_ LPVOID lpScreenBufferData	���۵����Ϳ� ���� ������ ���� NULL�� �����Ѵ� 

		for (int i = 0; i < 2; ++i)
		{
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			//�ܼ�ȭ�� ũ�⼳��
			COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
			SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
			SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);
			SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);

		}
		
	}

	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer);
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

		//WriteConsoleOutputCharacterA �ܼ� ȭ�� ���ۿ� ���� �ؽ�Ʈ�� ���� ������ �ϸ�, �̸� ������ �ܼ� ȭ�鿡 ���̰� �Ϸ��� ���۸� Ȱ��ȭ ����ߵȴ�.
		//SetConsoleActiveScreenBuffer Ȱ��ȭ����
		//�߿��Ѱ� ȭ�鿡 ���������� �ʰ� ���ۿ��� �����ϰ��ִ°Ŵ� ���� ���´�
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), coord, &dwWritten);

	}

	void Present()
	{
		//���� ���۸� Ȱ��ȭ�ϰ� 
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);
		m_iActiveBuffer = 1 - m_iActiveBuffer;	//, �������۸� �غ�
	}
};

int main()
{
	const int width = 100;
	const int height = 100;

	ConsoleDoubleBuffer console(width, height);

	while (true)
	{
		//�ܼ� ���� ȭ�� ����
		console.Clear();
		

		//�ؽ�Ʈ ���� Ȱ��ȭ�� �������
		console.Draw(0, 0, "Flickering");

		//���۸� �ֿܼ� ǥ���ϰ� ��������Ȱ��ȭ
		console.Present();

		//std::this_threa
		//std::cout << "Flickering" << std::endl;
		//�����̴� ������ Flickering �����̶�� �Ѵ� (�����Ͱ���)
		//�� ������ �������ؼ��� �ܼ� ȭ�� ����2���� �̿��Ͽ� ���� ���۸��� �����ؾ� �ȴ�.

		  // ������ �ӵ� ���� (��: 60 FPS)
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}