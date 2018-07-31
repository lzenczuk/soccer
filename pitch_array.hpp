//
// Created by lzenczuk on 31/07/18.
//

#ifndef SOCCER_PITCH_ARRAY_H
#define SOCCER_PITCH_ARRAY_H

#include <cstdint>

class pitch_array {

    uint8_t cells[50] = {};

    static const uint8_t directions_to_values[4];

public:
    /**
     * Get cell by it x,y position
     * @param x
     * @param y
     * @return
     */
    uint8_t get_cell(uint8_t x, uint8_t y);

    /**
     * Sets direction of selected cell to 0.
     * @param x
     * @param y
     * @param direction - one of four directions from up to down right.
     */
    void block_direction(uint8_t x, uint8_t y, uint8_t direction);
};

#endif //SOCCER_PITCH_ARRAY_H
