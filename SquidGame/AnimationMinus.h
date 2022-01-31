#pragma once
#pragma once
#include "Animation.h"

class AnimationMinus : public Animation
{

	int value;


public:

	void draw();

	void setValue(int v) override { value = v; }
	int getValue() override { return value; }
};
