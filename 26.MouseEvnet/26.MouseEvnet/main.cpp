
#include <iostream>
#include <Windows.h>

//���콺 �̺�Ʈ�Լ�

void ProcessMouseEvent(MOUSE_EVENT_RECORD re)
{
	switch (re.dwEventFlags)
	{
	case 0: //��ư���°� ����� ���
	{
		if (re.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			std::cout << "Left Button pressed" << std::endl;
			//std::cout << "Mouse moved to (" << re.dwMousePosition.X << ", " << re.dwMousePosition.Y << ")" << std::endl;
		}
		else if (re.dwButtonState & RIGHTMOST_BUTTON_PRESSED) 
		{
			std::cout << "Right button pressed" << std::endl;
		}
		else 
		{
			std::cout << "Button released" << std::endl;
		}
		break;
	}
	case MOUSE_MOVED: // ���콺 �̵�
		 std::cout << "Mouse moved to (" << re.dwMousePosition.X << ", " << re.dwMousePosition.Y << ")" << std::endl;
		break;

	default:
		break;
	}
}



int main()
{
	//Handle � Ű��� �����ص� ���� 
	//c++���� �پ��� ���ҽ�(����,������,�������)�� �����ϱ� ���� �ڵ��� ����Ѵ�.
	//�ڵ��� void*�� �����Ǿ� �ִ� . ������ void*�� �������� ����
	//������� �پ��� ���ҽ��� ���� �ٸ� Ÿ���� ���ҽ����ٵ� �̰� ��� �����ϰ� ó���Ҽ� �ִٴ� ������ �ִ�.

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD savemode;	//typedef unsigned long 

	//INVALID_HANDLE_VALUE�� WIndowAPI���� �߸��� �ڵ��� ��Ÿ���� ���� �����̴�.

	if (handle == INVALID_HANDLE_VALUE)
	{
		DWORD errorcode = GetLastError();
		std::cout << "Error input handle error code : " << errorcode << std::endl;
		
	
	}

	//�ָܼ�� ����
	if (!GetConsoleMode(handle, &savemode))
	{
		std::cout << "Get Console Mode Error " << std::endl;

	}
	//Ư�������̳� ���¸� ��Ÿ���� ������ �÷��׶�� �Ѵ�. ���� Bool���̳� bit�� ǥ���� ���̵ȴ�.
	
	//�ܼ� �Է¸�弳�� �÷��׵� 
	//ENABLE_EXTENDED_FLAGS //�÷����� Ȱ��ȭ�� �����ϰ� �ϴ� ���� 
	//
	//#define ENABLE_PROCESSED_INPUT              0x0001	Ư�� Ű ���� �ý���ó�� ex) Ctrl+C ���ձ�ɵ� ..
	//#define ENABLE_LINE_INPUT                   0x0002	����ڰ� EnterŰ�� ������ ���� �Է��� ���ۿ� ��ϵ��� �ʴ´�
	//#define ENABLE_ECHO_INPUT                   0x0004	�Է��� ���ڸ� �ܼ�ȭ�鿡 �����Ѵ� ���÷��װ� �������� �ʴ´ٸ� �Էµ� ���ڴ� ȭ�鿡 ǥ�õ��� �ʴ´�
	//#define ENABLE_WINDOW_INPUT                 0x0008	â �Է��� Ȱ��ȭ�Ҷ� �����Ǹ� �ܼ� �Է¹��۰� â ũ�� ���� �̺�Ʈ�� ����Ѵ�
	//#define ENABLE_MOUSE_INPUT                  0x0010	���콺 �Է� Ȱ��ȭ
	//#define ENABLE_INSERT_MODE                  0x0020	���� ��� Ȱ��ȭ 
	//#define ENABLE_QUICK_EDIT_MODE              0x0040	���� ������� Ȱ��ȭ
	//#define ENABLE_EXTENDED_FLAGS               0x0080	
	//#define ENABLE_AUTO_POSITION                0x0100	
	//#define ENABLE_VIRTUAL_TERMINAL_INPUT       0x0200

	//���콺 ��� ����
	DWORD mMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(handle, mMode))
	{
		std::cout << "Set Console Mode Error" << std::endl;
	}

	INPUT_RECORD pRecord[128];
	DWORD NumRe; //�ʱ�ȭ�� �о���ߵ�

	while (true)
	{
		//�Է� �̺�Ʈ �б�
		if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
		{
			std::cout << "Error ReadConsoleInput " << std::endl;
			system("Pause");
			break;
		}

		//�Է� �̺�Ʈ ó��
		for (DWORD i = 0; i < NumRe; ++i)
		{
			if (pRecord[i].EventType == MOUSE_EVENT)
			{
				//���콺 �̺�Ʈ ����
				ProcessMouseEvent(pRecord[i].Event.MouseEvent);
			}
		}
	
	}

	
	SetConsoleMode(handle, savemode);
	
	
	
	return 0;
}