//
// Created by lzenczuk on 31/07/18.
//

#include <iostream>
#include <assert.h>
#include "pitch.hpp"
#include "directions.hpp"

void print_move_result(move_result mr) {
    std::cout << "move_result: { ball: {" << (unsigned int) mr.b.x << ", " << (unsigned int) mr.b.y << "}, goal: "
              << mr.goal << ", success: " << mr.success << ", cell empty: " << mr.cell_empty << "}" << std::endl;
}

void test_get_ball() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);
}

void test_move_ball_up() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 4);
    assert(m.b.x == 4);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_down() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 6);
    assert(m.b.x == 4);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_up_and_down() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 4);
    assert(m.b.x == 4);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::down);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 4);
    assert(m.b.x == 4);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(!m.success);
}

void test_move_ball_down_and_up() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 6);
    assert(m.b.x == 4);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::up);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 6);
    assert(m.b.x == 4);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(!m.success);
}

int main() {
    test_get_ball();

    // Basic moves
    test_move_ball_up();
    test_move_ball_down();

    // Sequences
    test_move_ball_up_and_down();
    test_move_ball_down_and_up();
}
