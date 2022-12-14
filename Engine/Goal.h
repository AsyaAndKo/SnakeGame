#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public: 
	Goal(std::mt19937& rng, const Board& board, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& board, const Snake& snake);
	void Draw(Board& board) const;
	const Location& GetLocation() const;

private:
	Location location;
	static constexpr Color c = Colors::Red;
};
