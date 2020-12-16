#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx) ;
	void DrawCell(const Location& loc, Color c);
	int GetHeight() const;
	int GetWidth() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int dimensions = 20;
	static constexpr int height = 30;
	static constexpr int width = 40;
	Color c;
	Graphics& gfx;
};

