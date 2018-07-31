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

move_result pitch::move_ball(uint8_t dir) {
    switch (dir) {
        case directions::up: {
            return move_ball_up();

        }
        case directions::down:
            return move_ball_down();
    }

    return move_result{
            {ball_x, ball_y},
            false,
            false,
            true
    };

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
        ball_y = ball_y - 1;

        uint8_t new_cell = pa.get_cell(ball_x, ball_y);

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
