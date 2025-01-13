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

	bool bMusic = false;
	bool bFlag = true;		//음악을껏다 켯다 하는 플래그


	vector<LPCWSTR>		m_RecordName;
	vector<LPCWSTR>		m_RecordPath;

	bool bTrue = true;

public:
	const vector<LPCWSTR>& GetRecordName() const
	{
		return m_RecordName;
	}

	const vector<LPCWSTR>& GetRecordPath() const
	{
		return m_RecordPath;
	}

public:
	void InitRecordName();
	void SettingRecordPath(vector<LPCTSTR> _re);
	void MusicePlayMenuPrint();
	WORD InitMusiceDevice(LPCWSTR& _lpsz);

	void UpdateMusic(int _ReNum);
	void DestroyMusic();
	void PauseMusic(int _ReNum);
	void PlayMusic(int _ReNum);
	void ResetMusic(int _ReNum);
	
	

};

