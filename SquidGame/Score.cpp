#include "Score.h"
#include "sgg/graphics.h"
#include "Config.h"



void Score::draw()
{
	graphics::Brush br;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawText(CANVAS_WIDTH / 2 + 170, CANVAS_HEIGHT / 4 + 80, 15, "Score:", br);
	char tscore[40];
	sprintf_s(tscore, "(%d)", value);
	graphics::drawText(CANVAS_WIDTH / 2 + 185, CANVAS_HEIGHT / 4 + 100, 15, tscore, br);
}

Score::Score()
{
	value = 0;
}


