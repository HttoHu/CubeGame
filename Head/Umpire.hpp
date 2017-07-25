#ifndef UMPIRE_H
#define UMPIRE_H
#include "Coor.hpp"
#include "Player.hpp"
#include <array>
#include <vector>
#include <iostream>
std::string mark(const State & s);
enum State& player_state();
std::array<State,27>& Data();
Coor get_coor_by_array_pos(int pos);
int get_pos_by_coor(const Coor & c);
bool judge(const State & s);
void push(const Coor & c);
#endif
