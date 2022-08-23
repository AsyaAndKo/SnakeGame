#pragma once

#include "Graphics.h"
#include "Location.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawTitle( int x,int y,Graphics& gfx );
	static void DrawHead(const Location& loc, Graphics& gfx);
};