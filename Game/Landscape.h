#pragma once

class Landscape
{
protected:
	int length, width, seed;
	int getRandomNumber(int, int);
public:
	Landscape(int length, int width, int seed) : length(length), width(width), seed(seed) {}
	virtual void draw() = 0;
};
