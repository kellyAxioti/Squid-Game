#include "Game.h"
#include "sgg/graphics.h"
#include "Config.h"
#include <cstdlib>
#include <time.h>
#include "AnimationMinus.h"

void Game::update()
{
    if (m_state == STATE_INIT)
    {
        return;
    }
    if (m_state == STATE_LOADING)
    {
        init();
        checkMulti();

        m_state = STATE_STARTING;
        return;
    }
    if (m_state == STATE_STARTING)
    {
        setTotalScore(0);
        m_state = STATE_IDLE;
        return;
    }


    bool f1_pressed = graphics::getKeyState(graphics::scancode_t::SCANCODE_F1);
    if (f1_pressed)
    {
        cells_created = true;
        objs_created = true;

        graphics::Brush br;
        graphics::stopMusic();
        graphics::playSound("assets\\game.wav", 0.1f, true);


        board = new GameBoard;
        board_changed = true;
    }

    graphics::MouseState ms;
    graphics::getMouseState(ms);
    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasX(ms.cur_pos_y);
    Cell* cur_cell = nullptr;
    GameObject* cur_obj = nullptr;


    for (auto cell : cells) {
        if (cell->contains(mx, my))
        {
            cell->setHighlight(true);
            cur_cell = cell;
        }
        else
        {
            cell->setHighlight(false);
        }
    }
    for (auto obj : objs)
    {
        if (obj->contains(mx, my))
        {
            cur_obj = obj;

        }
    }

    if (ms.button_left_pressed && cur_cell && cur_obj)
    {
        setAnimDisplay(false);
        m_active_cell = cur_cell;
        m_active_obj = cur_obj;
        m_active_cell->setActive(true);
        for (auto c : cells)
        {
            if (c == m_active_cell)
            {
                c->setActive(true);
            }
            else
            {
                c->setActive(false);
            }
        }
        activeCells.push_back(m_active_cell);
        activeObjects.push_back(m_active_obj);
    }

    if (activeCells.size() == 2)
    {
        m_state = STATE_SWAPPING;
        swap(activeObjects[0], activeObjects[1], activeCells);
    }





    int randNum;
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tableuC[i][j]->getEmpty())
            {
                randNum = rand() % 6;
                randomise(tableuC[i][j], randNum, i, j);
                tableuC[i][j]->setEmpty(false);
            }
        }
    }
    if (m_state == STATE_SWAPPING)
    {

        m_active_cell->setActive(false);
        m_active_cell = nullptr;
        m_active_obj = nullptr;
        m_state = STATE_SWAPPED;
        activeObjects.clear();
        activeCells.clear();

    }


    bool s_pressed = graphics::getKeyState(graphics::scancode_t::SCANCODE_S);

    if (s_pressed)
    {
        setAnimDisplay(false);
        if (!objs.empty())
        {
            objs.clear();

        }
        if (!cells.empty())
        {
            cells.clear();
        }

        init();
        checkMulti();
    }


    if (m_state == STATE_SWAPPED) {
        if (total_score == 0)
        {

            if (!objs.empty())
            {
                objs.clear();

            }
            if (!cells.empty())
            {
                cells.clear();
            }
            graphics::Brush br;

            br.fill_color[0] = 2.0f;
            br.fill_color[1] = 0.0f;
            br.fill_color[2] = 0.0f;
            graphics::drawText(CANVAS_WIDTH / 2 - 280, CANVAS_HEIGHT / 2 - 80, 50, "GAME OVER", br);
            graphics::drawText(CANVAS_WIDTH / 2 - 280, CANVAS_HEIGHT / 2 - 30, 50, "Press [R] ", br);
            graphics::drawText(CANVAS_WIDTH / 2 - 280, CANVAS_HEIGHT / 2 + 20, 50, " to restart", br);


            bool r_pressed = graphics::getKeyState(graphics::scancode_t::SCANCODE_R);
            if (r_pressed)
            {
                m_state = STATE_STARTING;
                init();
                checkMulti();
            }
        }
    }
    score.setValue(total_score);

}



void Game::draw()
{
    if (m_state == STATE_INIT)
    {
        graphics::Brush br;
        graphics::drawText(CANVAS_WIDTH / 2 - 125, CANVAS_HEIGHT / 2, 30, "GAME LOADING...", br);
        m_state = STATE_LOADING;
        return;
    }
    graphics::Brush br;

    //background
    br.texture = std::string(ASSET_PATH) + "black-guy.png";
    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    br.fill_color[0] = 0.2f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 1.0f;
    float offset = CANVAS_WIDTH * sinf(graphics::getGlobalTime() / 400.0f) / 28;
    if (!board_changed) {
        graphics::drawText(210 + offset, 470, 50, "Press   [F1]   to   start", br);

    }
    br.texture = std::string(ASSET_PATH) + "image.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH - 90, 90, 150, 150, br);

    if (board) {

        board->draw();
    }
    if (cells_created) {
        for (auto cell : cells)
        {
            cell->draw();
        }
    }
    if (objs_created)
    {
        for (auto obj : objs)
        {
            obj->draw();
        }
    }
    if (board_changed && animation1.getValue() != 0 && m_state == STATE_SWAPPED && getAnimDisplay() && getTotalScore() != 0)
    {
        animation1.draw();
        animation2.draw();

    }
    score.draw();
}

void Game::init()
{

    //initialize cells for tableu
    int randNum;
    unsigned seed = time(0);
    srand(seed);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            Cell* c = new Cell();
            cells.push_back(c);
            tableuC[i][j] = c;

            c->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
            c->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
            //place random objects over cells
            randNum = rand() % 6;
            randomise(c, randNum, i, j);

        }
        randNum = rand() % 6;
    }
    //initialize game assets
    graphics::preloadBitmaps(ASSET_PATH);
}

void Game::randomise(Cell* c, int randNum, int i, int j)
{
    if (randNum == 0)
    {
        Girl* g = new Girl();
        objs.push_front(g);
        tableu[i][j] = g;
        c->setRandObj(g);

        g->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        g->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
    else if (randNum == 1)
    {
        BadGuy* bg = new BadGuy();
        objs.push_front(bg);
        tableu[i][j] = bg;
        c->setRandObj(bg);

        bg->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        bg->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
    else if (randNum == 2)
    {
        Triangle* tr = new Triangle();
        objs.push_front(tr);
        tableu[i][j] = tr;
        c->setRandObj(tr);

        tr->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        tr->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
    else if (randNum == 3)
    {
        RectangleOb* rec = new RectangleOb();
        objs.push_front(rec);
        tableu[i][j] = rec;
        c->setRandObj(rec);

        rec->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        rec->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
    else if (randNum == 4)
    {
        Circle* cir = new Circle();
        objs.push_front(cir);
        tableu[i][j] = cir;
        c->setRandObj(cir);

        cir->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        cir->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
    else if (randNum == 5)
    {
        Star* st = new Star();
        objs.push_front(st);
        tableu[i][j] = st;
        c->setRandObj(st);

        st->setPosX(CANVAS_WIDTH * (i + 0.5f) / 8.0f);
        st->setPosY(CANVAS_HEIGHT * (j + 0.5f) / 5.0f);
    }
}

void Game::checkMulti()
{
    int score_count = 0;
    int temp = deleteSame(tableu, objs, cells, score_count);

    while (temp != 0) {
        //start the board with no empty cells
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (tableuC[i][j]->getEmpty() == true)
                {
                    objs.clear();
                    cells.clear();
                    init();
                    temp = deleteSame(tableu, objs, cells, score_count);
                }
            }
        }
    }
}



void Game::swap(GameObject* obj1, GameObject* obj2, std::vector<Cell*> activeCells)
{
    float x1 = obj1->getPosX();
    float y1 = obj1->getPosY();
    float x2 = obj2->getPosX();
    float y2 = obj2->getPosY();



    int mscore = 200;

    if (obj1 != obj2)
    {
        obj1->setPosX(x2);
        obj1->setPosY(y2);
        obj2->setPosX(x1);
        obj2->setPosY(y1);


        activeCells[0]->setRandObj(activeObjects[1]);
        activeCells[1]->setRandObj(activeObjects[0]);

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (tableu[i][j] == obj1)
                {
                    tableu[i][j] = obj2;

                }
                else if (tableu[i][j] == obj2)
                {
                    tableu[i][j] = obj1;
                    /* tableuC[i][j] = activeCells[0];*/

                }

            }
        }

        int score_count = 0;

        //every swap decreases the score 200 values
        total_score = getTotalScore();
        total_score = total_score - mscore;

        int counter_extra = deleteSame(tableu, objs, cells, score_count);
        total_score = total_score + counter_extra;
        if (total_score < 0)
        {
            setTotalScore(0);
        }
        graphics::playSound("assets\\beep.wav", 1.0f, false);

        //Animations
        AnimationPlus a1;
        a1.setValue(counter_extra);
        setAnimation1(a1);

        AnimationMinus a2;
        a2.setValue(mscore);
        setAnimation2(a2);

        setAnimDisplay(true);

    }
}

int Game::deleteSame(GameObject* tableu[5][5], std::list<GameObject*>& objs, std::list<Cell*>& cells, int score_count)
{
    std::list<GameObject*> temp;
    std::list<Cell*> tempC;

    //check every row
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (tableu[i][j]->getNum() == tableu[i][j + 1]->getNum() && tableu[i][j + 1]->getNum() == tableu[i][j + 2]->getNum())
            {
                temp.push_front(tableu[i][j]);
                temp.push_front(tableu[i][j + 1]);
                temp.push_front(tableu[i][j + 2]);

            }
        }
    }
    for (auto c : cells)
    {
        for (auto t : temp)
        {
            if (t->getPosX() == c->getPosX() && t->getPosY() == c->getPosY())
                tempC.push_front(c);


        }
    }
    if (temp.size() >= 3)
    {

        for (auto t : temp)
        {

            score_count = score_count + t->getScore();

            objs.remove(t);

        }
    }
    for (auto c : tempC)
    {
        c->setEmpty(true);

    }

    temp.clear();
    tempC.clear();


    //check every column
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tableu[i][j]->getNum() == tableu[i + 1][j]->getNum() && tableu[i + 1][j]->getNum() == tableu[i + 2][j]->getNum())
            {
                temp.push_front(tableu[i][j]);
                temp.push_front(tableu[i + 1][j]);
                temp.push_front(tableu[i + 2][j]);
            }

        }
    }

    for (auto c : cells)
    {
        for (auto t : temp)
        {
            if (t->getPosX() == c->getPosX() && t->getPosY() == c->getPosY())
            {
                tempC.push_front(c);

            }

        }
    }

    if (temp.size() >= 3)
    {
        for (auto t : temp)
        {
            score_count = score_count + t->getScore();
            objs.remove(t);

        }
    }
    for (auto c : tempC)
    {
        c->setEmpty(true);

    }
    temp.clear();
    tempC.clear();
    return score_count;
}

Game* Game::getInstance()
{
    if (!m_instance)
        m_instance = new Game();
    return m_instance;
}

Game::~Game()
{

    for (auto cell : cells)
    {
        delete cell;
    }
    cells.clear();
    for (auto obj : objs)
    {
        delete obj;
    }
    objs.clear();

    for (auto a : activeCells)
    {
        delete a;
    }
    activeCells.clear();
    for (auto a : activeObjects)
    {
        delete a;
    }
    activeObjects.clear();

    if (board)
    {
        delete board;
    }



}
Game* Game::m_instance = nullptr;