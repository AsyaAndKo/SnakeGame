#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc, const Location& delta_loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& location) ;
		void Draw(Board& board) const;
		const Location& GetLocation() const;
		void SetSegmentLocation(const Segment& prev_segment, const Location& delta_loc);
	private:
		Location loc;
		Color c;
	};
	
public:
	Snake(const Location& delta_loc, const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& board) const;
	bool IsInTile(const Location& target) const;
	bool IsInTileWhole(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Blue;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 3;
};