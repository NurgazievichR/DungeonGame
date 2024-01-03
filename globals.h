#ifndef GLOBALS_H
#define GLOBALS_H
#include "vector"

#include "raylib.h"

#include <string>
#include <cstddef>

/* Game Elements */


void move_player(int dx, int dy);


const char FLOOR    = ' ';
const char WALL     = '#';
const char ENTRANCE = 'P';
const char EXIT     = 'E';
const char COIN     = '*';

/* Levels */

struct level {
    size_t rows = 0, columns = 0;
    char *data = nullptr;
};

char LEVEL_1_DATA[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', 'P', ' ', ' ', '*', ' ', ' ', 'E', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#'
};
level LEVEL_1 = {
    3, 9,
    LEVEL_1_DATA
};




char LEVEL_2_DATA[] = {
        '#', '#', '#',
        '#', 'P', '#',
        '#', ' ', '#',
        '#', ' ', '#',
        '#', '*', '#',
        '#', ' ', '#',
        '#', ' ', '#',
        '#', 'E', '#',
        '#', '#', '#',
};
level LEVEL_2 = {
        9, 3,
        LEVEL_2_DATA
};




char LEVEL_3_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'P', ' ', ' ', '#', 'E', ' ', ' ', '#',
        '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
        '#', ' ', '#', '#', '#', '*', '#', '#', '#',
        '#', '*', '#', '*', '#', ' ', ' ', ' ', '#',
        '#', ' ', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',


};
level LEVEL_3 = {
        9, 9,
        LEVEL_3_DATA
};


char LEVEL_4_DATA[] = {
'#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#','#', '#',
'#', 'P', '#', '#', '#', ' ', ' ', ' ', ' ',' ', ' ', '*', '#', ' ','#', '#',
'#', ' ', '#', '*', ' ', ' ', '#', '#', '#','#', '#', ' ', ' ', ' ',' ', '#',
'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ',' ', '#', ' ', '#', '#',' ', '#',
'#', ' ', '#', ' ', '#', ' ', '#', '*', '#',' ', '#', ' ', '#', '#',' ', '#',
'#', ' ', ' ', ' ', '#', ' ', '#', '#', '#',' ', '#', ' ', '#', '#','*', '#',
'#', '#', ' ', '#', '#', ' ', ' ', ' ', '#',' ', '#', ' ', ' ', ' ',' ', '#',
'#', '#', ' ', '#', '#', '#', '#', '*', '#',' ', '#', ' ', ' ', '#',' ', '#',
'#', '#', ' ', ' ', ' ', '#', ' ', ' ', '#',' ', ' ', ' ', ' ', '#','*', '#',
'#', '#', '#', '#', ' ', '#', ' ', '#', '#','#', ' ', '#', ' ', '#','#', '#',
'#', ' ', '*', '#', ' ', '#', ' ', '#', '*','#', ' ', '#', ' ', ' ','*', '#',
'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ','#', ' ', '#', ' ', '#','#', '#',
'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ',' ', ' ', '#', ' ', ' ','E', '#',
'#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#','#', '#',


};


level LEVEL_4 = {
        14, 16,
        LEVEL_4_DATA
};





std::vector<int> coins_copy;



const size_t LEVEL_COUNT = 4;
level LEVELS[LEVEL_COUNT] = {
        LEVEL_1,
        LEVEL_2,
        LEVEL_3,
        LEVEL_4,
};

/* Loaded Level Data */

level level;
size_t level_index = -1;

/* Player Data */

const int POINTS_FOR_COIN = 10;

size_t player_row;
size_t player_column;
int player_score = 0;

/* Graphics Metrics */

const float CELL_SCALE = 0.6f; // An aesthetic parameter to add some negative space around level
const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
                                           // to scale things accordingly to look pleasant.

float screen_width;
float screen_height;
float screen_scale; // Used to scale text/UI components size and displacements based on the screen size
float cell_size;
float shift_to_center_cell_by_x;
float shift_to_center_cell_by_y;

/* Fonts */

Font menu_font;

/* Menu Text Parameters */

const std::string MENU_TITLE     = "Dungeon";
const float MENU_TITLE_FONT_SIZE = 200.0f;
const float MENU_TITLE_Y_SHIFT   = 10.0f;
const Color MENU_TITLE_COLOR     = RED;

const std::string MENU_SUBTITLE     = "Press Enter to start the game";
const float MENU_SUBTITLE_FONT_SIZE = 30.0f;
const float MENU_SUBTITLE_Y_SHIFT   = 80.0f;
const Color MENU_SUBTITLE_COLOR     = WHITE;

/* Game Text Parameters */

const float GAME_SCORE_FONT_SIZE = 70.0f;
const float GAME_SCORE_Y_SHIFT   = 30.0f;
const Color GAME_SCORE_COLOR1    = GRAY;
const Color GAME_SCORE_COLOR2    = WHITE;

/* Images and Sprites */

Texture2D wall_image;
Texture2D floor_image;
Texture2D entrance_image;
Texture2D exit_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

sprite coin_sprite;
sprite player_sprite;
sprite swordL_sprite;
sprite swordR_sprite;
sprite swordD_sprite;
sprite swordU_sprite;

/* Sounds */

Sound coin_sound;
Sound exit_sound;

/* Pause Text Parameters */

const std::string PAUSE_TITLE     = "Press Esc to unpause the game";
const float PAUSE_TITLE_FONT_SIZE = 30.0f;
const float PAUSE_TITLE_Y_SHIFT   = 0.0f;
const Color PAUSE_TITLE_COLOR     = WHITE;

/* Victory Menu Background */

const int count = 2000;

const float max_speed = 2.0f;
const float max_rotation_speed = 0.1f;
unsigned int rays[count];
float x[count];
float y[count];
float dx[count];
float dy[count];
float out_r[count];
float in_r[count];
Color color[count];
float rotation[count];
float rotation_speed[count];

/* Victory Menu Text Parameters */

const std::string VICTORY_TITLE     = "You Won!";
const float VICTORY_TITLE_FONT_SIZE = 200.0f;
const float VICTORY_TITLE_Y_SHIFT   = 10.0f;
const Color VICTORY_TITLE_COLOR     = RED;

const std::string VICTORY_SUBTITLE     = "Press Enter to go back to menu";
const float VICTORY_SUBTITLE_FONT_SIZE = 30.0f;
const float VICTORY_SUBTITLE_Y_SHIFT   = 80.0f;
const Color VICTORY_SUBTITLE_COLOR     = WHITE;

/* Frame Counter */

size_t game_frame = 0;

/* Game State */

enum game_state {
    MENU_STATE,
    GAME_STATE,
    PAUSED_STATE,
    VICTORY_STATE
};

game_state game_state = MENU_STATE;

/* Forward Declarations */

// GRAPHICS_H

void draw_menu();
void draw_player_score();
void derive_graphics_metrics_from_loaded_level();
void draw_level();
void draw_pause_menu();
void create_victory_menu_background();
void animate_victory_menu_background(unsigned int rays,
                                     float x, float y,
                                     float in_r, float out_r,
                                     Color color = WHITE,
                                     float r_angle = 0.0f,
                                     float line_thickness = 1);
void draw_victory_menu_background();
void draw_victory_menu();

// IMAGES_H

void load_fonts();
void unload_fonts();

void load_images();
void unload_images();
void draw_image(Texture2D image, float x, float y, float width, float height);
void draw_image(Texture2D image, float x, float y, float size);

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count = 1,
    bool loop = true,
    size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, float x, float y, float width, float height);
void draw_sprite(sprite &sprite, float x, float y, float size);

// TODO: Add forward declarations of all your functions to avoid circular dependencies.

void load_sounds();
void unload_sounds();

#endif // GLOBALS_H
