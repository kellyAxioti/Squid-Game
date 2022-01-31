#pragma once

class Animation
{

	int value;


public:

	virtual void draw() = 0;
	virtual void setValue(int v) = 0;
	virtual int getValue() = 0;
};
