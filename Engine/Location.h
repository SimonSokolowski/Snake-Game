#pragma once
struct Location
{
public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x = 0;
	int y = 0;
};

