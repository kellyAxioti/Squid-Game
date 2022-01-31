#pragma once

class GameObject
{

	int number;
	int score;


public:

	virtual void draw() = 0;
	virtual float getPosX() = 0;
	virtual float getPosY() = 0;
	virtual void setPosX(float x) = 0;
	virtual void setPosY(float y) = 0;

	virtual int getNum() = 0;
	virtual int getScore() = 0;
	virtual void setScore(int s) = 0;
	virtual bool contains(float x, float y) = 0;



};
