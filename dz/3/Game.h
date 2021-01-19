#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>

#include "Player.h"
#include "ColorConfig.h"

#define BORDER_NUM 0
#define BORDER_SYMB (char)178

#define ROAD_NUM 1
#define ROAD_SYMB (char)176

#define FIELD_WIDTH 30
#define FIELD_HEIGTH 30

#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_UP 72 
#define ARROW_DOWN 80

#define PLAYER_NUM 3
#define PLAYER_SYMB (char)219


class Game
{
public:
	enum MoveDirection {
		Left,
		Right,
		Up,
		Down
	};
	~Game();
	Game(const char* username);

	void start();
private:
	ColorConfig::ConsoleColor playerColor = ColorConfig::ConsoleColor::Red;
	ColorConfig::ConsoleColor roadColor = ColorConfig::ConsoleColor::White;
	ColorConfig::ConsoleColor borderColor = ColorConfig::ConsoleColor::Green;

	Player* player;
	//int** gameField;			//игровое поле
	int width;					//ширина поля
	int height;					//высота поля
	int gameField[FIELD_HEIGTH][FIELD_WIDTH];// = 	//игровое поле
	

	void init();
	bool isGameOver();
	void printField();
	void printSymb(int symbNum);
	MoveDirection keyUp();
	void playerMove(MoveDirection direction)
	{
		switch (direction)
		{
		case Game::Left:
			if (canMoveToLeft()) {
				player->toLeft();
			}
			break;
		case Game::Right:
			if (canMoveToRight()) {
				player->toRight();
			}
			break;
		case Game::Up:
			if (canMoveToUp()) {
				player->toUp();
			}
			break;
		case Game::Down:
			if (canMoveToDown()) {
				player->toDown();
			}
			break;
		}
	}

	bool canMoveToRight();
	bool canMoveToLeft();

	bool canMoveToUp();
	bool canMoveToDown();

};