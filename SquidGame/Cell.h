#pragma once
#include "GameObject.h"
#include <list>


class Cell
{
	float m_pos[2];
	bool m_highlighted = false;
	bool m_active = false;

	bool m_empty = false;
	GameObject* randObj;

public:

	void draw();

	float getPosX() { return m_pos[0]; }
	float getPosY() { return m_pos[1]; }
	void setPosX(float x) { m_pos[0] = x; }
	void setPosY(float y) { m_pos[1] = y; }
	void setHighlight(bool h) { m_highlighted = h; }
	void setActive(bool a) { m_active = a; }
	void setEmpty(bool e) { m_empty = e; }

	bool getEmpty() { return m_empty; }

	bool contains(float x, float y);
	void setRandObj(GameObject* o) { randObj = o; }
	GameObject* getRandObj() { return randObj; }
};







