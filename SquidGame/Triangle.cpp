#include "Triangle.h"
#include "sgg/graphics.h"
#include "Config.h"



void Triangle::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "tri.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], 70, 70, br);
}

bool Triangle::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < CELL_SIZE * 1.05;
}

