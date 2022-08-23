/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board(gfx),
	rng(std::random_device()()),
	snake(delt_loc, {10,10}),
	goal(rng, board, snake)
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
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		gameStarted = true;
	}
	if (!gameOver && gameStarted)
	{		
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delt_loc = { 0, -1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delt_loc = { 0, 1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delt_loc = { -1, 0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delt_loc = { 1, 0 };
		}
		snakeMoveCounter++;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;
			const Location next = snake.GetNextHeadLocation(delt_loc);
			if (!board.IsInsideBoard(next) || snake.IsInTile(next))
			{
				gameOver = true;
			}
			else
			{
				bool eating = next == goal.GetLocation();
				if (eating)
				{
					snake.Grow();
				}
				snake.MoveBy(delt_loc);
				if (eating)
				{
					goal.Respawn(rng, board, snake);
				}
			}
		}
	}		
}

void Game::ComposeFrame()
{
	if (gameOver)
	{
		SpriteCodex::DrawGameOver(350, 250, gfx);
	}
	else
	{
		if (!gameStarted)
		{
			SpriteCodex::DrawTitle(300, 200, gfx);
		}
		else
		{
			board.DrawBorders();
			snake.Draw(board);
			goal.Draw(board);
		}
	}	
}
