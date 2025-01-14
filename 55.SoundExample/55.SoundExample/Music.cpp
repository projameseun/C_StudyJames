#include "Music.h"



void Music::MusicePlayMenuPrint()
{
	system("cls");
	std::cout << "�ȳ��ϼ��� JamesLon �������α׷� �Դϴ�" << std::endl;
	std::cout << "���ϴ� �뷡�� ��ȣ�� �������ּ��� " << std::endl;

	for (int i = 0; i < m_RecordName.size(); ++i)
	{
		std::wcout << i + 1 << " . " << m_RecordName[i] << std::endl;
	}
	
}

WORD Music::InitMusiceDevice(LPCWSTR& _lpsz)
{
	ZeroMemory(&m_MciOpen, sizeof(m_MciOpen));

	m_MciOpen.lpstrDeviceType = L"MPEGVideo";	//WaveAudio

	m_MciOpen.lpstrElementName = _lpsz;

	//DWORD_PTR 64��Ʈ DWORD32��Ʈ 
	m_Result = mciSendCommand(m_MciOpen.wDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)(LPVOID)&m_MciOpen);

	m_iDeviceID = m_MciOpen.wDeviceID;

	if (m_Result == 0)

	{
		return m_Result;

	}
	else
	{
		std:cerr << "Error == >" << m_Result;
	}

	return 0;
	
	
}

void Music::UpdateMusic(int _ReNum)
{
	int iReNumber = 0;
	iReNumber = _ReNum;

	m_Result = mciSendCommand(iReNumber, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)(LPVOID)&m_MciPlay);

	//�� �ռ��ڴ� �����ȣ�̴� 
	if (m_Result == 0)
	{
		bMusic = true;



	}

	while (bMusic)
	{
		system("cls");
		MusicePlayMenuPrint();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		std::wcout << m_RecordName[iReNumber - 1] << "  �������Դϴ�" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		std::cout << "�ٸ� �뷡�� ����ϽǷ��� ��ȣ�� �Է����ּ���" << std::endl;
		std::cout << "���α׷��� �����ϽǷ��� 99�� �Է����ּ��� " << std::endl;
		std::cout << "�Ͻ������ϰ� �ٽ� ų���� 11�� �Է����ּ��� " << std::endl;

		int iSelect = 0;

		std::cin >> iSelect;

	

		if (iSelect == 99)
		{
			DestroyMusic();
			bMusic = false;
		}

		else if (iSelect == 11)
		{
			bFlag = !bFlag;
			if (bFlag == false)
			{
				//����
				PauseMusic(iReNumber);
			}
			else
			{
				//�÷���
				PlayMusic(iReNumber);
			}

			continue;
			
		}


		else if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "������ �߸��Ͽ����ϴ� �ٽ� �������ּ��� " << std::endl;
			Sleep(500);
			continue;
		}
		
		ResetMusic(_ReNum);
		UpdateMusic(iSelect);
		
	}

}

void Music::DestroyMusic()
{
	
	if (m_iDeviceID > 0)
	{
		for (int i = 0; i < 20; ++i)
		{
			mciSendCommand(i, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
		}
	}
}

void Music::PauseMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_PAUSE, MCI_SEEK_TO_START, (DWORD_PTR)(LPVOID)NULL);
}

void Music::PlayMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)(LPVOID)&m_MciPlay);
}

void Music::ResetMusic(int _ReNum)
{
	mciSendCommand(_ReNum, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)(LPVOID)NULL);
}

void Music::ShuffuleMusic()
{
	int idx1, idx2 = 0;

	LPCWSTR strTemp;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 10;
		idx2 = rand() % 10;

		strTemp = m_RecordName[idx1];
		m_RecordName[idx1] = m_RecordName[idx2];
		m_RecordName[idx2] = strTemp;
	}
}

void Music::InitRecordName()
{
	//���� ���ڵ� �ֱ�
	m_RecordName.push_back(L"TroyeSIvan");
	m_RecordName.push_back(L"Maroon5");
	m_RecordName.push_back(L"YouDaEn");
	m_RecordName.push_back(L"AnnerMarie");
	m_RecordName.push_back(L"JangBeomJun");
	m_RecordName.push_back(L"GyungSeo");
	m_RecordName.push_back(L"AllTimeLow");
	m_RecordName.push_back(L"OnePiece");
	m_RecordName.push_back(L"PostMalone");
	m_RecordName.push_back(L"SungSiKyung");
	
}


void Music::InitSettingRecordPath(vector<LPCTSTR> _re)
{
	for (int i = 0; i < _re.size(); ++i)
	{

		switch (MusicNumber(i+1))
		{
		case MusicNumber::TroyeSIvan:
			m_RecordPath.push_back(L".\\Music\\seventeen.mp3");
			break;
		case MusicNumber::Maroon5:
			m_RecordPath.push_back(L".\\Music\\Memories.mp3");
			break;
		case MusicNumber::YouDaEn:
			m_RecordPath.push_back(L".\\Music\\jisang.mp3");
			break;
		case MusicNumber::AnnerMarie:
			m_RecordPath.push_back(L".\\Music\\2002.mp3");
			break;
		case MusicNumber::JangBeomJun:
			m_RecordPath.push_back(L".\\Music\\jangbumzun.mp3");
			break;
		case MusicNumber::GyungSeo:
			m_RecordPath.push_back(L".\\Music\\gyungseo.mp3");
			break;
		case MusicNumber::AllTimeLow:
			m_RecordPath.push_back(L".\\Music\\timebomb.mp3");
			break;
		case MusicNumber::OnePiece:
			m_RecordPath.push_back(L".\\Music\\onepiece.mp3");
			break;
		case MusicNumber::PostMalone:
			m_RecordPath.push_back(L".\\Music\\postmalone.mp3");
			break;
		case MusicNumber::SungSiKyung:
			m_RecordPath.push_back(L".\\Music\\sungsikyung.mp3");
			break;
		default:
			break;
		}
	}

	//���� ������ �ʱ�ȭ�����ش�
	/*for (int i = 0; i < m_RecordName.size(); ++i)
	{
		InitMusiceDevice(m_RecordPath[i]);

	}*/

}

void Music::SettingRecordPath(vector<LPCTSTR> _re)
{
		m_RecordPath.clear();


	for (int i = 0; i < _re.size(); ++i)
	{


		if (_re[i] == L"TroyeSIvan")
		{
			m_RecordPath.push_back(L".\\Music\\seventeen.mp3");
		}
		else if (_re[i] == L"Maroon5")
		{
			m_RecordPath.push_back(L".\\Music\\Memories.mp3");
		}
		else if (_re[i] == L"YouDaEn")
		{
			m_RecordPath.push_back(L".\\Music\\jisang.mp3");
		}
		else if (_re[i] == L"JangBeomJun")
		{
			m_RecordPath.push_back(L".\\Music\\jangbumzun.mp3");
		}
		else if (_re[i] == L"GyungSeo")
		{
			m_RecordPath.push_back(L".\\Music\\gyungseo.mp3");
		}
		else if (_re[i] == L"AllTimeLow")
		{
			m_RecordPath.push_back(L".\\Music\\timebomb.mp3");
		}
		else if (_re[i] == L"OnePiece")
		{
			m_RecordPath.push_back(L".\\Music\\onepiece.mp3");
		}
		else if (_re[i] == L"PostMalone")
		{
			m_RecordPath.push_back(L".\\Music\\postmalone.mp3");

		}
		else if (_re[i] == L"AnnerMarie")
		{
			m_RecordPath.push_back(L".\\Music\\2002.mp3");
		}
		else if (_re[i] == L"SungSiKyung")
		{
			m_RecordPath.push_back(L".\\Music\\sungsikyung.mp3");
		}

	}

	int a = 0;
}

