#pragma once

class Score
{

	int value;


public:

	void draw();
	Score();
	void setValue(int v) { value = v; }
	int getValue() { return value; }
};

