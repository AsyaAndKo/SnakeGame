#include "Snake.h"
#include <assert.h>



Snake::Snake(const Location& delta_loc, const Location& loc)
{
	segments[0].InitHead(loc, delta_loc);
	for (int i = 1; i < nSegments; i++)
	{
		segments[i].InitBody();
		segments[i].SetSegmentLocation(segments[i - 1], delta_loc);
	}
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		nSegments++;
	}
}

void Snake::Draw(Board& board) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(board);
	}
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].GetLocation() == target)
			return true;
	}
	return false;
}

bool Snake::IsInTileWhole(const Location& target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
			return true;
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc, const Location& delta_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& location)
{
	assert(abs(location.x) + abs(location.y) == 1);
	loc.Add(location);
}

void Snake::Segment::Draw(Board& board) const
{
	if (c == headColor)
	{
		board.DrawCell(loc, c);
		board.DrawEyes(loc);
	}
	else
	{
		board.DrawCell(loc, c);
	}
	 
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Segment::SetSegmentLocation(const Segment& prev_segment, const Location& delta_loc)
{
	Location l(prev_segment.GetLocation());
	l.Add(-delta_loc);
	loc = l;
}

