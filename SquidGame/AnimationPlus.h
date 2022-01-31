#pragma once
#include "Animation.h"

class AnimationPlus : public Animation
{

	int value;


public:

	void draw();

	void setValue(int v) override { value = v; }
	int getValue() override { return value; }
};

