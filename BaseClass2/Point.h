#pragma once

#include "Base.h"
#include <string>

class Point : public BaseClass // Derive class
{
public:
	int x;
	int y;
	int z; // z - will not be serialized	
	SAVE
	{
		REG_MEMBER(_int, x),
		REG_MEMBER(_int, y)
	}
	ENDSAVE;
};

class Line : public BaseClass
{
public:
	Point p1, p2;
	std::string name;
	SAVE
	{
		REG_MEMBER(_derive, p1),
		REG_MEMBER(_derive, p2),
		REG_MEMBER(_string, name)
	}
	ENDSAVE;
};
