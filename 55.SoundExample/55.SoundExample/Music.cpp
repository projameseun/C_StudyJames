#include "Music.h"



void Music::MusicePlayMenuPrint()
{
	system("cls");
	std::cout << "안녕하세요 JamesLon 음악프로그램 입니다" << std::endl;
	std::cout << "원하는 노래의 번호를 선택해주세요 " << std::endl;

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

	//DWORD_PTR 64비트 DWORD32비트 
	m_Result = mciSendCommand(m_iDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)(LPVOID)&m_MciOpen);

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

	//맨 앞숫자는 재생번호이다 
	if (m_Result == 0)
	{
		bMusic = true;



	}

	while (bMusic)
	{
		system("cls");
		MusicePlayMenuPrint();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		std::wcout << m_RecordName[iReNumber - 1] << "  실행중입니다" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		std::cout << "다른 노래를 재생하실려면 번호를 입력해주세요" << std::endl;
		std::cout << "프로그램을 종료하실려면 99를 입력해주세요 " << std::endl;
		std::cout << "일시정지하고 다시 킬려면 11을 입력해주세요 " << std::endl;

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
				//정지
				PauseMusic(iReNumber);
			}
			else
			{
				//플레이
				PlayMusic(iReNumber);
			}

			continue;
			
		}


		else if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "선택을 잘못하였습니다 다시 선택해주세요 " << std::endl;
			Sleep(500);
			continue;
		}
		
		ResetMusic(_ReNum);
		
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

void Music::InitRecordName()
{
	//음악 레코드 넣기
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


void Music::SettingRecordPath(vector<LPCTSTR> _re)
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

	//실제 음악을 초기화를해준다
	/*for (int i = 0; i < m_RecordName.size(); ++i)
	{
		InitMusiceDevice(m_RecordPath[i]);

	}*/

}
