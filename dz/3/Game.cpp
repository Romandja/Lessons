#include "Game.h"

Game::~Game()
{
	delete player;
}

Game::Game(const char* username)
{
	player = new Player(username);
	/*this->width = width;
	this->height = height;*/
	init();
}


void Game::start()
{
	//пока игра не закончена
	while (!isGameOver()) {
		system("cls");
		printField();
		MoveDirection direction = keyUp();
		playerMove(direction);
	}
}

void Game::init()
{
	srand(time(0));

	int a = 0, b = 1;

	for (int i = 0; i < FIELD_HEIGTH; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			gameField [i][j]= a + rand() % (b - a + 1);
		}
	}
	for (int i = 0; i < 2; i++)//стартовая зона
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			gameField[i][j] = 1;
		}
	}
	//начало


	for (int i = 0; i < 20; i++)//центр
	{
		for (int j = 0; j < 10; j++)
		{
			int HEIGTH = rand() % 30;
			int WIDTH = rand() % 30;
			gameField[HEIGTH][WIDTH] = 1;
		}
	}

	for (int i = 29; i < FIELD_HEIGTH; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			gameField[i][j] = 1;
		}
	}//конец
}

bool Game::isGameOver()
{
	return false;
}

void Game::printField()
{
	for (int i = 0; i < FIELD_HEIGTH; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			if (j == player->position.x && i == player->position.y) {
				ColorConfig::setColor(playerColor);
				std::cout << PLAYER_SYMB;
			}
			else {
				if (gameField[i][j] == ROAD_NUM)
					ColorConfig::setColor(roadColor);
				else if (gameField[i][j] == BORDER_NUM)
					ColorConfig::setColor(borderColor);
				printSymb(gameField[i][j]);
			}
		}
		std::cout << std::endl;
	}
}

void Game::printSymb(int symbNum)
{
	switch (symbNum) {
	case ROAD_NUM: std::cout << ROAD_SYMB; break;
	case BORDER_NUM: std::cout << BORDER_SYMB; break;
		//case PLAYER_NUM: std::cout << PLAYER_SYMB; break;
	}
}

Game::MoveDirection Game::keyUp()
{
	_getch();
	MoveDirection direction;
	int key = _getch();

	switch (key)
	{
	case ARROW_LEFT:
		direction = Left;
		break;
	case ARROW_RIGHT:
		direction = Right;
		break;
	case ARROW_UP:
		direction = Up;
		break;
	case ARROW_DOWN:
		direction = Down;
		break;
	}

	return direction;
}

bool Game::canMoveToRight()
{
	return player->position.x < FIELD_WIDTH && gameField[player->position.y][player->position.x + 1] == ROAD_NUM;
}

bool Game::canMoveToLeft()
{
	return player->position.x > 0 && gameField[player->position.y][player->position.x - 1] == ROAD_NUM;
}

bool Game::canMoveToUp()
{
	return player->position.y > 0 && gameField[player->position.y - 1][player->position.x] == ROAD_NUM;
}

bool Game::canMoveToDown()
{
	return player->position.y < FIELD_HEIGTH&& gameField[player->position.y + 1][player->position.x] == ROAD_NUM;
}
