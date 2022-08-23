#pragma once

class Location
{
public: 
	void Add(const Location& loc);

	bool operator==(const Location& rhs) const;
	Location operator-() const;

	void Rotate(const Location& delta_loc, const Location& loc);
	int x;
	int y;
};