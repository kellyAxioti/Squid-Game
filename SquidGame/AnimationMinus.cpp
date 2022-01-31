#include "AnimationMinus.h"
#include "sgg/graphics.h"
#include "Config.h"

void AnimationMinus::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 2.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	char tscore[40];
	sprintf_s(tscore, "-(%d)", value);
	graphics::drawText(CANVAS_WIDTH / 2 + 270, CANVAS_HEIGHT / 4 + 110, 30, tscore, br);
}
