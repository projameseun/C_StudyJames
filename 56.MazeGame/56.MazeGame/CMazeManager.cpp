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

	//r :�б� w : ���� a :�̾��
	//t : �ؽ�Ʈ���� , b : ���̳ʸ�����

	//�ش������� ��� �̷� ���� ������ ����´�
	fopen_s(&pFile, "MazeList.txt", "rt");

	if (!pFile)
	{
		perror("Failed to Open File");
		return false;
	}

	char cLine[256] = {};

	//��Ʈ������ ���ڿ��� �޾Ƽ� (MaxCount - 1)���� ���ڸ� �Է¹�����������, ���� ���ڳ� ���ϳ���EOF �����Ҷ����� �Է��� �޾Ƽ�
	//C������ ���ڿ��� �����Ѵ�.
	//���๮�ڴ� fgets�� �Ͽ��� �Է��� ������ ������ �� ���� ���� _Buffer�� �����Ѵ�
	fgets(cLine, 256, pFile);

	size_t iCount = atoi(cLine);	//���ڿ��� ���ڷ� �޾Ƶ��̴� �Լ�

	for (int i = 0; i < iCount; ++i)
	{
		fgets(cLine, 256, pFile);

		size_t iLength = static_cast<int>(strlen(cLine));

		//\n���� �о���Ƿ� �������� ���� 
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

		//���� ������ ����մ� �迭�� �����Ŵ�
		m_MazeArray.push_back(pMaze);
	}

	//DeltaTime�̶�?
	// FPS(Frame Per Seconend,�ʴ�������) 
	//�ַ� �����Ӱ��� �ð� ������ ����ϴ��� ����Ѵ�
	// Update�Լ��� �ִµ� �� �����Ӹ��� ����Ǵ� �Լ��̴�
	// �ʴ� �������� 100�� �������ִ� ��ǻ�Ͷ�� �� ĳ���ʹ� 1�� ���� ��ġ�� 100�� �ɰŴ�
	// �׷��� �������� 10�����ۿ� �ȵǴ� ��ǻ�Ͷ�� ��ĳ���ʹ� 10�� �ȴ�
	//�츮�� �Ϲ����� �ð��� ����ϸ� ��ǻ�� ���� �������̰� �����Ŵ� ������ǻ���ϼ��� �������� �����Ŵ� 
	//�׷��� ���ӿ����� ��� ��ǻ�Ϳ��� ������ �Ȱ��� �������� ���;ߵȴ� 
	//�̷��� DeltaTime�� ����Ѵ� 
	//100FPS �����ϸ� 1/100�ʰ� �ȴ�
	//10FPS��� 1/10 �ʰ� �ȴ�.
	//������ �̰� 1������ ������ ����غ���
	//FPS100 ==> 1������ �̵��Ÿ� = 100 * (1 * 1/100) = 1
	//FPS10 ===> 1������ �̵��Ÿ� = 10 * (1 * 1/10) = 1 
	//���� ���� �������� 
	//1������ �̵��Ÿ� = FPS * (�����ǽ��ǵ尪 * DeltaTime) 

	//DeltaTiem�� ���������
	//��ǻ���� ���κ��忡 ���ػ� Ÿ�̸Ӱ� �����Ѵ�. �� Ÿ�̸Ӵ� ��Ȯ�ϰ� ������ ���ļ�(1���� �� Ÿ�̸��� ���ɿ� �´� ������)�� ������ �ִ�

	
	//QueryPerformanceCounter 
	//�� �Լ��� ���ڷ� �Ѿ ������ �Լ��� ȣ��� ������ Ÿ�̸� ���� �Ѱ��ش�.
	//���࿡ �������� �ʴ� ȯ���̶�� 0�� ��ȯ�Ѵ� �׷����� ���Ǿ��ٰ� ����ȴ�.
	//�� �Լ��� �ݺ������� ����ϰԵǸ� ���Ӿ��� ���ڰ� ī���õǴ°� Ȯ�� �Ҽ� �ִ�



	//QueryPerformanceFrequency
	//�� �Լ��� ���ڿ� ���� �ý����� ���ػ� Ÿ�̸��� ���ļ�(1�ʴ� ������)�� ��ȯ�Ѵ�.
	//�� ���� �Լ��� ȣ���ϴ� �ý��۸��� �ٸ��� ������(��ǻ�ͻ��) ��ǻ�͸��� ȣ�������� ���� �ٸ��� �ִ�.

	//DeltaTime(�����ӻ����� �ð�) = (���� �������� ������ ī���� - ������������ ����ī����) / �ʴ�������

	//���ػ� Ÿ�̸� ���ļ� Ȯ��
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


	//�̷��� ������ġ�� �����´�
	COORD fStartPos = m_pCurrentMaze->GetStartPos();

	//�̷��� ������ġ�� �÷��̾��� ��ġ�� ����
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();

	pPlayer->SetPos(fStartPos);
	pPlayer->clear();

	m_pCurrentMaze->clear();
	m_bStart = true;

	system("cls");


	//�ʱ� �ð����
	QueryPerformanceCounter(&m_fPrevTime);
	
	while (m_bStart)
	{
		
		LARGE_INTEGER fCurrentTime;
		QueryPerformanceCounter(&fCurrentTime);

		//DeltaTime 
		//DeltaTime(�����ӻ����� �ð�) = (���� �������� ������ ī���� - ������������ ����ī����) / �ʴ�������
		float fDeltaTime = (fCurrentTime.QuadPart - m_fPrevTime.QuadPart) / (float)m_fSecond.QuadPart;

		//���� �ð��� ����ð����� ����
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

	
	
	std::cout << "������ �ٽ� �����ҷ��� ENTER �����ּ��� " << std::endl;

	//enter�� ���������� ��ٸ� 
	while (_getch() != '\r')
	{
		char test = _getch();
		int a = 0;
	}
	
	CObjectManager::GetInst()->ClearObj();


	//�Է½�Ʈ�� ���ۺ���
	//Windows.h ������ �浹�̳����ִµ� �̷��� 
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

	std::cout << m_MazeArray.size() + 1 << "  ���� " << std::endl;
	std::cout << "�̷θ� �������ּ��� : ";

	int iSelect;

	
	std::cin >> iSelect;
	std::cin.ignore();


	if (iSelect < 1 || iSelect > m_MazeArray.size() + 1)
	{
		return 0;
	}

	return iSelect;

	

}
