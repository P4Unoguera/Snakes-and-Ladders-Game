#ifndef GAME_H
#define GAME_H

#include "board.h"

#define THROW_DICE 'T'
#define SHOW_SEQUENCE 'S'       // 'P' a Lab 2
#define QUIT 'Q'

void start_game(Board* board);
void solve(Board* board);

#endif //GAME_H
