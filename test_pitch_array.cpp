#include <iostream>
#include <assert.h>
#include "pitch_array.hpp"
#include "directions.hpp"

void test_all_cells_values(){
    pitch_array pitch;

    std::cout << "Checking is all cells set to 0 by default " << std::endl;

    for(int y = 0; y < 11; y++){

        std::cout << "Checking row " << y << "; cell: ";

        for(int x = 0;  x < 9; x++){
            std::cout << x << " ";
            assert(0 == pitch.get_cell(x, y));
        }

        std::cout << std::endl;
    }
}

void test_set_all_cells_values(){
    pitch_array pitch;

    std::cout << "Checking is all cells correctly update direction" << std::endl;

    for(int y = 0; y < 11; y++){

        std::cout << "Checking row " << y << "; cell: ";

        for(int x = 0;  x < 9; x++){

            std::cout << x << " ";

            assert(0 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::up);
            assert(1 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::up_right);
            assert(3 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::right);
            assert(7 == pitch.get_cell(x, y));
            pitch.block_direction(x, y, directions::down_right);
            assert(15 == pitch.get_cell(x, y));
        }

        std::cout << std::endl;
    }

    for(int y = 0; y < 11; y++){

        std::cout << "Checking row " << y << "; cell: ";

        for(int x = 0;  x < 9; x++){
            std::cout << x << " ";
            assert(15 == pitch.get_cell(x, y));
        }

        std::cout << std::endl;
    }
}

int main() {
    test_all_cells_values();
    test_set_all_cells_values();
    return 0;
}