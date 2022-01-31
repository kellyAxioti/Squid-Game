#pragma once
#include "Config.h"
#include "GameBoard.h"
#include "Cell.h"
#include <list>
#include <vector>
#include "Girl.h"
#include "BadGuy.h"
#include "Triangle.h"
#include "RectangleOb.h"
#include "Circle.h"
#include "Star.h"
#include "Score.h"
#include "AnimationPlus.h"
#include "AnimationMinus.h"


class Game
{
public:
	enum game_state_t { STATE_INIT, STATE_LOADING, STATE_STARTING, STATE_IDLE, STATE_SWAPPING, STATE_SWAPPED };
	static Game* m_instance;

	GameBoard* board = nullptr;
	Cell* m_active_cell = nullptr;
	GameObject* m_active_obj = nullptr;
	bool board_changed = false;
	bool cells_created = false;
	bool objs_created = false;
	bool anim_display = false;
	int total_score = 0;
	std::list<Cell*> cells;
	std::list<GameObject*> objs;
	std::vector<Cell*> activeCells;
	std::vector<GameObject*> activeObjects;

	Score score;
	AnimationPlus animation1;
	AnimationMinus animation2;
	GameObject* tableu[5][5];
	Cell* tableuC[5][5];

	game_state_t m_state = STATE_INIT;


	void update();
	void draw();
	void init();
	void randomise(Cell* c, int randNum, int i, int j);
	void checkMulti();

	void swap(GameObject* obj1, GameObject* obj2, std::vector<Cell*> cells);
	int deleteSame(GameObject* tableu[5][5], std::list<GameObject*>& objs, std::list<Cell*>& cells, int score_count);

	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
	static Game* getInstance();

	void setTotalScore(int t) { total_score = t; }
	int getTotalScore() { return total_score; }
	void setAnimation1(AnimationPlus a) { animation1 = a; }
	void setAnimation2(AnimationMinus a) { animation2 = a; }
	void setAnimDisplay(bool d) { anim_display = d; }
	bool getAnimDisplay() { return anim_display; }

	~Game();
};

