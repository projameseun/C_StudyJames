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

	
	vector<string>		m_RecordName;
	LPCTSTR				m_MusicRoutue[25];


	bool bTrue = true;

public:
	void InitRecord();
	void SettingRecord(vector<string> _re);
	void MusicePlayMenuPrint();
	WORD InitMusiceDevice(LPCSTR _lpsz);
	

};

