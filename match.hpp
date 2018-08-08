//
// Created by lzenczuk on 01/08/18.
//

#ifndef SOCCER_MATCH_H
#define SOCCER_MATCH_H

#include <cstdint>
#include "pitch.hpp"

struct match_status{
    uint8_t active_player;
    uint8_t winner;
};

class match {
    pitch p;
    uint8_t active_player;
    uint8_t winner;

public:
    match();
    match_status make_move(uint8_t direction);
};

#endif //SOCCER_MATCH_H
