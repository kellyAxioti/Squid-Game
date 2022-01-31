#include "Cell.h"
#include "sgg/graphics.h"
#include "Config.h"



void Cell::draw()
{
    graphics::Brush br;

    float h = 1.0f * m_highlighted;
    br.fill_color[0] = h;
    br.fill_color[1] = h;
    br.fill_color[2] = h;
    br.outline_opacity = 1.0f * (m_active);

    graphics::drawRect(m_pos[0], m_pos[1], CELL_SIZE * 1.5, CELL_SIZE * 1.5, br);

    float e = 1.0f * m_active;
    br.fill_color[0] = e;
    br.fill_color[1] = e;
    br.fill_color[2] = e;
    br.outline_opacity = 0.0f;
    graphics::drawRect(m_pos[0], m_pos[1], CELL_SIZE, CELL_SIZE, br);
    graphics::resetPose();

}

bool Cell::contains(float x, float y)
{
    return distance(x, y, m_pos[0], m_pos[1]) < CELL_SIZE * 1.05;
}
