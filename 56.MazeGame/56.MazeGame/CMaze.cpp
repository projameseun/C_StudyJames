#include "CMaze.h"

CMaze::CMaze()
{
}

CMaze::~CMaze()
{
}

bool CMaze::Start(const char* pFileName)
{
	memset(m_strName, 0, 64);

	FILE* pFile = nullptr;

	fopen_s(&pFile, pFileName, "rt");

	if (!pFile)
	{
		perror("Failed to Open File");
		return false;
	}


	char cLine[256] = {};

	fgets(cLine, 256, pFile);

	//�ľ�
	//��ū�� ���������ؼ� ����ϴ� �Լ�
	// ������ ���� ���ǰ� �ʿ��ϰ� �����ü�� �������� �ʴ´�. 
	// hello strtok func !\0 �̰� strtok �Լ��� ����ϰ� �Ǹ�
	// hello\0strtok\0func\0!\0 �̷������� ��ȯ�� �ȴ� 
	// ���� �������� ���Ἲ�� �����ؾ� �Ǵ°�쿡�� ����� ����ؼ��� �ȵȴ�.
	// ���Ἲ�̶� �����ϰ� ��Ȯ�ϰ� ������� ���� ���¸� ���Ѵ�.
	// 
	//_ACRTIMP char* __cdecl strtok_s(
	//	_Inout_opt_z_                 char* _String,		�и��� ���ڿ��ּ� ù ȣ�⿡���� ���ڿ��� �����ּҸ� ���� ���� ȣ�⿡���� NULL�� �����Ͽ� ���� ȣ���� ���¸� �̾��
	//	_In_z_                        char const* _Delimiter,		������ ������� ,�� ��ǥ�� ���ڿ��� ������
	//	_Inout_ _Deref_prepost_opt_z_ char** _Context		���ڿ� �и� ���¸� �����ϴ� ������ 
	//);
	//strtok�� ���������� ���¸� �������� �ʴ´� ��� ȣ���ڰ� ������ context�� ����Ͽ� ���¸� �����Ѵ�.
	//�������� �غ��ϱ����� ����Ȱ��̰� �������ڿ��� ���ÿ� ó���ϰų� �����尣�� ������ �Լ� ȣ���� ����Ұ�쿡�� �����ϴ�.

	char* pContext = nullptr;
	char* pWidth = nullptr;
	char* pHeigth = nullptr;
	pWidth = strtok_s(cLine, ", ",&pContext);
	pHeigth = strtok_s(NULL, ", ", & pContext);
	m_iWidth = atoi(pWidth);
	m_iHeigth = atoi(pHeigth);

	m_pBlockOrigin = new char* [m_iHeigth];
	m_pBlock = new char* [m_iHeigth];

	for (int i = 0; i < m_iHeigth; ++i)
	{
		m_pBlockOrigin[i] = new char[m_iWidth];
		m_pBlock[i] = new char[m_iWidth];

		memset(cLine, 0, 256);

		fgets(cLine, 256, pFile);
		
		memcpy(m_pBlockOrigin[i], cLine, m_iWidth);	//�� ��ü
		memcpy(m_pBlock[i], cLine, m_iWidth);	//���� ����������� ���
		

		for (int j = 0; j < m_iWidth; ++j)
		{
			if ((BLOCK)m_pBlockOrigin[i][j] == BLOCK::START)
			{
				m_tStartPos.X = j;
				m_tStartPos.Y = i;
			}

			else if ((BLOCK)m_pBlockOrigin[i][j] == BLOCK::EXIT)
			{
				m_tExitPos.X = j;
				m_tExitPos.Y = i;
			}
		}
	}
	

	fclose(pFile);

	//�������߰�
	//�����߰� 

	strcpy_s(m_strName, pFileName);

	m_strName[strlen(pFileName) - 4] = 0;
	
	
	return true;
}

void CMaze::Render(char* pBuffer)
{
	int iCurrent = 0;

	for (int i = 0; i < m_iHeigth; ++i)
	{
		for (int j = 0; j < m_iWidth; ++j)
		{

			switch ((BLOCK)m_pBlock[i][j])
			{
			case BLOCK::ROAD:
				memcpy(&pBuffer[iCurrent], "  ", 2);
				break;
			case BLOCK::WALL:
				memcpy(&pBuffer[iCurrent], "��", 2);
				break;
			case BLOCK::START:
				memcpy(&pBuffer[iCurrent], "��", 2);
				break;
			case BLOCK::EXIT:
				memcpy(&pBuffer[iCurrent], "�� ", 2);
				break;
			}

			iCurrent += 2;
		}
		//���� 
		pBuffer[iCurrent] = '\n';
		++iCurrent;
	}

}
