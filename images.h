#ifndef IMAGES_H
#define IMAGES_H

#include "raylib.h"

#include "globals.h"

#include <string>
#include <cassert>
#include <fstream>

void load_fonts() {
    menu_font = LoadFont("data/fonts/ARCADECLASSIC.TTF");
}

void unload_fonts() {
    UnloadFont(menu_font);
}

void load_images() {
    wall_image     = LoadTexture("data/images/wall.png");
    floor_image    = LoadTexture("data/images/floor.png");
    entrance_image = LoadTexture("data/images/entrance.png");
    exit_image     = LoadTexture("data/images/exit.png");
    tree_image = LoadTexture("data/images/tree/tree00.png");
    coin_sprite    = load_sprite("data/images/coin/coin", ".png", 9);
    player_sprite  = load_sprite("data/images/player/player", ".png", 11);
    swordR_sprite = load_sprite("data/images/sword/rightward/sword", ".png", 7);
    swordL_sprite = load_sprite("data/images/sword/leftward/sword", ".png", 7);
    swordU_sprite = load_sprite("data/images/sword/upward/sword", ".png", 7);
    swordD_sprite = load_sprite("data/images/sword/downward/sword", ".png", 7);
    dead_tree_sprite = load_sprite("data/images/tree/tree", ".png",12);

}

void unload_images() {
    UnloadTexture(wall_image);
    UnloadTexture(floor_image);
    UnloadTexture(entrance_image);
    UnloadTexture(exit_image);
    unload_sprite(coin_sprite);
    unload_sprite(player_sprite);
}

void draw_image(Texture2D image, float x, float y, float size) {
    draw_image(image, x, y, size, size);
}

void draw_image(Texture2D image, float x, float y, float width, float height) {
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(image.width), static_cast<float>(image.height) };
    Rectangle destination = { x, y, width, height };
    DrawTexturePro(image, source, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
}

sprite load_sprite(
    const std::string &file_name_prefix,
    const std::string &file_name_suffix,
    size_t frame_count,
    bool loop,
    size_t frames_to_skip
) {
    assert(frame_count < 100);

    sprite result = {
        frame_count, frames_to_skip, 0, 0, loop, 0, new Texture2D[frame_count]
    };

    for (size_t i = 0; i < frame_count; ++i) {
        std::string file_name;
        if (frame_count < 10) {
            file_name = file_name_prefix;
            file_name += std::to_string(i);
            file_name += file_name_suffix;
        } else {
            file_name = file_name_prefix;
            file_name += i < 10 ? ("0" + std::to_string(i)) : std::to_string(i);
            file_name += file_name_suffix;
        }
        result.frames[i] = LoadTexture(file_name.c_str());
    }

    return result;
}

void unload_sprite(sprite &sprite) {
    assert(sprite.frames != nullptr);

    for (size_t i = 0; i < sprite.frame_count; ++i) {
        UnloadTexture(sprite.frames[i]);
    }
    delete[] sprite.frames;
    sprite.frames = nullptr;
}

void draw_sprite(sprite &sprite, float x, float y, float size) {
    draw_sprite(sprite, x, y, size, size);
}

void draw_sprite(sprite &sprite, float x, float y, float width, float height) {
    draw_image(sprite.frames[sprite.frame_index], x, y, width, height);

    if (sprite.prev_game_frame == game_frame) {
        return;
    }
    if (sprite.frames_skipped < sprite.frames_to_skip) {
        ++sprite.frames_skipped;
    } else {
        sprite.frames_skipped = 0;

        ++sprite.frame_index;
        if (sprite.frame_index >= sprite.frame_count) {
            sprite.frame_index = sprite.loop ? 0 : sprite.frame_count - 1;
        }
    }
    sprite.prev_game_frame = game_frame;
}



// Структура для представления гифки
struct sprite_once {
    Texture2D* frames;
    int frame_count;
    int frame_index;
    bool is_playing;
};


bool file_exists(const char* filename) {
    std::ifstream file(filename);
    return file.good();
}

sprite_once load_sprite_once(const char* folderPath, int frameCount) {
    sprite_once spriteOnce;
    spriteOnce.frames = (Texture2D*)malloc(frameCount * sizeof(Texture2D));
    spriteOnce.frame_count = frameCount;
    spriteOnce.frame_index = 0;
    spriteOnce.is_playing = false;

    for (int i = 0; i < frameCount; ++i) {
        char filePath[256];
        sprintf(filePath, "%s/frame_%04d.png", folderPath, i);

        // Проверка наличия файла, если не найден, используется пустая текстура
        if (file_exists(filePath)) {
            Image image = LoadImage(filePath);
            spriteOnce.frames[i] = LoadTextureFromImage(image);
            UnloadImage(image);
        } else {
            // Используйте пустую текстуру или загрузите заранее подготовленную текстуру "отсутствует"
            // spriteOnce.frames[i] = LoadTexture("path_to_missing_texture.png");
        }
    }

    return spriteOnce;
}



void unload_sprite_once(sprite_once &spriteOnce) {
    for (int i = 0; i < spriteOnce.frame_count; ++i) {
        UnloadTexture(spriteOnce.frames[i]);
    }

    free(spriteOnce.frames);
}



void draw_sprite_once(sprite_once &spriteOnce, float x, float y, float width, float height) {
    if (!spriteOnce.is_playing) {
        return;
    }

    draw_image(spriteOnce.frames[spriteOnce.frame_index], x, y, width, height);

    ++spriteOnce.frame_index;
    if (spriteOnce.frame_index >= spriteOnce.frame_count) {
        spriteOnce.is_playing = false;
        spriteOnce.frame_index = 0;
    }
}



void play_sprite_once(sprite_once &spriteOnce) {
    spriteOnce.is_playing = true;
    spriteOnce.frame_index = 0;
}









#endif // IMAGES_H
