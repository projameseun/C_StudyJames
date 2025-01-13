#include "Music.h"



void Music::MusicePlayMenuPrint()
{
}

WORD Music::InitMusiceDevice(LPCSTR _lpsz)
{
	ZeroMemory(&m_MciOpen, sizeof(m_MciOpen));

	m_MciOpen.lpstrDeviceType = L"MPEGVideo";	//WaveAudio

	m_MciOpen.lpstrElementName = (LPCWSTR)_lpsz;

	m_Result = mciSendCommand(m_iDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&m_MciOpen);

	m_iDeviceID = m_MciOpen.wDeviceID;

	if (m_Result)

	{
		return m_Result;

	}
	else
	{
		std:cerr << "Error == >" << m_Result;
	}

	return 0;
	
	
}

void Music::InitRecord()
{
	//음악 레코드 넣기
	m_RecordName.push_back("TroyeSIvan");
	m_RecordName.push_back("Maroon5");
	m_RecordName.push_back("YouDaEn");
	m_RecordName.push_back("AnnerMarie");
	m_RecordName.push_back("JangBeomJun");
	m_RecordName.push_back("GyungSeo");
	m_RecordName.push_back("AllTimeLow");
	m_RecordName.push_back("OnePiece");
	m_RecordName.push_back("PostMalone");
	m_RecordName.push_back("SungSiKyung");
	
}


void Music::SettingRecord(vector<string> _re)
{
	for (int i = 0; i < _re.size(); ++i)
	{
		if (m_RecordName[i] == "TroyeSIvan")
		{

		}
	}

}
