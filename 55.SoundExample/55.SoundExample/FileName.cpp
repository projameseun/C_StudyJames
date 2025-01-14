#include "Info.h"
#include "Music.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Music mic;

	mic.InitRecordName();
	
	mic.InitSettingRecordPath(mic.GetRecordName());

	vector<LPCWSTR> rePath;

	while (true)
	{
		system("cls");
		
		std::cout << "1.�Ϲ� ���" << std::endl;
		std::cout << "2.���� ���" << std::endl;
		std::cout << "3.������" << std::endl;

		int iSelect = 0;

		std::cin >> iSelect;

		if (iSelect  <= 0 || iSelect > 3)
		{
			
			std::cout << "������ �߸��Ͽ����ϴ� �ٽ� �������ּ��� " << std::endl;
			Sleep(500);
			continue;
		}

		
		if (iSelect == (int)MenuSelect::DefaultPlay)
		{
			mic.MusicePlayMenuPrint();
			for (int i = 0; i < mic.GetRecordName().size(); ++i)
			{
				 rePath = mic.GetRecordPath();
				
				mic.InitMusiceDevice(rePath[i]);

			}
		


			
		}

		else if (iSelect == (int)MenuSelect::RandomPlay)
		{
			mic.ShuffuleMusic();
			mic.SettingRecordPath(mic.GetRecordName());
			mic.MusicePlayMenuPrint();
			for (int i = 0; i < mic.GetRecordName().size(); ++i)
			{
				 rePath = mic.GetRecordPath();
				
				mic.InitMusiceDevice(rePath[i]);

			}
		}

		else if (iSelect == (int)MenuSelect::EXIT)
		{
			break;
		}


		//�뷡��� ��� select
		iSelect = 0;

		std::cin >> iSelect;

		if (iSelect < 1 || iSelect > 10)
		{
			std::cout << "������ �߸��Ͽ����ϴ� �ٽ� �������ּ��� " << std::endl;
			Sleep(500);
			continue;
		}


		//�뷡����
		mic.UpdateMusic(iSelect);
	}

	mic.DestroyMusic();
	

	return 0;
}