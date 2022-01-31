#include "Girl.h"
#include "sgg/graphics.h"
#include "Config.h"


void Girl::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "girl.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 60, 60, br);
}

bool Girl::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < CELL_SIZE * 1.05;
}

