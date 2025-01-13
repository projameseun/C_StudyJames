#pragma 
#include "Info.h"

//MIC -> Media Control Interface
class Music
{
private:
	MCI_OPEN_PARMS		m_MciOpen;	//������ �ε�
	MCI_PLAY_PARMS		m_MciPlay;	//������ ���
	MCI_STATUS_PARMS	m_MciStatus;	//������ ����

	UINT				m_iDeviceID = 0;		//����� ��ġ�� 0�̸� ó������ ������
	DWORD				m_Result;			//�����

	bool bMusic = false;
	bool bFlag = true;		//���������� �ִ� �ϴ� �÷���


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

