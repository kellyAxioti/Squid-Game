#include "RectangleOb.h"
#include "sgg/graphics.h"
#include "Config.h"



void RectangleOb::draw()

{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "rec.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 45, 55, br);
}

bool RectangleOb::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < CELL_SIZE * 1.05;
}


