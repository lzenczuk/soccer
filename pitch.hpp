//
// Created by lzenczuk on 31/07/18.
//

#ifndef SOCCER_PITCH_H
#define SOCCER_PITCH_H

#include <iostream>
#include "pitch_array.hpp"

struct ball {
    uint8_t x;
    uint8_t y;
};

struct move_result{
    ball b;
    bool goal;
    bool success;
    bool next_move_possible;
    bool cell_visited;
};

struct cell_status{
    bool next_move_by_player;
    bool next_move_possible;
};

class pitch {
    uint8_t ball_x;
    uint8_t ball_y;
    pitch_array pa;

    move_result move_ball_up();
    move_result move_ball_up_right();
    move_result move_ball_right();
    move_result move_ball_down_right();
    move_result move_ball_down();
    move_result move_ball_down_left();
    move_result move_ball_left();
    move_result move_ball_up_left();

    bool next_move_possible();
    bool is_cell_visited(uint8_t x, uint8_t y);

public:
    pitch();
    ball get_ball();
    move_result move_ball(uint8_t dir);

    // Functions for test purpose
    friend std::string _visualize_pitch(pitch p);
    friend void _move_ball(pitch& p, uint8_t x, uint8_t y);
};

#endif //SOCCER_PITCH_H
