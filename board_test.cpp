#include <iostream>
#include <assert.h>

struct directions{
    static const uint8_t up = 0;
    static const uint8_t up_right = 1;
    static const uint8_t right = 2;
    static const uint8_t down_right = 3;
    static const uint8_t down = 4;
    static const uint8_t down_left = 5;
    static const uint8_t left = 6;
    static const uint8_t up_left = 7;
};

typedef uint8_t PitchCell;

struct PitchArray {
    uint8_t cells[50] = {
            204, 204, 204, 204, 240,
            255, 255, 255, 31,
            255, 255, 255, 255, 241,
            255, 255, 255, 31,
            255, 255, 255, 255, 241,
            255, 255, 255, 31,
            255, 255, 255, 255, 241,
            255, 255, 255, 31,
            255, 255, 255, 255, 241,
            255, 255, 255, 31,
            119, 119, 119, 119, 241
    };

    /**
     * Get cell by it x,y position
     * @param x
     * @param y
     * @return
     */
    uint8_t get_cell(uint8_t x, uint8_t y){

        assert(x>=0 && x<9);
        assert(y>=0 && y<11);

        int global_cell_index = y*9+x;
        return get_cell(global_cell_index);
    }

    void set_cell(uint8_t x, uint8_t y, uint8_t direction){

        assert(x>=0 && x<9);
        assert(y>=0 && y<11);
        assert(direction >= 0 && direction < 4);

        int global_cell_index = y*9+x;
        set_cell(global_cell_index, direction);
    }

private:

    static const uint8_t directions_to_values[4];

    /**
     * Get cell by index in cells array
     * @param global_cell_index
     * @return
     */
    uint8_t get_cell(int global_cell_index){
        int real_cel_index = global_cell_index / 2;
        uint8_t cell = cells[real_cel_index];

        if(global_cell_index % 2){
            cell = cell >> 4;
        }

        // set upper bits to 0
        cell = static_cast<uint8_t>(cell & 15);

        return cell;
    }

    void set_cell(int global_cell_index, uint8_t direction) {
        int real_cel_index = global_cell_index / 2;

        uint8_t value = directions_to_values[direction];

        if(global_cell_index % 2){
            value = value << 4;
        }

        value = ~value;

        cells[real_cel_index] = cells[real_cel_index] & value;
    }
};

const uint8_t PitchArray::directions_to_values[] = {1, 2, 4, 8};

void test_all_cells_values(){
    PitchArray pitch;

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
    PitchArray pitch;

    std::cout << " row: " << 0 << std::endl;

    for(int x=0; x<8; x++){
        assert(12 == pitch.get_cell(x, 0));
        pitch.set_cell(x,0, directions::up);
        assert(12 == pitch.get_cell(x, 0));
        pitch.set_cell(x,0, directions::up_right);
        assert(12 == pitch.get_cell(x, 0));
        pitch.set_cell(x,0, directions::right);
        assert(8 == pitch.get_cell(x, 0));
        pitch.set_cell(x,0, directions::down_right);
        assert(0 == pitch.get_cell(x, 0));
    }

    assert(0 == pitch.get_cell(8, 0));
    pitch.set_cell(8,0, directions::up);
    assert(0 == pitch.get_cell(8, 0));
    pitch.set_cell(8,0, directions::up_right);
    assert(0 == pitch.get_cell(8, 0));
    pitch.set_cell(8,0, directions::right);
    assert(0 == pitch.get_cell(8, 0));
    pitch.set_cell(8,0, directions::down_right);
    assert(0 == pitch.get_cell(8, 0));

    for(int y = 1; y < 10; y++){

        std::cout << " row: " << y << std::endl;

        for(int x=0; x<8; x++){
            assert(15 == pitch.get_cell(x, y));
            pitch.set_cell(x,y, directions::up);
            assert(14 == pitch.get_cell(x, y));
            pitch.set_cell(x,y, directions::up_right);
            assert(12 == pitch.get_cell(x, y));
            pitch.set_cell(x,y, directions::right);
            assert(8 == pitch.get_cell(x, y));
            pitch.set_cell(x,y, directions::down_right);
            assert(0 == pitch.get_cell(x, y));
        }

        assert(1 == pitch.get_cell(8, y));
        pitch.set_cell(8,y, directions::up);
        assert(0 == pitch.get_cell(8, y));
        pitch.set_cell(8,y, directions::up_right);
        assert(0 == pitch.get_cell(8, y));
        pitch.set_cell(8,y, directions::right);
        assert(0 == pitch.get_cell(8, y));
        pitch.set_cell(8,y, directions::down_right);
        assert(0 == pitch.get_cell(8, y));
    }

    std::cout << " row: " << 10 << std::endl;

    for(int x=0; x<8; x++){
        assert(7 == pitch.get_cell(x, 10));
        pitch.set_cell(x,10, directions::up);
        assert(6 == pitch.get_cell(x, 10));
        pitch.set_cell(x,10, directions::up_right);
        assert(4 == pitch.get_cell(x, 10));
        pitch.set_cell(x,10, directions::right);
        assert(0 == pitch.get_cell(x, 10));
        pitch.set_cell(x,10, directions::down_right);
        assert(0 == pitch.get_cell(x, 10));
    }

    assert(1 == pitch.get_cell(8, 10));
    pitch.set_cell(8,10, directions::up);
    assert(0 == pitch.get_cell(8, 10));
    pitch.set_cell(8,10, directions::up_right);
    assert(0 == pitch.get_cell(8, 10));
    pitch.set_cell(8,10, directions::right);
    assert(0 == pitch.get_cell(8, 10));
    pitch.set_cell(8,10, directions::down_right);
    assert(0 == pitch.get_cell(8, 10));
}

int main() {
    test_simple_set_cells_value();
    //test_all_cells_values();
    return 0;
}