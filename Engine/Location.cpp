#include "Location.h"

void Location::Add(const Location& loc)
{
	x += loc.x;
	y += loc.y;
}

bool Location::operator==(const Location& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

Location Location::operator-() const
{
	return {-x, -y};
}

void Location::Rotate(const Location& delta_loc, const Location& loc)
{

}
