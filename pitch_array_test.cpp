#include <iostream>
#include <assert.h>
#include "pitch_array.hpp"
#include "directions.hpp"

void test_all_cells_values(){
    pitch_array pitch;

    std::cout << " row: " << 0 << std::endl;

    assert(12 == pitch.get_cell(0, 0));
    assert(12 == pitch.get_cell(1, 0));
    assert(12 == pitch.get_cell(2, 0));
    assert(12 == pitch.get_cell(3, 0));
    assert(12 == pitch.get_cell(4, 0));
    assert(12 == pitch.get_cell(5, 0));
    assert(12 == pitch.get_cell(6, 0));
    assert(12 == pitch.get_cell(7, 0));
    assert(0  == pitch.get_cell(8, 0));

    std::cout << " row: " << 1 << std::endl;

    assert(15 == pitch.get_cell(0, 1));
    assert(15 == pitch.get_cell(1, 1));
    assert(15 == pitch.get_cell(2, 1));
    assert(15 == pitch.get_cell(3, 1));
    assert(15 == pitch.get_cell(4, 1));
    assert(15 == pitch.get_cell(5, 1));
    assert(15 == pitch.get_cell(6, 1));
    assert(15 == pitch.get_cell(7, 1));
    assert(1  == pitch.get_cell(8, 1));

    for(int y = 2; y < 10; y++){

        std::cout << " row: " << y << std::endl;

        assert(15 == pitch.get_cell(0, y));
        assert(15 == pitch.get_cell(1, y));
        assert(15 == pitch.get_cell(2, y));
        assert(15 == pitch.get_cell(3, y));
        assert(15 == pitch.get_cell(4, y));
        assert(15 == pitch.get_cell(5, y));
        assert(15 == pitch.get_cell(6, y));
        assert(15 == pitch.get_cell(7, y));
        assert(1  == pitch.get_cell(8, y));
    }

    std::cout << " row: " << 10 << std::endl;

    assert(7 == pitch.get_cell(0, 10));
    assert(7 == pitch.get_cell(1, 10));
    assert(7 == pitch.get_cell(2, 10));
    assert(7 == pitch.get_cell(3, 10));
    assert(7 == pitch.get_cell(4, 10));
    assert(7 == pitch.get_cell(5, 10));
    assert(7 == pitch.get_cell(6, 10));
    assert(7 == pitch.get_cell(7, 10));
    assert(1 == pitch.get_cell(8, 10));
}

void test_simple_set_cells_value() {
    pitch_array pitch;

    std::cout << " row: " << 0 << std::endl;

    for(int x=0; x<8; x++){
        assert(12 == pitch.get_cell(x, 0));
        pitch.block_direction(x, 0, directions::up);
        assert(12 == pitch.get_cell(x, 0));
        pitch.block_direction(x, 0, directions::up_right);
        assert(12 == pitch.get_cell(x, 0));
        pitch.block_direction(x, 0, directions::right);
        assert(8 == pitch.get_cell(x, 0));
        pitch.block_direction(x, 0, directions::down_right);
        assert(0 == pitch.get_cell(x, 0));
    }

    assert(0 == pitch.get_cell(8, 0));
    pitch.block_direction(8, 0, directions::up);
    assert(0 == pitch.get_cell(8, 0));
    pitch.block_direction(8, 0, directions::up_right);
    assert(0 == pitch.get_cell(8, 0));
    pitch.block_direction(8, 0, directions::right);
    assert(0 == pitch.get_cell(8, 0));
    pitch.block_direction(8, 0, directions::down_right);
    assert(0 == pitch.get_cell(8, 0));

    for(int y = 1; y < 10; y++){

        std::cout << " row: " << y << std::endl;

        for(int x=0; x<8; x++){
            assert(15 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::up);
            assert(14 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::up_right);
            assert(12 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::right);
            assert(8 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::down_right);
            assert(0 == pitch.get_cell(x, y));
        }

        assert(1 == pitch.get_cell(8, y));
        pitch.block_direction(8, y, directions::up);
        assert(0 == pitch.get_cell(8, y));
        pitch.block_direction(8, y, directions::up_right);
        assert(0 == pitch.get_cell(8, y));
        pitch.block_direction(8, y, directions::right);
        assert(0 == pitch.get_cell(8, y));
        pitch.block_direction(8, y, directions::down_right);
        assert(0 == pitch.get_cell(8, y));
    }

    std::cout << " row: " << 10 << std::endl;

    for(int x=0; x<8; x++){
        assert(7 == pitch.get_cell(x, 10));
        pitch.block_direction(x, 10, directions::up);
        assert(6 == pitch.get_cell(x, 10));
        pitch.block_direction(x, 10, directions::up_right);
        assert(4 == pitch.get_cell(x, 10));
        pitch.block_direction(x, 10, directions::right);
        assert(0 == pitch.get_cell(x, 10));
        pitch.block_direction(x, 10, directions::down_right);
        assert(0 == pitch.get_cell(x, 10));
    }

    assert(1 == pitch.get_cell(8, 10));
    pitch.block_direction(8, 10, directions::up);
    assert(0 == pitch.get_cell(8, 10));
    pitch.block_direction(8, 10, directions::up_right);
    assert(0 == pitch.get_cell(8, 10));
    pitch.block_direction(8, 10, directions::right);
    assert(0 == pitch.get_cell(8, 10));
    pitch.block_direction(8, 10, directions::down_right);
    assert(0 == pitch.get_cell(8, 10));
}

int main() {
    test_all_cells_values();
    test_simple_set_cells_value();
    return 0;
}