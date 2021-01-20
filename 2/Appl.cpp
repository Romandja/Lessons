#include "Appl.h"






void Application::menu()
{
	cout << "[1] Выход" << endl;
	cout << "[2] Старт" << endl;
		
	
}

bool Application::runAction(int action)
{



	switch (action) {
	case 1:
		return false;
		break;
	case 2:
        Game();
		Sleep(2000);
		break;
	case 3:

		Sleep(2000);
		break;
	case 4:


		break;
	case 5:

		break;
	case 6:
			
		break;
	case 7:

		break;
	case 8:

		break;
	}

	return true;
}

void Application::start()
{
	int action;

	while (true) {
		system("cls");

		menu();
		cin >> action;
		if (!runAction(action))
		{
			break;
		}
		Sleep(2000);
	}
}

void Application::Game()
{
	

}
