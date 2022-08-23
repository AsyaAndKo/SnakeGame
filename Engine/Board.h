#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& location, Color c);
	void DrawEyes(const Location& location);
	void DrawBorders();
	bool IsInsideBoard(const Location& loc) const;
	static constexpr int width = 40;
	static constexpr int height = 30;

private:
	static constexpr int dimension = 20;
	Graphics& gfx;
};