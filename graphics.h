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
    // TODO
}

void animate_victory_menu_background() {
    // TODO
}

void draw_victory_menu_background() {
    ClearBackground(BLACK);
}

void draw_victory_menu() {
    DrawRectangle(
        0, 0,
        static_cast<int>(screen_width), static_cast<int>(screen_height),
        { 0, 0, 0, 10 }
    );

    animate_victory_menu_background();
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

#endif // GRAPHICS_H
