#include "CMaze.h"


CMaze::CMaze()
{
}

CMaze::~CMaze()
{
//#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }	

	for (int i = 0; i < m_iHeight; ++i)
	{
		if (m_pBlock[i])
		{
			delete[] m_pBlock[i];
			m_pBlock[i] = nullptr;
		}
		
		SAFE_DELETE_ARRAY(m_pBlockOrigin[i]);
	}
	
	if (m_pBlock)
	{
		delete[] m_pBlock;
		m_pBlock = nullptr;
	}

	SAFE_DELETE_ARRAY(m_pBlockOrigin);
	

	//SAFE_DELETE_ARRAY(m_pItemArray);

	//2차원배열 해제 방법 
		// 🔥 2차원 배열 삭제 (각 행을 먼저 삭제 후, 배열 포인터 자체를 삭제)
//	for (int i = 0; i < rows; ++i) {
//		delete[] arr[i];  // 각 행을 삭제
//		arr[i] = nullptr;  // 포인터를 nullptr로 설정
//	}
//
//	delete[] arr;  // 배열 포인터 자체를 삭제
//	arr = nullptr;  // 포인터를 nullptr로 설정
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

	//파씽
	//토큰을 나누기위해서 사용하는 함수
	// 굉장히 많은 주의가 필요하고 사용자체를 권장하지 않는다. 
	// hello strtok func !\0 이걸 strtok 함수를 사용하게 되면
	// hello\0strtok\0func\0!\0 이런식으로 변환이 된다 
	// 원본 데이터의 무결성을 보장해야 되는경우에는 절대로 사용해서는 안된다.
	// 무결성이란 간단하게 정확하고 변경되지 않은 상태를 말한다.
	// 
	//_ACRTIMP char* __cdecl strtok_s(
	//	_Inout_opt_z_                 char* _String,		분리할 문자열주소 첫 호출에서는 문자열의 시작주소를 전달 이후 호출에서는 NULL을 전달하여 이전 호출의 상태를 이어간다
	//	_In_z_                        char const* _Delimiter,		구분자 예를들어 ,면 쉼표로 문자열을 나눈다
	//	_Inout_ _Deref_prepost_opt_z_ char** _Context		문자열 분리 상태를 저장하는 포인터 문자열의 현재위치를 저장하는 포인터!
	//);
	//strtok는 내부적으로 상태를 저장하지 않는다 대신 호출자가 제공한 context를 사용하여 상태를 관리한다.
	//안정성을 극복하기위해 설계된것이고 여러문자열을 동시에 처리하거나 스레드간에 동일한 함수 호출을 사용할경우에도 안전하다.

	char* pContext = nullptr;
	char* pWidth = nullptr;
	char* pHeigth = nullptr;
	pWidth = strtok_s(cLine, ", ",&pContext);
	pHeigth = strtok_s(NULL, ", ", & pContext);
	m_iWidth = atoi(pWidth);
	m_iHeight = atoi(pHeigth);

	m_pBlockOrigin = new char* [m_iHeight];
	m_pBlock = new char* [m_iHeight];

	for (int i = 0; i < m_iHeight; ++i)
	{
		m_pBlockOrigin[i] = new char[m_iWidth];
		m_pBlock[i] = new char[m_iWidth];

		memset(cLine, 0, 256);

		fgets(cLine, 256, pFile);
		
		memcpy(m_pBlockOrigin[i], cLine, m_iWidth);	//맵 본체
		memcpy(m_pBlock[i], cLine, m_iWidth);	//맵의 정보들을담는 블락
		

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

	//아이템추가
	//몬스터추가 

	strcpy_s(m_strName, pFileName);

	m_strName[strlen(pFileName) - 4] = 0;
	
	
	return true;
}

void CMaze::Render(char* pBuffer)
{
	int iCurrent = 0;

	for (int i = 0; i < m_iHeight; ++i)
	{
		for (int j = 0; j < m_iWidth; ++j)
		{

			switch ((BLOCK)m_pBlock[i][j])
			{
			case BLOCK::ROAD:
				memcpy(&pBuffer[iCurrent], "  ", 2);
				break;
			case BLOCK::WALL:
				memcpy(&pBuffer[iCurrent], "■", 2);
				break;
			case BLOCK::START:
				memcpy(&pBuffer[iCurrent], "★", 2);
				break;
			case BLOCK::EXIT:
				memcpy(&pBuffer[iCurrent], "☞ ", 2);
				break;
			}

			iCurrent += 2;
		}
		//한줄 
		pBuffer[iCurrent] = '\n';
		++iCurrent;
	}

}
