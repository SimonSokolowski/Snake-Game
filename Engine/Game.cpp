#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()()),
	snek({2,2})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}

		++snekMoveCounter;
		if (snekMoveCounter >= snekMovePeriod)
		{
			snekMoveCounter = 0;
			if (!brd.IsInsideBoard(snek.GetNextHeadLocation(delta_loc)))
			{
				gameIsOver = true;
			}
			else
			{
				if (wnd.kbd.KeyIsPressed(VK_CONTROL))
				{
					snek.Grow();
				}
				snek.MoveBy(delta_loc);
			}
		}
	}
}

void Game::ComposeFrame()
{
	snek.Draw(brd);
	if (gameIsOver)
	{
		SpriteCodex::DrawGameOver(200, 200, gfx);
	}
}
