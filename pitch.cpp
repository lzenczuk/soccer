//
// Created by lzenczuk on 31/07/18.
//

#include "pitch.hpp"
#include "directions.hpp"

pitch::pitch() : ball_x(4), ball_y(5), pa(pitch_array()) {}

ball pitch::get_ball() {
    return ball{ball_x, ball_y};
}

struct directions_bits {
    static const uint8_t up = 1;
    static const uint8_t up_right = 2;
    static const uint8_t right = 4;
    static const uint8_t down_right = 8;
    static const uint8_t down = 1;
    static const uint8_t down_left = 2;
    static const uint8_t left = 4;
    static const uint8_t up_left = 8;
};

/*
 * struct move_result{
    ball b;
    bool goal;
    bool success;
    bool cell_empty;
};
 */

std::string visualize_pitch(pitch p){

    char v[] = {
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\n',
            ' ','0','-','0','-','0','-','0',' ','0',' ','0','-','0','-','0','-','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','0',' ','\n',
            ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','\n',
            ' ','0','-','0','-','0','-','0',' ','0',' ','0','-','0','-','0','-','0',' ','\n',
            0
    };

    for(int y = 0; y < 11; y++){
        for(int x = 0;  x < 9; x++){
            auto cell = p.pa.get_cell(x, y);

            if(cell & directions_bits::up){
                v[y*40+x*2+1] = '|';
            }

            if(cell & directions_bits::up_right){
                if(v[y*40+x*2+2]==' '){
                    v[y*40+x*2+2] = '/';
                }else{
                    v[y*40+x*2+2] = 'X';
                }
            }

            if(cell & directions_bits::right){
                v[y*40+20+x*2+2] = '-';
            }

            if(cell & directions_bits::down_right){
                if(v[y*40+20+20+x*2+2]==' '){
                    v[y*40+20+20+x*2+2] = '\\';
                }else{
                    v[y*40+20+20+x*2+2] = 'X';
                }
            }
        }
    }

    return std::string(v);
}

move_result pitch::move_ball(uint8_t dir) {
    switch (dir) {
        case directions::up:
            return move_ball_up();
        case directions::up_right:
            return move_ball_up_right();
        case directions::right:
            return move_ball_right();
        case directions::down_right:
            return move_ball_down_right();
        case directions::down:
            return move_ball_down();
        case directions::down_left:
            return move_ball_down_left();
        case directions::left:
            return move_ball_left();
        case directions::up_left:
            return move_ball_up_left();
        default:
            return move_result{
                    {ball_x, ball_y},
                    false,
                    false,
                    true
            };
    }
}

move_result pitch::move_ball_up() {

    // Top row but not goal
    if (ball_y == 0 && ball_x != 4) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Top row and goal
    if (ball_y == 0 && ball_x == 4) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // Block moving up on edges
    if(ball_x == 0 || ball_x == 8){
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not top row
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::up) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(ball_x, ball_y, directions::up);
        ball_y -= 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_up_right() {

    // Top row but not goal
    if (ball_y == 0 && ball_x != 3) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Top row and goal
    if (ball_y == 0 && ball_x == 3) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // Last column
    if (ball_x == 8) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not top row
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::up_right) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(ball_x, ball_y, directions::up_right);
        ball_y -= 1;
        ball_x += 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_right() {

    // Last column
    if (ball_x >= 8) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not last column
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::right) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(ball_x, ball_y, directions::right);
        ball_x += 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_down_right() {
    // Bottom row but not goal
    if (ball_y == 10 && ball_x != 3) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Top row and goal
    if (ball_y == 10 && ball_x == 3) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // Last column
    if (ball_x == 8) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not bottom row
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::down_right) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(ball_x, ball_y, directions::down_right);
        ball_y += 1;
        ball_x += 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_down() {

    // Bottom row but not goal
    if (ball_y == 10 && ball_x != 4) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Bottom row and goal
    if (ball_y == 10 && ball_x == 4) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // Block moving down on edges
    if(ball_x == 0 || ball_x == 8){
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not bottom row

    /*
     * Because cell stores only information about directions from up to down right
     * to check down direction we have to fetch cell bellow and it's up direction
     */
    uint8_t cell_y = ball_y + 1;
    uint8_t cell = pa.get_cell(ball_x, cell_y);

    if (cell & directions_bits::up) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(ball_x, cell_y, directions::up);
        ball_y = ball_y + 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_down_left() {
    // Bottom row but not goal
    if (ball_y == 10 && ball_x != 5) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Top row and goal
    if (ball_y == 10 && ball_x == 5) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // First column
    if (ball_x == 0) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not top row

    /*
     * Because cell stores only information about directions from up to down right
     * to check down direction we have to fetch cell up and left to current one
     */
    uint8_t cell_y = ball_y + 1;
    uint8_t cell_x = ball_x - 1;
    uint8_t cell = pa.get_cell(cell_x, cell_y);

    if (cell & directions_bits::down_left) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(cell_x, cell_y, directions::up_right);
        ball_y += 1;
        ball_x -= 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_left() {

    // Last column
    if (ball_x <= 0) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not last column
    uint8_t cell_x = ball_x - 1;
    uint8_t cell = pa.get_cell(cell_x, ball_y);

    if (cell & directions_bits::right) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(cell_x, ball_y, directions::right);
        ball_x -= 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

move_result pitch::move_ball_up_left() {

    // Top row but not goal
    if (ball_y == 0 && ball_x != 5) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Top row and goal
    if (ball_y == 0 && ball_x == 5) {
        return move_result{
                {ball_x, ball_y},
                true,
                true,
                true
        };
    }

    // First column
    if (ball_x == 0) {
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    }

    // Not top row

    /*
     * Because cell stores only information about directions from up to down right
     * to check down direction we have to fetch cell up and left to current one
     */
    uint8_t cell_y = ball_y - 1;
    uint8_t cell_x = ball_x - 1;
    uint8_t cell = pa.get_cell(cell_x, cell_y);

    if (cell & directions_bits::down_right) {
        // Move in this direction blocked
        return move_result{
                {ball_x, ball_y},
                false,
                false,
                true
        };
    } else {
        // Move in this direction available
        pa.block_direction(cell_x, cell_y, directions::down_right);
        ball_y -= 1;
        ball_x -= 1;

        return move_result{
                {ball_x, ball_y},
                false,
                true,
                true
        };
    }
}

