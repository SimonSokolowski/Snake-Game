#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
private:
	MainWindow& wnd;
	Graphics gfx;

	Board brd;
	Snake snek;
	Location delta_loc = {1,0};
	static constexpr int snekMovePeriod = 30;
	int snekMoveCounter = 0;
	bool gameIsOver = false;
	std::mt19937 rng;
};