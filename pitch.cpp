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
    bool cell_visited;
};
 */

move_result not_allowed_move(ball b){
    return {
        b,
        false,
        static_cast<uint8_t>(-1),
        false,
        true,
        false
    };
}

move_result success_move(ball b, bool next_move_possible, bool cell_visited){
    return {
            b,
            false,
            static_cast<uint8_t>(-1),
            true,
            next_move_possible,
            cell_visited
    };
}

move_result goal(ball b, uint8_t player){
    return {
            b,
            true,
            player,
            true,
            false,
            false
    };
}

void _move_ball(pitch &p, uint8_t x, uint8_t y){
    p.ball_x = x;
    p.ball_y = y;
}

std::string _visualize_pitch(pitch p){

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
            return not_allowed_move({ball_x, ball_y});
    }
}

move_result pitch::move_ball_up() {

    // Top row and goal
    if (ball_y == 0 && ball_x == 4) {
        return goal({ball_x, ball_y}, 0);
    }

    // Top row but not goal
    if (ball_y == 0){
        return not_allowed_move({ball_x, ball_y});
    }

    // Block moving up on edges
    if(ball_x == 0 || ball_x == 8){
        return not_allowed_move({ball_x, ball_y});
    }

    // Not top row
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::up) {
        // Move in this direction blocked
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available
        bool visited = is_cell_visited(ball_x, ball_y - 1);
        
        pa.block_direction(ball_x, ball_y, directions::up);
        ball_y -= 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_up_right() {

    // Top row and goal
    if (ball_y == 0 && (ball_x == 3 || ball_x == 4)) {
        return goal({ball_x, ball_y}, 0);
    }

    // Top row - block
    if (ball_y == 0) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Last column - block
    if (ball_x == 8) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Not top row
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::up_right) {
        // Move in this direction blocked
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x + 1, ball_y - 1);

        pa.block_direction(ball_x, ball_y, directions::up_right);
        ball_y -= 1;
        ball_x += 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_right() {

    // Last column
    if (ball_x >= 8) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Top or bottom row allow right from only two cells
    if((ball_y==0 || ball_y==10) && (ball_x!=3 && ball_x!=4)){
        return not_allowed_move({ball_x, ball_y});
    }

    // Not last column
    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::right) {
        // Move in this direction blocked
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x+1, ball_y);

        pa.block_direction(ball_x, ball_y, directions::right);
        ball_x += 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_down_right() {

    // Top row and goal
    if (ball_y == 10 && (ball_x == 3 || ball_x == 4)) {
        return goal({ball_x, ball_y}, 1);
    }

    // Bottom row
    if (ball_y == 10) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Last column
    if (ball_x == 8) {
        return not_allowed_move({ball_x, ball_y});
    }

    uint8_t cell = pa.get_cell(ball_x, ball_y);

    if (cell & directions_bits::down_right) {
        // Move in this direction blocked
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x + 1, ball_y + 1);

        pa.block_direction(ball_x, ball_y, directions::down_right);
        ball_y += 1;
        ball_x += 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_down() {

    // Bottom row and goal
    if (ball_y == 10 && ball_x == 4) {
        return goal({ball_x, ball_y}, 1);
    }

    // Bottom row
    if (ball_y == 10) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Block moving down on edges
    if(ball_x == 0 || ball_x == 8){
        return not_allowed_move({ball_x, ball_y});
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
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x, ball_y + 1);

        pa.block_direction(ball_x, cell_y, directions::up);
        ball_y += 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_down_left() {

    // Top row and goal
    if (ball_y == 10 && (ball_x == 4 || ball_x == 5)) {
        return goal({ball_x, ball_y}, 1);
    }

    // First column
    if (ball_x == 0) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Bottom row
    if (ball_y == 10){
        return not_allowed_move({ball_x, ball_y});
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
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x - 1, ball_y + 1);

        pa.block_direction(cell_x, cell_y, directions::up_right);
        ball_y += 1;
        ball_x -= 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_left() {

    // Top or bottom row allow left from only two cells
    if((ball_y==0 || ball_y==10) && (ball_x!=4 && ball_x!=5)){
        return not_allowed_move({ball_x, ball_y});
    }

    // Last column
    if (ball_x == 0) {
        return not_allowed_move({ball_x, ball_y});
    }

    // Not last column
    uint8_t cell_x = ball_x - 1;
    uint8_t cell = pa.get_cell(cell_x, ball_y);

    if (cell & directions_bits::right) {
        // Move in this direction blocked
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available
        bool visited = is_cell_visited(ball_x - 1, ball_y);

        pa.block_direction(cell_x, ball_y, directions::right);
        ball_x -= 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

move_result pitch::move_ball_up_left() {

    // Top row and goal
    if (ball_y == 0 && (ball_x == 4 || ball_x == 5)) {
        return goal({ball_x, ball_y}, 0);
    }

    // Top row
    if (ball_y == 0) {
        return not_allowed_move({ball_x, ball_y});
    }

    // First column
    if (ball_x == 0) {
        return not_allowed_move({ball_x, ball_y});
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
        return not_allowed_move({ball_x, ball_y});
    } else {
        // Move in this direction available

        bool visited = is_cell_visited(ball_x - 1, ball_y - 1);

        pa.block_direction(cell_x, cell_y, directions::down_right);
        ball_y -= 1;
        ball_x -= 1;

        return success_move({ball_x, ball_y}, next_move_possible(),visited);
    }
}

bool pitch::next_move_possible() {
    
    if(ball_y == 0){
        // Top row
        
        if(ball_x == 0){
            // left top corner
            return false; 
        }
        
        if(ball_x == 8){
            // right top corner
            return false;
        }
        
        if(ball_x == 3 || ball_x == 4 || ball_x == 5){
            // goal cells - move always possible
            return true;
        }
        
        if(!(pa.get_cell(ball_x - 1, ball_y + 1) & directions_bits::up_right)){
            // lower left cell
            return true;
        }

        if(!(pa.get_cell(ball_x, ball_y + 1) & directions_bits::up)){
            // lower cell
            return true;
        }

        if(!(pa.get_cell(ball_x, ball_y) & directions_bits::down_right)){
            // lower right cell
            return true;
        }

        return false;
    }
    
    if(ball_y == 10){
        // Top row

        if(ball_x == 0){
            // left bottom corner
            return false;
        }

        if(ball_x == 8){
            // right bottom corner
            return false;
        }

        if(ball_x == 3 || ball_x == 4 || ball_x == 5){
            // goal cells - move always possible
            return true;
        }

        if(!(pa.get_cell(ball_x - 1, ball_y - 1) & directions_bits::down_right)){
            // upper left cell
            return true;
        }

        uint8_t cell = pa.get_cell(ball_x, ball_y);

        if(!(cell & directions_bits::up)){
            // up cell
            return true;
        }

        if(!(cell & directions_bits::up_right)){
            // lower left cell
            return true;
        }

        return false;
    }

    // We are at the middle, not at the top or bottom
    
    if(ball_x == 0){

        uint8_t cell = pa.get_cell(ball_x, ball_y);
        
        if(!(cell & directions_bits::up_right)){
            // lower left cell
            return true;
        }

        if(!(cell & directions_bits::right)){
            // lower left cell
            return true;
        }

        if(!(cell & directions_bits::down_right)){
            // lower left cell
            return true;
        }

        return false;
    }

    if(ball_x == 8){

        if(!(pa.get_cell(ball_x - 1, ball_y - 1) & directions_bits::down_right)){
            // upper left cell
            return true;
        }

        if(!(pa.get_cell(ball_x - 1, ball_y) & directions_bits::right)){
            // left cell
            return true;
        }

        if(!(pa.get_cell(ball_x - 1, ball_y+1) & directions_bits::up_right)){
            // lower left cell
            return true;
        }
        
        return false;
    }
    
    // Middle of pitch
    
    if(pa.get_cell(ball_x, ball_y)!=15){
        // Not all paths are used
        return true;
    }

    if(!(pa.get_cell(ball_x - 1, ball_y-1) & directions_bits::down_right)){
        // upper left cell
        return true;
    }

    if(!(pa.get_cell(ball_x - 1, ball_y) & directions_bits::right)){
        // left cell
        return true;
    }

    if(!(pa.get_cell(ball_x - 1, ball_y+1) & directions_bits::up_right)){
        // lower left cell
        return true;
    }

    if(!(pa.get_cell(ball_x, ball_y+1) & directions_bits::up)){
        // lower cell
        return true;
    }

    return false;
}

bool pitch::is_cell_visited(uint8_t x, uint8_t y) {
    
    if((y==0 || y==10) && (x != 4) ){
        return true;
    }
    
    if(x==0 || x==8){
        return true;
    }

    uint8_t cell = pa.get_cell(x, y);
    
    if(cell!=0){
        return true;
    }

    if(y!=0) {
        if (pa.get_cell(x - 1, y - 1) & directions_bits::down_right) {
            return true;
        }
    }

    if(pa.get_cell(x-1, y) & directions_bits::right){
        return true;
    }

    if(y!=10) {
        if (pa.get_cell(x - 1, y + 1) & directions_bits::up_right) {
            return true;
        }

        if (pa.get_cell(x, y + 1) & directions_bits::up) {
            return true;
        }
    }

    return false;
}
