#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& board, const Snake& snake)
{
	Respawn(rng, board, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& board, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, board.width - 1);
	std::uniform_int_distribution<int> yDist(0, board.height - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	location = newLoc;
}

void Goal::Draw(Board& board) const
{
	board.DrawCell(location, c);
}

const Location& Goal::GetLocation() const
{
	return location;
}
