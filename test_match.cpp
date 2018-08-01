//
// Created by lzenczuk on 01/08/18.
//

#include <iostream>
#include "pitch.hpp"

uint8_t get_move(){
    return static_cast<uint8_t>(rand() % 8);
}

std::string move_to_str(uint8_t m){
    switch(m){
        case 0: return "up";
        case 1: return "up right";
        case 2: return "right";
        case 3: return "down right";
        case 4: return "down";
        case 5: return "down left";
        case 6: return "left";
        case 7: return "up left";
    }
}

void print_move_result(move_result mr) {
    std::cout << "move_result: { ball: {" << (unsigned int) mr.b.x << ", " << (unsigned int) mr.b.y << "}, goal: "
              << mr.goal << ", success: " << mr.success << ", cell empty: " << mr.cell_empty << "}" << std::endl;
}

int main(){
    uint8_t players[] = {31, 144};
    int active_player_index = 0;

    pitch p = pitch();

    srand (time(NULL));

    while(true){
        uint8_t move = get_move();

        std::cout << " ----- "<< int(players[active_player_index]) << std::endl;
        std::cout << " ----- "<< move_to_str(move) << std::endl;

        move_result m = p.move_ball(move);
        print_move_result(m);

        if(m.goal){
            std::cout << "Played "<< int(players[active_player_index]) << " scored" << std::endl;
            break;
        }

        if(active_player_index==0){
            active_player_index = 1;
        }else{
            active_player_index = 0;
        }

        std::cout << _visualize_pitch(p) << std::endl;

        std::cout << " ----- "<< std::endl;
    }

    std::cout << " ----- END "<< std::endl;

    return 0;
}
