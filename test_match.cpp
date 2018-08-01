//
// Created by lzenczuk on 01/08/18.
//

#include <iostream>
#include "pitch.hpp"

uint8_t get_move() {
    return static_cast<uint8_t>(rand() % 8);
}

std::string move_to_str(uint8_t m) {
    switch (m) {
        case 0:
            return "up";
        case 1:
            return "up right";
        case 2:
            return "right";
        case 3:
            return "down right";
        case 4:
            return "down";
        case 5:
            return "down left";
        case 6:
            return "left";
        case 7:
            return "up left";
    }
}

void print_move_result(move_result mr) {
    std::cout << "move_result: { ball: {" << (unsigned int) mr.b.x << ", " << (unsigned int) mr.b.y << "}, goal: "
              << mr.goal << ", success: " << mr.success << ", cell empty: " << mr.cell_visited << "}" << std::endl;
}

int main() {
    uint8_t players[] = {31, 144};
    int active_player_index = 0;

    long wins[3] = {};

    srand(time(NULL));
    pitch p;

    for (int x = 0; x < 10000; x++) {
        p = pitch();

        while (true) {
            uint8_t move = get_move();

            std::cout << " ----- " << int(players[active_player_index]) << std::endl;
            std::cout << " ----- " << move_to_str(move) << std::endl;

            move_result m = p.move_ball(move);
            print_move_result(m);

            if (m.goal) {
                wins[m.player] = wins[m.player]+1;
                std::cout << "Player " << int(players[m.player]) << " scored" << std::endl;
                std::cout << _visualize_pitch(p) << std::endl;
                break;
            }

            if (m.success && !m.next_move_possible) {
                wins[2] = wins[2]+1;
                std::cout << "No mor moves. Draw. " << std::endl;
                std::cout << _visualize_pitch(p) << std::endl;
                break;
            }

            if (m.cell_visited) {
                std::cout << "Player " << int(players[active_player_index]) << " continue." << std::endl;
            } else {
                if (active_player_index == 0) {
                    active_player_index = 1;
                } else {
                    active_player_index = 0;
                }
            }

            //std::cout << _visualize_pitch(p) << std::endl;

            std::cout << " ----- " << std::endl;
        }

        std::cout << "Game: "<< x << " ----- END " << std::endl;
    }

    std::cout << "Result. player 0: "<< wins[0] << "; player 1: " << wins[1] << "; draw: " << wins[2] << std::endl;

    return 0;
}
