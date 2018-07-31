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

void test_move_ball_up_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 4);
    assert(m.b.x == 5);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 5);
    assert(m.b.x == 5);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_down_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 6);
    assert(m.b.x == 5);
    assert(m.b.y == 6);
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

void test_move_ball_down_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 6);
    assert(m.b.x == 3);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 5);
    assert(m.b.x == 3);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(m.success);
}

void test_move_ball_up_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 4);
    assert(m.b.x == 3);
    assert(m.b.y == 4);
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

void test_move_ball_up_right_and_down_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 4);
    assert(m.b.x == 5);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::down_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 4);
    assert(m.b.x == 5);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(!m.success);
}

void test_move_ball_right_and_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 5);
    assert(m.b.x == 5);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 5);
    assert(m.b.x == 5);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
}

void test_move_ball_down_right_and_up_left() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 6);
    assert(m.b.x == 5);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::up_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 5);
    assert(b.y == 6);
    assert(m.b.x == 5);
    assert(m.b.y == 6);
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

void test_move_ball_down_left_and_up_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::down_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 6);
    assert(m.b.x == 3);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::up_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 6);
    assert(m.b.x == 3);
    assert(m.b.y == 6);
    assert(!m.goal);
    assert(!m.success);
}

void test_move_ball_left_and_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 5);
    assert(m.b.x == 3);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 5);
    assert(m.b.x == 3);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
}

void test_move_ball_up_left_and_down_right() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::up_left);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 4);
    assert(m.b.x == 3);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(m.success);

    m = p.move_ball(directions::down_right);
    print_move_result(m);

    b = p.get_ball();
    assert(b.x == 3);
    assert(b.y == 4);
    assert(m.b.x == 3);
    assert(m.b.y == 4);
    assert(!m.goal);
    assert(!m.success);
}

void test_visualize() {
    pitch p = pitch();

    p.move_ball(directions::up);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::down_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::down_right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_left);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_right);
    std::cout << visualize_pitch(p) << std::endl;
    p.move_ball(directions::up_right);
    std::cout << visualize_pitch(p) << std::endl;
}

void test_right_edge() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.b.x == 8);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
    std::cout << visualize_pitch(p) << std::endl;
}

void test_right_edge_blocking_up_and_down() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);
    m = p.move_ball(directions::right);
    assert(m.success);

    m = p.move_ball(directions::up);
    assert(m.b.x == 8);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);

    m = p.move_ball(directions::down);
    assert(m.b.x == 8);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
}

void test_left_edge() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.b.x == 0);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
    std::cout << visualize_pitch(p) << std::endl;
}

void test_left_edge_blocking_up_and_down() {
    pitch p = pitch();
    ball b = p.get_ball();
    assert(b.x == 4);
    assert(b.y == 5);

    auto m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);
    m = p.move_ball(directions::left);
    assert(m.success);

    m = p.move_ball(directions::up);
    assert(m.b.x == 0);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);

    m = p.move_ball(directions::down);
    assert(m.b.x == 0);
    assert(m.b.y == 5);
    assert(!m.goal);
    assert(!m.success);
}

int main() {
    test_get_ball();

    // Basic moves
    test_move_ball_up();
    test_move_ball_up_right();
    test_move_ball_right();
    test_move_ball_down_right();
    test_move_ball_down();
    test_move_ball_down_left();
    test_move_ball_left();
    test_move_ball_up_left();

    // Sequences
    test_move_ball_up_and_down();
    test_move_ball_up_right_and_down_left();
    test_move_ball_right_and_left();
    test_move_ball_down_right_and_up_left();
    test_move_ball_down_and_up();
    test_move_ball_down_left_and_up_right();
    test_move_ball_left_and_right();
    test_move_ball_up_left_and_down_right();

    // visualize
    test_visualize();

    // Boundaries
    test_right_edge();
    test_right_edge_blocking_up_and_down();
    test_left_edge();
    test_left_edge_blocking_up_and_down();
}
