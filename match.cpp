//
// Created by lzenczuk on 01/08/18.
//

#include <cstdint>
#include "match.hpp"

match::match() : p(pitch()), active_player(0), winner(100) {}

match_status match::make_move(uint8_t direction) {

    // game already finished
    if(winner!=100){
        return {
                active_player,
                winner
        };
    }

    // make move
    move_result mr = p.move_ball(direction);

    // winner
    if(mr.goal){
        winner = mr.player;
        active_player = 100;
        return {
            active_player,
            winner
        };
    }

    // draw
    if(mr.success && !mr.next_move_possible){
        winner = 2;
        active_player = 100;
        return {
                active_player,
                winner
        };
    }

    // active player continue
    if(mr.success && mr.next_move_possible && mr.cell_visited){
        return {
                active_player,
                winner
        };
    }

    // next player move
    if(mr.success && mr.next_move_possible && !mr.cell_visited){
        if(active_player){
            active_player = 0;
        }else{
            active_player = 1;
        }

        return {
                active_player,
                winner
        };
    }


}
