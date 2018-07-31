//
// Created by lzenczuk on 31/07/18.
//

#ifndef SOCCER_PITCH_H
#define SOCCER_PITCH_H

#include <cstdint>
#include "pitch_array.hpp"

struct ball {
    uint8_t x;
    uint8_t y;
};

struct move_result{
    ball b;
    bool goal;
    bool success;
    bool cell_empty;
};

class pitch {
    uint8_t ball_x;
    uint8_t ball_y;
    pitch_array pa;

    move_result move_ball_up();

public:
    pitch();
    ball get_ball();
    move_result move_ball(uint8_t dir);

    move_result move_ball_down();
};

#endif //SOCCER_PITCH_H
