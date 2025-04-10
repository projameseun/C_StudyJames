#include "CMazeManager.h"
#include "CMaze.h"
#include "CPlayer.h"
#include "CObjectManager.h"


CMazeManager* CMazeManager::m_pInst = nullptr;

CMazeManager::CMazeManager() : 
	m_pCurrentMaze(nullptr), m_bStart(false)
{
}

CMazeManager::~CMazeManager()
{
	for (int i = 0; i < m_MazeArray.size(); ++i)
	{
		delete m_MazeArray[i];
	}
}

bool CMazeManager::Start()
{
	FILE* pFile = nullptr;

	//r :읽기 w : 쓰기 a :이어쓰기
	//t : 텍스트파일 , b : 바이너리파일

	//해당파일을 열어서 미로 맵의 정보를 갖고온다
	fopen_s(&pFile, "MazeList.txt", "rt");

	if (!pFile)
	{
		perror("Failed to Open File");
		return false;
	}

	char cLine[256] = {};

	//스트림에서 문자열을 받아서 (MaxCount - 1)개의 문자를 입력받을때까지나, 개행 문자나 파일끝에EOF 도달할때까지 입력을 받아서
	//C형식의 문자열로 저장한다.
	//개행문자는 fgets로 하여금 입력을 끝나게 하지만 이 문자 역시 _Buffer에 저장한다
	fgets(cLine, 256, pFile);

	size_t iCount = atoi(cLine);	//문자열을 숫자로 받아들이는 함수

	for (int i = 0; i < iCount; ++i)
	{
		fgets(cLine, 256, pFile);

		size_t iLength = static_cast<int>(strlen(cLine));

		//\n까지 읽어오므로 마지막은 제거 
		if (cLine[iLength - 1] == '\n')
		{
			--iLength;
			cLine[iLength] = 0;
		}


		CMaze* pMaze = new CMaze;

		if (!pMaze->Start(cLine))
		{
			delete pMaze;
			fclose(pFile);
			return false;
		}

		//맵의 정보를 담고잇는 배열이 있을거다
		m_MazeArray.push_back(pMaze);
	}

	//DeltaTime이란?
	// FPS(Frame Per Seconend,초당프레임) 
	//주로 프레임간의 시간 간격을 계산하느데 사용한다
	// Update함수가 있는데 매 프레임마다 실행되는 함수이다
	// 초당 프레임이 100을 보장해주는 컴퓨터라면 이 캐릭터는 1초 후의 위치는 100이 될거다
	// 그러나 프레임이 10정도밖에 안되는 컴퓨터라면 이캐릭터는 10이 된다
	//우리가 일반적인 시간을 사용하면 컴퓨터 마다 성능차이가 있을거다 좋은컴퓨터일수록 프레임이 빠를거다 
	//그러나 게임에서는 어느 컴퓨터에서 돌려도 똑같은 프레임이 나와야된다 
	//이럴때 DeltaTime을 사용한다 
	//100FPS 가정하면 1/100초가 된다
	//10FPS라면 1/10 초가 된다.
	//실제로 이걸 1초후의 값으로 계산해보면
	//FPS100 ==> 1초후의 이동거리 = 100 * (1 * 1/100) = 1
	//FPS10 ===> 1초후의 이동거리 = 10 * (1 * 1/10) = 1 
	//둘의 값은 같아진다 
	//1초후의 이동거리 = FPS * (임의의스피드값 * DeltaTime) 

	//DeltaTiem을 직접만들기
	//컴퓨터의 메인보드에 고해상도 타이머가 존재한다. 이 타이머는 정확하고 일정한 주파수(1초의 각 타이머의 성능에 맞는 진동수)를 가지고 있다

	
	//QueryPerformanceCounter 
	//이 함수는 인자로 넘어간 변수의 함수가 호출된 시점의 타이머 값을 넘겨준다.
	//만약에 지원되지 않는 환경이라면 0을 반환한다 그럴일은 거의없다고 보면된다.
	//이 함수를 반복문으로 출력하게되면 끊임없이 숫자가 카운팅되는걸 확인 할수 있다



	//QueryPerformanceFrequency
	//이 함수는 인자에 현재 시스템의 고해상도 타이머의 주파수(1초당 진동수)를 반환한다.
	//이 값은 함수를 호출하는 시스템마다 다르기 때문에(컴퓨터사양) 컴퓨터마다 호출했을때 값이 다를수 있다.

	//DeltaTime(프레임사이의 시간) = (현제 프레임의 진동수 카운팅 - 이전프레임의 진동카운팅) / 초당진동수

	//고해상도 타이머 주파수 확인
	if (!QueryPerformanceFrequency(&m_fSecond))
	{
		std::cout << "timer not supported" << std::endl;
	}
	

	fclose(pFile);

	return true;
}

void CMazeManager::Update(int _idx, char* pBuffer)
{
	m_pCurrentMaze = m_MazeArray[_idx];


	//미로의 시작위치를 가져온다
	COORD fStartPos = m_pCurrentMaze->GetStartPos();

	//미로의 시작위치를 플레이어의 위치로 지정
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();

	pPlayer->SetPos(fStartPos);
	pPlayer->clear();

	m_pCurrentMaze->clear();
	m_bStart = true;

	system("cls");


	//초기 시간기록
	QueryPerformanceCounter(&m_fPrevTime);
	
	while (m_bStart)
	{
		
		LARGE_INTEGER fCurrentTime;
		QueryPerformanceCounter(&fCurrentTime);

		//DeltaTime 
		//DeltaTime(프레임사이의 시간) = (현제 프레임의 진동수 카운팅 - 이전프레임의 진동카운팅) / 초당진동수
		float fDeltaTime = (fCurrentTime.QuadPart - m_fPrevTime.QuadPart) / (float)m_fSecond.QuadPart;

		//이전 시간을 현재시간으로 갱신
		m_fPrevTime = fCurrentTime;


		COORD fPos = {};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), fPos);

		//ObjectUpdate
		CObjectManager::GetInst()->Update(fDeltaTime);

		//MazeRender
		m_pCurrentMaze->Render(pBuffer);

		//ObjectRender
		CObjectManager::GetInst()->Render(pBuffer);

		std::cout << pBuffer << std::endl;
		
		if (m_bStart == false)
		{
			memset(pBuffer, 0, 256);
			std::cout << pBuffer << std::endl;

			
		}
	}

	//memset(pBuffer, 0, 256);

	
	
	std::cout << "게임을 다시 시작할려면 ENTER 눌러주세요 " << std::endl;

	//enter를 누를떄까지 기다림 
	while (_getch() != '\r')
	{
		char test = _getch();
		int a = 0;
	}
	
	CObjectManager::GetInst()->ClearObj();


	//입력스트림 버퍼비우기
	//Windows.h 때문에 충돌이날수있는데 이러면 
	//#define NOMINMAX
		//#include <Windows.h>
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	

}

int CMazeManager::MazeMainMenu()
{
	system("cls");

	for (int i = 0; i < m_MazeArray.size(); ++i)
	{
		std::cout << i + 1 << ". " << m_MazeArray[i]->GetName() << std::endl;
	} 

	std::cout << m_MazeArray.size() + 1 << "  종료 " << std::endl;
	std::cout << "미로를 선택해주세요 : ";

	int iSelect;

	
	std::cin >> iSelect;
	std::cin.ignore();


	if (iSelect < 1 || iSelect > m_MazeArray.size() + 1)
	{
		return 0;
	}

	return iSelect;

	

}
