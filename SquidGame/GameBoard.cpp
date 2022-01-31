#include "GameBoard.h"
#include "sgg/graphics.h"

void GameBoard::draw()
{
    //background
    graphics::Brush br;
    br.texture = std::string(ASSET_PATH) + "board.png";
    graphics::drawRect(pos_x, pos_y, CANVAS_WIDTH, CANVAS_HEIGHT, br);
    graphics::resetPose();
    br.texture = " ";
    //background for game-instructions
    br.texture = std::string(ASSET_PATH) + "scorebg.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH - 170, 250, 320, 450, br);
    br.outline_opacity = 0.0f;
    graphics::resetPose();
    br.texture = " ";
    //rectangle for score display
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 295, CANVAS_HEIGHT / 4, 245, 85, br);
    //instructions
    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;
    graphics::drawText(CANVAS_WIDTH / 2 + 180, CANVAS_HEIGHT / 10, 30, "Match-3 items", br);

    graphics::drawText(CANVAS_WIDTH / 2 + 180, CANVAS_HEIGHT / 4 - 10, 15, "Press  [S]  to shuffle", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 180, CANVAS_HEIGHT / 4 + 25, 15, "Every swap :  -200 points", br);

    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 85, 80, 50, br);


    //score rules

    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 135, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "badguy.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 135, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 280, CANVAS_HEIGHT / 4 + 135, 60, 30, br);


    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 190, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "cir.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 190, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 280, CANVAS_HEIGHT / 4 + 190, 60, 30, br);

    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 250, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "girl.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 250, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 280, CANVAS_HEIGHT / 4 + 250, 60, 30, br);

    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 310, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "rec.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 212, CANVAS_HEIGHT / 4 + 310, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 280, CANVAS_HEIGHT / 4 + 310, 60, 30, br);

    graphics::drawRect(CANVAS_WIDTH / 2 + 380, CANVAS_HEIGHT / 4 + 135, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "star.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 380, CANVAS_HEIGHT / 4 + 135, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 450, CANVAS_HEIGHT / 4 + 135, 60, 30, br);

    graphics::drawRect(CANVAS_WIDTH / 2 + 380, CANVAS_HEIGHT / 4 + 190, 40, 40, br);
    br.texture = std::string(ASSET_PATH) + "tri.png";
    br.outline_opacity = 0.0f;
    graphics::drawRect(CANVAS_WIDTH / 2 + 380, CANVAS_HEIGHT / 4 + 190, 30, 30, br);
    br.texture = " ";
    graphics::drawRect(CANVAS_WIDTH / 2 + 450, CANVAS_HEIGHT / 4 + 190, 60, 30, br);

    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.outline_opacity = 0.0f;
    graphics::drawText(CANVAS_WIDTH / 2 + 263, CANVAS_HEIGHT / 4 + 135, 15, "+100", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 263, CANVAS_HEIGHT / 4 + 190, 15, "+10", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 263, CANVAS_HEIGHT / 4 + 250, 15, "+80", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 263, CANVAS_HEIGHT / 4 + 310, 15, "+20", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 430, CANVAS_HEIGHT / 4 + 135, 15, "+50", br);
    graphics::drawText(CANVAS_WIDTH / 2 + 430, CANVAS_HEIGHT / 4 + 190, 15, "+30", br);

}

