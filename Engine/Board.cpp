#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx (gfx)
{
}

void Board::DrawCell( const Location& location, Color c)
{
	assert(location.x >= 1);
	assert(location.x < width-1);
	assert(location.y >= 1);
	assert(location.y < height-1);

	gfx.DrawRectDim(location.x * dimension, location.y * dimension, dimension, dimension, c);
}

void Board::DrawEyes(const Location& location)
{
	gfx.DrawRectDim(location.x * dimension + dimension - 7, location.y * dimension + 4, 4, 4, Colors::Black);
	gfx.DrawRectDim(location.x * dimension + dimension - 7, location.y * dimension + 12, 4, 4, Colors::Black);
}

void Board::DrawBorders()
{
	for (int x = dimension; x < dimension*width - dimension; x++)
	{
		gfx.PutPixel(x, dimension, { 255,255,255 });
		gfx.PutPixel(x, dimension * height - dimension, { 255,255,255 });
	}

	for (int y = dimension; y < dimension * height - dimension; y++)
	{
		gfx.PutPixel(dimension, y, { 255,255,255 });
		gfx.PutPixel(dimension * width - dimension, y, { 255,255,255 });
	}
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 1 && loc.x < width-1 && 
		   loc.y >= 1 && loc.y < height-1;
}
