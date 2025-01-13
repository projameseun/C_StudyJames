#pragma 
#include "Info.h"

//MIC -> Media Control Interface
class Music
{
private:
	MCI_OPEN_PARMS		m_MciOpen;	//파일을 로드
	MCI_PLAY_PARMS		m_MciPlay;	//파일을 재생
	MCI_STATUS_PARMS	m_MciStatus;	//파일의 상태

	UINT				m_iDeviceID = 0;		//재생위 위치값 0이면 처음으로 돌려줌
	DWORD				m_Result;			//결과값

	
	vector<string>		m_RecordName;
	LPCTSTR				m_MusicRoutue[25];


	bool bTrue = true;

public:
	void InitRecord();
	void SettingRecord(vector<string> _re);
	void MusicePlayMenuPrint();
	WORD InitMusiceDevice(LPCSTR _lpsz);
	

};

