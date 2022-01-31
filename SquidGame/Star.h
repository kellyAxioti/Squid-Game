#pragma once
#include "GameObject.h"

class Star : public GameObject
{
	float m_pos[2];

	int number = 5;
	int score = 50;

public:

	void draw() override;

	float getPosX() override { return m_pos[0]; }
	float getPosY() override { return m_pos[1]; }
	void setPosX(float x) override { m_pos[0] = x; }
	void setPosY(float y) override { m_pos[1] = y; }

	int getNum()  override { return number; }
	int getScore()  override { return score; }
	void setScore(int s)  override { score = s; }
	bool contains(float x, float y) override;
};

