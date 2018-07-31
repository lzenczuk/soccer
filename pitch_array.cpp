//
// Created by lzenczuk on 31/07/18.
//

#include <assert.h>
#include "pitch_array.hpp"

const uint8_t pitch_array::directions_to_values[] = {1, 2, 4, 8};

uint8_t pitch_array::get_cell(uint8_t x, uint8_t y) {
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 11);

    int global_cell_index = y * 9 + x;
    int real_cel_index = global_cell_index / 2;

    uint8_t cell = cells[real_cel_index];

    // uint8_t stores two 4 bits cells.
    if(global_cell_index % 2){
        // move upper 4 bits lower
        cell = cell >> 4;
    }else{
        // clear 4 upper bits
        cell = static_cast<uint8_t>(cell & 15);
    }

    return cell;
}

void pitch_array::block_direction(uint8_t x, uint8_t y, uint8_t direction) {

    assert(x>=0 && x<9);
    assert(y>=0 && y<11);
    assert(direction >= 0 && direction < 4);

    int global_cell_index = y*9+x;
    int real_cel_index = global_cell_index / 2;

    uint8_t value = directions_to_values[direction];

    // uint8_t stores two 4 bits cells. Move value 4 bits up.
    if(global_cell_index % 2){
        value = value << 4;
    }

    cells[real_cel_index] = cells[real_cel_index] | value;
}

