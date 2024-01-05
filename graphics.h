#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

#include "globals.h"
#include "images.h"
#include "utilities.h"

#include <string>
#include <cmath>

void draw_menu() {
    ClearBackground(BLACK);

    const char *title = MENU_TITLE.c_str();
    const float title_font_size = MENU_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = MENU_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
        (screen_width - title_size.x) * 0.5f,
        screen_height * 0.5f - title_size.y * 0.5f - title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, MENU_TITLE_COLOR);

    const char *subtitle = MENU_SUBTITLE.c_str();
    const float subtitle_font_size = MENU_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift   = MENU_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
    Vector2 subtitle_position = {
        (screen_width - subtitle_size.x) * 0.5f,
        screen_height * 0.5f - subtitle_size.y * 0.5f + subtitle_y_shift
    };
    DrawTextEx(menu_font, subtitle, subtitle_position, subtitle_font_size, 1, MENU_SUBTITLE_COLOR);
}

void draw_player_score() {
    const float score_font_size  = GAME_SCORE_FONT_SIZE * screen_scale;
    const float score_top_margin = GAME_SCORE_Y_SHIFT   * screen_scale;

    std::string score_text = std::string("Score ");
    score_text += std::to_string(player_score);

    Vector2 score_size = MeasureTextEx(menu_font, score_text.c_str(), score_font_size, 1);
    Vector2 score_position = { (screen_width - score_size.x) * 0.5f, score_top_margin };
    DrawTextEx(menu_font, score_text.c_str(), score_position, score_font_size, 1, GAME_SCORE_COLOR1);
    score_position.x -= 4 * screen_scale;
    score_position.y -= 4 * screen_scale;
    DrawTextEx(menu_font, score_text.c_str(), score_position, score_font_size, 1, GAME_SCORE_COLOR2);
}

void derive_graphics_metrics_from_loaded_level() {
    screen_width  = static_cast<float>(GetScreenWidth());
    screen_height = static_cast<float>(GetScreenHeight());

    cell_size = std::min(
        screen_width  / static_cast<float>(level.columns),
        screen_height / static_cast<float>(level.rows)
    ) * CELL_SCALE;
    screen_scale = std::min(screen_width, screen_height) / SCREEN_SCALE_DIVISOR;
    float level_width  = static_cast<float>(level.columns) * cell_size;
    float level_height = static_cast<float>(level.rows)    * cell_size;
    shift_to_center_cell_by_x = (screen_width - level_width)   * 0.5f;
    shift_to_center_cell_by_y = (screen_height - level_height) * 0.5f;
}

void draw_level(){
    ClearBackground(BLACK);
    for (size_t row = 0; row < level.rows; ++row){
        for (size_t column = 0; column<level.columns; ++column){
            char cell = level.data[row*level.columns + column];
            float x = shift_to_center_cell_by_x + static_cast<float>(column) * cell_size;
            float y = shift_to_center_cell_by_y + static_cast<float>(row) * cell_size;
            switch (cell) {
                case FLOOR:
                    draw_image(floor_image, x, y, cell_size);
                    break;
                case WALL:
                    draw_image(wall_image, x, y, cell_size);
                    break;
                case ENTRANCE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(entrance_image, x, y, cell_size);
                    break;
                case EXIT:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(exit_image, x, y, cell_size);
                    break;
                case COIN:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(coin_sprite, x, y, cell_size);
                    break;
                case SWORD_DOWN_HIT:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(swordD_sprite, x,y,cell_size);
                    break;
                case SWORD_UP_HIT:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(swordU_sprite, x,y,cell_size);
                    break;
                case SWORD_LEFT_HIT:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(swordL_sprite, x,y,cell_size);
                    break;
                case SWORD_RIGHT_HIT:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(swordR_sprite, x,y,cell_size);
                    break;
                case TREE:
                    draw_image(floor_image,x,y,cell_size);
                    draw_image(tree_image,x,y,cell_size);
                    break;
                case DEAD_TREE:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(dead_tree_sprite,x,y,cell_size);
                    break;
                case ENEMY:
                    draw_image(floor_image,x,y,cell_size);
                    draw_sprite(enemy_sprite,x,y,cell_size);
                    break;
                case SHIPI:
                    draw_image(floor_image,x,y,cell_size);
                    draw_image(shipi_image,x,y,cell_size);
                    break;
                default:
                    break;
            }
        }
    }
}


void draw_player(){
    float x = shift_to_center_cell_by_x + static_cast<float>(player_column) * cell_size;
    float y = shift_to_center_cell_by_y + static_cast<float>(player_row) * cell_size;
    draw_sprite(player_sprite, x, y, cell_size);
}




void draw_pause_menu() {
    ClearBackground(BLACK);

    const char *title = PAUSE_TITLE.c_str();
    const float title_font_size = PAUSE_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = PAUSE_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
        (screen_width - title_size.x) * 0.5f,
        screen_height * 0.5f - title_size.y * 0.5f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, PAUSE_TITLE_COLOR);
}

void create_victory_menu_background() {
    for (int i = 0; i < count; ++i) {
        rays[i] = static_cast<unsigned int>(GetRandomValue(30, 50));
        rays[i] += rays[i] % 2;
        in_r[i] = GetRandomValue(1.2f, 2.4f);
        x[i] = GetRandomValue(out_r[i], screen_width - out_r[i]);
        y[i] = GetRandomValue(out_r[i], screen_height - out_r[i]);
        dx[i] = static_cast<float>(GetRandomValue(-max_speed, max_speed));
        if (fabs(dx[i]) < 22E-40f) dx[i] = 2.0f;
        dy[i] = static_cast<float>(GetRandomValue(-max_speed, max_speed));
        if (fabs(dy[i]) < 22E-40f) dy[i] = 2.0f;
        rotation[i] = 0.0f;
        rotation_speed[i] = static_cast<float>(GetRandomValue(-max_rotation_speed, max_rotation_speed));
        if (fabs(rotation_speed[i]) < 2E-4f) rotation_speed[i] = 0.01f;    }

    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
}

void animate_victory_menu_background(unsigned int rays, float x, float y, float in_r, float out_r,
                                     Color color, float r_angle, float line_thickness){

    float angle = r_angle;
    float angle_d = static_cast<float>(2.0 * M_PI / rays);
    float prev_end_x = x + cos(angle - angle_d) * in_r;
    float prev_end_y = y + sin(angle - angle_d) * in_r;
    for (unsigned int i = 0; i < rays; i++) {
        const float radius = i % 2 == 0 ? out_r : in_r;
        const float end_x = x + cos(angle) * radius;
        const float end_y = y + sin(angle) * radius;
        DrawLineEx({ x, y }, { end_x, end_y }, line_thickness, WHITE);
        DrawLineEx({ end_x, end_y }, { prev_end_x,
                                       prev_end_y }, line_thickness, WHITE);
        prev_end_x = end_x;
        prev_end_y = end_y;
        angle += angle_d;
    }
}

void draw_victory_menu_background() {
    DrawRectangle(0, 0, screen_width, screen_height, { 0, 0, 0, 60 });
    for (int i = 0; i < count; ++i) {
        animate_victory_menu_background(rays[i], x[i], y[i], in_r[i], out_r[i],
                                        color[i], rotation[i]);
        x[i] += dx[i];
        if (x[i] - out_r[i] < 0  || x[i] + out_r[i] > screen_width) {
            dx[i] = -dx[i];
        }
        y[i] += dy[i];
        if (y[i] - out_r[i] < 0 || y[i] + out_r[i] > screen_height) {
            dy[i] = -dy[i];
        }
        rotation[i] += rotation_speed[i];
    }
}

void draw_victory_menu() {
    DrawRectangle(
        0, 0,
        static_cast<int>(screen_width), static_cast<int>(screen_height),
        { 0, 0, 0, 10 }
    );

    draw_victory_menu_background();

    const char *title = VICTORY_TITLE.c_str();
    const float title_font_size = VICTORY_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = VICTORY_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
        (screen_width - title_size.x) * 0.5f,
        screen_height * 0.5f - title_size.y * 0.5f - title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, VICTORY_TITLE_COLOR);

    const char *subtitle = VICTORY_SUBTITLE.c_str();
    const float subtitle_font_size = VICTORY_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift   = VICTORY_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
    Vector2 subtitle_position = {
        (screen_width - subtitle_size.x) * 0.5f,
        screen_height * 0.5f - subtitle_size.y * 0.5f + subtitle_y_shift
    };
    DrawTextEx(menu_font, subtitle, subtitle_position, subtitle_font_size, 1, VICTORY_SUBTITLE_COLOR);
}

void create_lose_menu_background(){
    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
}

void draw_lose_menu() {
    ClearBackground(BLACK);
    DrawRectangle(
            0, 0,
            static_cast<int>(screen_width), static_cast<int>(screen_height),
            { 0, 0, 0, 10 }
    );

    const char *title = GAME_OVER_TITLE.c_str();
    const float title_font_size = GAME_OVER_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = GAME_OVER_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.5f - title_size.y * 0.5f - title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, GAME_OVER_TITLE_COLOR);

    const char *subtitle = GAME_OVER_SUBTITLE.c_str();
    const float subtitle_font_size = GAME_OVER_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift   = GAME_OVER_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
    Vector2 subtitle_position = {
            (screen_width - subtitle_size.x) * 0.5f,
            screen_height * 0.5f - subtitle_size.y * 0.5f + subtitle_y_shift
    };
    DrawTextEx(menu_font, subtitle, subtitle_position, subtitle_font_size, 1, GAME_OVER_SUBTITLE_COLOR);
}


#endif // GRAPHICS_H
